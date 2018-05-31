#include "global.h"
#include "event_obj_lock.h"
#include "field_player_avatar.h"
#include "field_effect.h"
#include "fieldmap.h"
#include "item_use.h"
#include "metatile_behavior.h"
#include "pokeradar.h"
#include "script.h"
#include "constants/field_effects.h"

static void WaitForShakingPokeRadarGrass(u8 taskId);
static void FinishPokeRadar(u8 taskId);

bool8 CanUsePokeRadar(u8 taskId)
{
    s16 x, y;
    u16 tileBehavior;

    PlayerGetDestCoords(&x, &y);
    tileBehavior = MapGridGetMetatileBehaviorAt(x, y);

    // Must be standing in tall grass.
    if (!MetatileBehavior_IsTallGrass(tileBehavior))
    {
        DisplayDadsAdviceCannotUseItemMessage(taskId, gTasks[taskId].data[2]);
        return FALSE;
    }

    // PokeRadar must be fully charged.
    // TODO:

    return TRUE;
}

#define tWaitDuration data[0]

void ChoosePokeRadarShakeCoords(s16 baseX, s16 baseY)
{
    gPokeRadarGrassCoords[0][0] = baseX - 1;
    gPokeRadarGrassCoords[0][1] = baseY - 1;
    gPokeRadarGrassCoords[1][0] = baseX + 1;
    gPokeRadarGrassCoords[1][1] = baseY - 1;
    gPokeRadarGrassCoords[2][0] = baseX - 1;
    gPokeRadarGrassCoords[2][1] = baseY + 1;
    gPokeRadarGrassCoords[3][0] = baseX + 1;
    gPokeRadarGrassCoords[3][1] = baseY + 1;
}

void StartPokeRadarGrassShake(void)
{
    int i;
    struct EventObject *playerObj;

    playerObj = &gEventObjects[gPlayerAvatar.eventObjectId];
    ChoosePokeRadarShakeCoords(playerObj->currentCoords.x, playerObj->currentCoords.y);

    for (i = 0; i < NUM_POKE_RADAR_GRASS_PATCHES; i++)
    {
        gFieldEffectArguments[0] = gPokeRadarGrassCoords[i][0];
        gFieldEffectArguments[1] = gPokeRadarGrassCoords[i][1];
        gFieldEffectArguments[2] = playerObj->previousElevation;
        gFieldEffectArguments[3] = 2;
        gFieldEffectArguments[4] = playerObj->localId << 8 | playerObj->mapNum;
        gFieldEffectArguments[5] = playerObj->mapGroup;
        gFieldEffectArguments[6] = (u8)gSaveBlock1.location.mapNum << 8 | (u8)gSaveBlock1.location.mapGroup;
        gFieldEffectArguments[7] = 0;
        FieldEffectStart(FLDEFF_TALL_GRASS);
    }
}

void ItemUseOnFieldCB_PokeRadar(u8 taskId)
{
    ScriptContext2_Enable();
    gPlayerAvatar.preventStep = TRUE;
    StartPokeRadarGrassShake();
    gTasks[taskId].tWaitDuration = 60;
    gTasks[taskId].func = WaitForShakingPokeRadarGrass;
}

void WaitForShakingPokeRadarGrass(u8 taskId)
{
    if (--gTasks[taskId].tWaitDuration < 0)
        FinishPokeRadar(taskId);
}

void FinishPokeRadar(u8 taskId)
{
    sub_8064E2C();
    gPlayerAvatar.preventStep = FALSE;
    ScriptContext2_Disable();
    DestroyTask(taskId);
}
