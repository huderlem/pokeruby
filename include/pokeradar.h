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
    u8 patchType;
    u8 streak;
    u16 species;
    u8 level;
    u8 active;
    u8 increasedRates;
    struct PokeRadarGrassPatch grassPatches[NUM_POKE_RADAR_GRASS_PATCHES];
};

extern struct PokeRadarChain gPokeRadarChain;

bool8 CanUsePokeRadar(u8 taskId);
void ItemUseOnFieldCB_PokeRadar(u8 taskId);

#endif
