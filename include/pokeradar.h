#ifndef GUARD_POKERADAR_H
#define GUARD_POKERADAR_H

#define NUM_POKE_RADAR_GRASS_PATCHES 4

struct PokeRadarGrassPatch {
    s16 x;
    s16 y;
    u8 patchType;
    u8 active;
    u8 continueChain;
    u8 isShiny;
};

struct PokeRadarChain {
    u16 streak;
    u16 species;
    u8 level;
    u8 patchType;
    u8 active;
    u8 increasedRates;
    struct PokeRadarGrassPatch grassPatches[NUM_POKE_RADAR_GRASS_PATCHES];
};

extern struct PokeRadarChain gPokeRadarChain;

bool8 SetPokeRadarShakeCoords(s16 baseX, s16 baseY);
void BreakPokeRadarChain(void);
void IncrementPokeRadarChain(void);
void SetPokeRadarPokemon(u16 species, u8 level);
bool8 CanUsePokeRadar(u8 taskId);
void TrySetPokeRadarPatchCoords(void);
void Task_StartPokeRadarGrassShake(u8 taskId);
void ItemUseOnFieldCB_PokeRadar(u8 taskId);
void UpdatePokeRadarAfterWildBattle(u8 battleOutcome);
void InitNewPokeRadarStreak(u16 species, u8 level, u8 patchType);

#endif
