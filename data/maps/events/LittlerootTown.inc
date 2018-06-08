LittlerootTown_EventObjects::
	object_event 1, EVENT_OBJ_GFX_LITTLE_BOY_3, 0, 16, 0, 10, 0, 3, 2, 33, 0, 0, 0, 0, 0, LittlerootTown_EventScript_14D6DF, 0, 0, 0

LittlerootTown_MapWarps::
	warp_def 14, 8, 0, 1, MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F
	warp_def 5, 8, 0, 1, MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F
	warp_def 7, 16, 0, 0, MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB

LittlerootTown_MapCoordEvents::
	coord_event 10, 1, 3, 0, VAR_LITTLEROOT_STATE, 0, 0, LittlerootTown_EventScript_14D739
	coord_event 11, 1, 3, 0, VAR_LITTLEROOT_STATE, 0, 0, LittlerootTown_EventScript_14D797
	coord_event 11, 1, 3, 0, VAR_LITTLEROOT_STATE, 1, 0, LittlerootTown_EventScript_14D7C7
	coord_event 8, 9, 3, 0, VAR_LITTLEROOT_STATE, 3, 0, LittlerootTown_EventScript_14D89E
	coord_event 9, 9, 3, 0, VAR_LITTLEROOT_STATE, 3, 0, LittlerootTown_EventScript_14D8AA
	coord_event 10, 9, 3, 0, VAR_LITTLEROOT_STATE, 3, 0, LittlerootTown_EventScript_14D886
	coord_event 11, 9, 3, 0, VAR_LITTLEROOT_STATE, 3, 0, LittlerootTown_EventScript_14D892
	coord_event 10, 2, 3, 0, VAR_LITTLEROOT_STATE, 3, 0, LittlerootTown_EventScript_14D860
	coord_event 11, 2, 3, 0, VAR_LITTLEROOT_STATE, 3, 0, LittlerootTown_EventScript_14D873

LittlerootTown_MapBGEvents::
	bg_event 15, 13, 0, 0, 0, LittlerootTown_EventScript_14D7F6
	bg_event 6, 17, 0, 0, 0, LittlerootTown_EventScript_14D7FF
	bg_event 7, 8, 3, 0, 0, LittlerootTown_EventScript_14D808
	bg_event 12, 8, 3, 0, 0, LittlerootTown_EventScript_14D834

LittlerootTown_MapEvents::
	map_events LittlerootTown_EventObjects, LittlerootTown_MapWarps, LittlerootTown_MapCoordEvents, LittlerootTown_MapBGEvents
