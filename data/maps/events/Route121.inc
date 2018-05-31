Route121_MapWarps::
	warp_def 37, 5, 0, 2, MAP_ROUTE121_SAFARI_ZONE_ENTRANCE

Route121_MapCoordEvents::
	coord_event 25, 5, 3, 0, VAR_ROUTE121_STATE, 0, 0, Route121_EventScript_151B25
	coord_event 25, 6, 3, 0, VAR_ROUTE121_STATE, 0, 0, Route121_EventScript_151B25
	coord_event 25, 7, 3, 0, VAR_ROUTE121_STATE, 0, 0, Route121_EventScript_151B25
	coord_event 25, 8, 3, 0, VAR_ROUTE121_STATE, 0, 0, Route121_EventScript_151B25

Route121_MapBGEvents::
	bg_event 32, 14, 0, 0, 0, Route121_EventScript_151B13
	bg_event 39, 6, 0, 0, 0, Route121_EventScript_151B1C
	bg_hidden_item_event 23, 10, 3, ITEM_HP_UP, FLAG_HIDDEN_ITEM_27
	bg_hidden_item_event 58, 3, 3, ITEM_NUGGET, FLAG_HIDDEN_ITEM_28
	bg_hidden_item_event 72, 5, 3, ITEM_FULL_HEAL, FLAG_HIDDEN_ITEM_49
	bg_secret_base_event 40, 11, 0, SECRET_BASE_RED_CAVE2_2
	bg_secret_base_event 18, 13, 0, SECRET_BASE_RED_CAVE3_2
	bg_secret_base_event 43, 7, 0, SECRET_BASE_TREE1_2
	bg_secret_base_event 42, 7, 0, SECRET_BASE_TREE2_2

Route121_MapEvents::
	map_events 0, Route121_MapWarps, Route121_MapCoordEvents, Route121_MapBGEvents
