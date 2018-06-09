#include "global.h"
#include "battle.h"
#include "event_obj_lock.h"
#include "field_control_avatar.h"
#include "field_player_avatar.h"
#include "field_effect.h"
#include "fieldmap.h"
#include "global.fieldmap.h"
#include "item_menu.h"
#include "item_use.h"
#include "metatile_behavior.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "pokeradar.h"
#include "random.h"
#include "script.h"
#include "sound.h"
#include "strings.h"
#include "text.h"
#include "constants/field_effects.h"
#include "constants/songs.h"
#include "constants/species.h"

static void WaitForShakingPokeRadarGrass(u8 taskId);
static void FinishPokeRadar(u8 taskId);

static bool8 IsValidPokeRadarMetatile(s16 x, s16 y)
{
    u16 tileBehavior;
    s16 gridX, gridY;

    // Must not lie in the map's border.
    gridX = x - 7;
    gridY = y - 7;
    if (gridX < 0 || gridY < 0 || gridX >= gMapHeader.mapData->width || gridY >= gMapHeader.mapData->height)
    {
        return FALSE;
    }

    // Must be tall grass.
    tileBehavior = MapGridGetMetatileBehaviorAt(x, y);
    if (!MetatileBehavior_IsTallGrass(tileBehavior))
        return FALSE;

    return TRUE;
}

bool8 CanUsePokeRadar(u8 taskId)
{
    s16 x, y;

    // Check if the player is standing in a valid pokeradar metatile.
    PlayerGetDestCoords(&x, &y);
    if (!IsValidPokeRadarMetatile(x, y))
    {
        DisplayDadsAdviceCannotUseItemMessage(taskId, gTasks[taskId].data[2]);
        return FALSE;
    }

    return TRUE;
}

static const u8 sNumPatchesInRing[] = { 32, 24, 16, 8, };

static const s8 sFourthRingCoords[][2] = {
    {-4, -4},{-4, -3},{-4, -2},{-4, -1},{-4,  0},{-4,  1},{-4,  2},{-4,  3},{-4,  4},
    {-3, -4},                                                               {-3,  4},
    {-2, -4},                                                               {-2,  4},
    {-1, -4},                                                               {-1,  4},
    { 0, -4},                                                               { 0,  4},
    { 1, -4},                                                               { 1,  4},
    { 2, -4},                                                               { 2,  4},
    { 3, -4},                                                               { 3,  4},
    { 4, -4},{ 4, -3},{ 4, -2},{ 4, -1},{ 4,  0},{ 4,  1},{ 4,  2},{ 4,  3},{ 4,  4},
};

static const s8 sThirdRingCoords[][2] = {
    {-3, -3},{-3, -2},{-3, -1},{-3,  0},{-3,  1},{-3,  2},{-3,  3},
    {-2, -3},                                             {-2,  3},
    {-1, -3},                                             {-1,  3},
    { 0, -3},                                             { 0,  3},
    { 1, -3},                                             { 1,  3},
    { 2, -3},                                             { 2,  3},
    { 3, -3},{ 3, -2},{ 3, -1},{ 3,  0},{ 3,  1},{ 3,  2},{ 3,  3},
};

static const s8 sSecondRingCoords[][2] = {
    {-2, -2},{-2, -1},{-2,  0},{-2,  1},{-2,  2},
    {-1, -2},                           {-1,  2},
    { 0, -2},                           { 0,  2},
    { 1, -2},                           { 1,  2},
    { 2, -2},{ 2, -1},{ 2,  0},{ 2,  1},{ 2,  2},
};

static const s8 sFirstRingCoords[][2] = {
    {-1, -1},{-1,  0},{-1,  1},
    { 0, -1},         { 0,  1},
    { 1, -1},{ 1,  0},{ 1,  1},
};

typedef const s8 (*RingCoords)[2];
static const RingCoords sPokeRadarRingCoords[] = {
    sFourthRingCoords,
    sThirdRingCoords,
    sSecondRingCoords,
    sFirstRingCoords,
};

bool8 SetPokeRadarPatchCoords(s16 baseX, s16 baseY)
{
    int i;
    bool8 valid = FALSE;

    for (i = 0; i < NUM_POKE_RADAR_GRASS_PATCHES; i++)
    {
        u16 index = (Random() % sNumPatchesInRing[i]);
        gPokeRadarChain.grassPatches[i].x = baseX + sPokeRadarRingCoords[i][index][0];
        gPokeRadarChain.grassPatches[i].y = baseY + sPokeRadarRingCoords[i][index][1];
        gPokeRadarChain.grassPatches[i].active = IsValidPokeRadarMetatile(gPokeRadarChain.grassPatches[i].x, gPokeRadarChain.grassPatches[i].y);

        if (gPokeRadarChain.grassPatches[i].active)
            valid = TRUE;
    }

    return valid;
}

static const u8 sNormalPatchRates[] = { 88, 68, 48, 28, };
static const u8 sHighPatchRates[]   = { 98, 78, 58, 38, };

static bool8 CheckPatchContinuesChain(int patchIndex, u8 increasedRates)
{
    const u8 *rates = increasedRates ? sHighPatchRates : sNormalPatchRates;
    return (Random() % 100) < rates[patchIndex];
}

static u8 CheckShinyPatch(u8 streak)
{
    int shinyChance;

    if (streak == 0)
        return 0;

    if (streak > 40)
        streak = 40;

    shinyChance = (65535 / (8200 - streak * 200)) + 1;
    return Random() < shinyChance;
}

static void PrepGrassPatchChainData(void)
{
    int i;
    for (i = 0; i < NUM_POKE_RADAR_GRASS_PATCHES; i++)
    {
        if (gPokeRadarChain.grassPatches[i].active)
        {
            gPokeRadarChain.grassPatches[i].continueChain = CheckPatchContinuesChain(i, gPokeRadarChain.increasedRates);
            gPokeRadarChain.increasedRates = 0;

            if (gPokeRadarChain.grassPatches[i].continueChain)
            {
                gPokeRadarChain.grassPatches[i].patchType = gPokeRadarChain.streak > 0 ? gPokeRadarChain.patchType : (Random() & 1);
                gPokeRadarChain.grassPatches[i].isShiny = CheckShinyPatch(gPokeRadarChain.streak);
            }
            else
            {
                gPokeRadarChain.grassPatches[i].patchType = Random() & 1;
                gPokeRadarChain.grassPatches[i].isShiny = 0;
            }
        }
    }
}

void TrySetPokeRadarPatchCoords(void)
{
    // Set coordinates for next radar iteration before the battle starts.
    if (gPokeRadarChain.active)
    {
        s16 x, y;
        PlayerGetDestCoords(&x, &y);
        if (!SetPokeRadarPatchCoords(x, y))
        {
            BreakPokeRadarChain();
        }
    }
}

static void StartPokeRadarGrassShake(void)
{
    int i;
    struct EventObject *playerObj = &gEventObjects[gPlayerAvatar.eventObjectId];

    PlayBGM(BGM_POKERADAR);

    // Disable the 4-step wild pokemon immunity.
    DisableWildPokemonImmunity();
    PrepGrassPatchChainData();

    for (i = 0; i < NUM_POKE_RADAR_GRASS_PATCHES; i++)
    {
        if (IsValidPokeRadarMetatile(gPokeRadarChain.grassPatches[i].x, gPokeRadarChain.grassPatches[i].y))
        {
            gFieldEffectArguments[0] = gPokeRadarChain.grassPatches[i].x;
            gFieldEffectArguments[1] = gPokeRadarChain.grassPatches[i].y;
            gFieldEffectArguments[2] = playerObj->previousElevation;
            gFieldEffectArguments[3] = 2;
            gFieldEffectArguments[4] = playerObj->localId << 8 | playerObj->mapNum;
            gFieldEffectArguments[5] = playerObj->mapGroup;
            gFieldEffectArguments[6] = (u8)gSaveBlock1.location.mapNum << 8 | (u8)gSaveBlock1.location.mapGroup;
            gFieldEffectArguments[7] = 0;

            if (gPokeRadarChain.grassPatches[i].isShiny)
                FieldEffectStart(FLDEFF_POKERADAR_GRASS_SHINY);
            else if (gPokeRadarChain.grassPatches[i].patchType == 0)
                FieldEffectStart(FLDEFF_POKERADAR_GRASS_0);
            else
                FieldEffectStart(FLDEFF_POKERADAR_GRASS_1);
        }
    }
}

#define tWaitDuration data[0]

void Task_StartPokeRadarGrassShake(u8 taskId)
{
    ScriptContext2_Enable();
    gPlayerAvatar.preventStep = TRUE;
    gPokeRadarChain.stepsUntilCharged = POKE_RADAR_STEPS_TO_CHARGE;
    gPokeRadarChain.originX = gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.x;
    gPokeRadarChain.originY = gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.y;
    gPokeRadarChain.mapGroup = gSaveBlock1.location.mapGroup;
    gPokeRadarChain.mapNum = gSaveBlock1.location.mapNum;

    StartPokeRadarGrassShake();
    gTasks[taskId].tWaitDuration = 60;
    gTasks[taskId].func = WaitForShakingPokeRadarGrass;
}

void ItemUseOnFieldCB_PokeRadar(u8 taskId)
{
    struct EventObject *playerObj;

    // Ensure pokeradar is fully-charged.
    if (gPokeRadarChain.stepsUntilCharged > 0)
    {
        if (gPokeRadarChain.stepsUntilCharged == 1)
        {
            DisplayItemMessageOnField(taskId, gPokeRadar_StepUntilCharged, CleanUpOverworldMessage, 0);
        }
        else
        {
            ConvertIntToDecimalStringN(gStringVar1, gPokeRadarChain.stepsUntilCharged, 0, 2);
            StringExpandPlaceholders(gStringVar4, gPokeRadar_StepsUntilCharged);
            DisplayItemMessageOnField(taskId, gStringVar4, CleanUpOverworldMessage, 0);
        }        
        return;
    }

    playerObj = &gEventObjects[gPlayerAvatar.eventObjectId];
    if (SetPokeRadarPatchCoords(playerObj->currentCoords.x, playerObj->currentCoords.y))
    {
        gPokeRadarChain.active = 1;
        Task_StartPokeRadarGrassShake(taskId);
    }
    else
    {
        // End pokeradar chain because no grass shook.
        BreakPokeRadarChain();
        gPokeRadarChain.stepsUntilCharged = POKE_RADAR_STEPS_TO_CHARGE;
        DisplayItemMessageOnField(taskId, gPokeRadar_GrassRemainedSilent, CleanUpOverworldMessage, 0);
    }
}

static void WaitForShakingPokeRadarGrass(u8 taskId)
{
    if (--gTasks[taskId].tWaitDuration < 0)
        FinishPokeRadar(taskId);
}

static void FinishPokeRadar(u8 taskId)
{
    sub_8064E2C();
    gPlayerAvatar.preventStep = FALSE;
    ScriptContext2_Disable();
    DestroyTask(taskId);
}

void BreakPokeRadarChain(void)
{
    int i;

    Overworld_PlaySpecialMapMusic();

    gPokeRadarChain.streak = 0;
    gPokeRadarChain.species = 0;
    gPokeRadarChain.level = 0;
    gPokeRadarChain.patchType = 0;
    gPokeRadarChain.active = 0;
    gPokeRadarChain.originX = 0;
    gPokeRadarChain.originY = 0;
    gPokeRadarChain.mapGroup = 0;
    gPokeRadarChain.mapNum = 0;

    for (i = 0; i < NUM_POKE_RADAR_GRASS_PATCHES; i++)
    {
        gPokeRadarChain.grassPatches[i].x = 0;
        gPokeRadarChain.grassPatches[i].y = 0;
        gPokeRadarChain.grassPatches[i].patchType = 0;
        gPokeRadarChain.grassPatches[i].active = 0;
        gPokeRadarChain.grassPatches[i].continueChain = 0;
        gPokeRadarChain.grassPatches[i].isShiny = 0;
    }
}

void IncrementPokeRadarChain(void)
{
    if (++gPokeRadarChain.streak > 999)
        gPokeRadarChain.streak = 999;
}

void SetPokeRadarPokemon(u16 species, u8 level)
{
    gPokeRadarChain.species = species;
    gPokeRadarChain.level = level;
}

void UpdatePokeRadarAfterWildBattle(u8 battleOutcome)
{
    if (gPokeRadarChain.active)
    {
        switch (battleOutcome)
        {
        case BATTLE_LOST:
        case BATTLE_DREW:
        case BATTLE_RAN:
        case BATTLE_PLAYER_TELEPORTED:
        case BATTLE_POKE_FLED:
        case BATTLE_OUT_OF_BALLS:
        case BATTLE_OPPONENT_TELEPORTED:
            BreakPokeRadarChain();
            break;
        case BATTLE_CAUGHT:
            gPokeRadarChain.increasedRates = 1;
            break;
        }
    }
}

void InitNewPokeRadarStreak(u16 species, u8 level, u8 patchType)
{
    SetPokeRadarPokemon(species, level);
    gPokeRadarChain.patchType = patchType;
    gPokeRadarChain.streak = 1;
}

void ChargePokeRadar(void)
{
    s16 xDiff, yDiff;

    if (gPokeRadarChain.stepsUntilCharged > 0)
        gPokeRadarChain.stepsUntilCharged--;

    if (gPokeRadarChain.active)
    {
        // Break the pokeradar chain if the player enters a different map.
        if (gSaveBlock1.location.mapGroup != gPokeRadarChain.mapGroup
            || gSaveBlock1.location.mapNum != gPokeRadarChain.mapNum)
        {
            BreakPokeRadarChain();
            return;
        }

        // Break the pokeradar chain if the player walks too far away from the last
        // radar location.
        xDiff = abs(gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.x - gPokeRadarChain.originX);
        yDiff = abs(gEventObjects[gPlayerAvatar.eventObjectId].currentCoords.y - gPokeRadarChain.originY);
        if (xDiff > 13 || yDiff > 13)
        {
            BreakPokeRadarChain();
            return;
        }
    }
}
