#ifndef GUARD_POKERADAR_H
#define GUARD_POKERADAR_H

#define NUM_POKE_RADAR_GRASS_PATCHES 4

extern s16 gPokeRadarGrassCoords[4][2];

bool8 CanUsePokeRadar(u8 taskId);
void ItemUseOnFieldCB_PokeRadar(u8 taskId);

#endif
