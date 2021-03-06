Route109_EventObjects:: @ 8381AFC
	object_event 1, EVENT_OBJ_GFX_MR_BRINEYS_BOAT, 0, 21, 26, 1, 7, 0, 0, 0, 0, 0x0, FLAG_HIDE_MR_BRINEY_BOAT_ROUTE109
	object_event 2, EVENT_OBJ_GFX_OLD_MAN_1, 0, 21, 24, 3, 7, 0, 0, 0, 0, Route109_EventScript_14F680, FLAG_HIDE_MR_BRINEY_ROUTE109
	object_event 3, EVENT_OBJ_GFX_SWIMMER_M, 0, 12, 36, 3, 10, 0, 0, 1, 5, Route109_EventScript_14F7AD, 0
	object_event 4, EVENT_OBJ_GFX_SWIMMER_F, 0, 25, 42, 3, 15, 0, 0, 1, 5, Route109_EventScript_14F7C4, 0
	object_event 5, EVENT_OBJ_GFX_SAILOR, 0, 19, 19, 3, 10, 0, 0, 1, 4, Route109_EventScript_14F7DB, 0
	object_event 6, EVENT_OBJ_GFX_SAILOR, 0, 14, 11, 4, 8, 0, 0, 1, 1, Route109_EventScript_14F7F2, 0
	object_event 7, EVENT_OBJ_GFX_TUBER_M, 0, 21, 11, 3, 23, 0, 0, 1, 3, Route109_EventScript_14F809, 0
	object_event 8, EVENT_OBJ_GFX_TUBER_F, 0, 28, 8, 3, 10, 0, 0, 1, 4, Route109_EventScript_14F847, 0
	object_event 9, EVENT_OBJ_GFX_LITTLE_GIRL_2, 0, 11, 6, 3, 8, 0, 0, 0, 0, Route109_EventScript_14F705, 0
	object_event 10, EVENT_OBJ_GFX_ITEM_BALL, 0, 27, 48, 3, 1, 0, 0, 0, 0, Route109_EventScript_1B14A1, FLAG_ITEM_ROUTE109_1
	object_event 11, EVENT_OBJ_GFX_TUBER_F, 0, 29, 32, 3, 13, 0, 0, 1, 3, Route109_EventScript_14F89C, 0
	object_event 12, EVENT_OBJ_GFX_TUBER_F, 0, 28, 31, 3, 17, 0, 0, 1, 3, Route109_EventScript_14F885, 0
	object_event 13, EVENT_OBJ_GFX_FISHERMAN, 0, 15, 52, 3, 10, 0, 0, 1, 0, Route109_EventScript_14F8B3, 0
	object_event 14, EVENT_OBJ_GFX_TUBER_M, 0, 24, 17, 3, 10, 1, 1, 0, 0, Route109_EventScript_14F70E, 0
	object_event 15, EVENT_OBJ_GFX_TUBER_F, 0, 25, 17, 3, 9, 1, 1, 0, 0, Route109_EventScript_14F725, 0
	object_event 16, EVENT_OBJ_GFX_WOMAN_2, 0, 30, 32, 3, 8, 1, 1, 0, 0, Route109_EventScript_14F776, 0
	object_event 17, EVENT_OBJ_GFX_WOMAN_5, 0, 8, 41, 3, 8, 1, 1, 1, 0, Route109_EventScript_14F8E5, 0
	object_event 18, EVENT_OBJ_GFX_MAN_5, 0, 9, 41, 3, 8, 1, 1, 1, 0, Route109_EventScript_14F8CA, 0
	object_event 19, EVENT_OBJ_GFX_OLD_MAN_2, 0, 33, 6, 3, 1, 1, 1, 0, 0, Route109_EventScript_14F77F, 0
	object_event 20, EVENT_OBJ_GFX_ZIGZAGOON, 0, 32, 6, 3, 1, 1, 1, 0, 0, Route109_EventScript_14F788, 0

Route109_MapWarps:: @ 8381CDC
	warp_def 12, 5, 0, 0, MAP_ROUTE109_SEASHORE_HOUSE

Route109_MapBGEvents:: @ 8381CE4
	bg_event 15, 5, 0, 0, 0, Route109_EventScript_14F79B
	bg_event 29, 10, 3, 0, 0, Route109_EventScript_14F7A4
	bg_hidden_item_event 16, 23, 3, ITEM_REVIVE, FLAG_HIDDEN_ITEM_32
	bg_hidden_item_event 33, 5, 3, ITEM_HEART_SCALE, FLAG_HIDDEN_ITEM_34
	bg_hidden_item_event 9, 10, 3, ITEM_GREAT_BALL, FLAG_HIDDEN_ITEM_33
	bg_hidden_item_event 28, 20, 3, ITEM_ETHER, FLAG_HIDDEN_ITEM_40
	bg_hidden_item_event 13, 16, 3, ITEM_HEART_SCALE, FLAG_HIDDEN_ITEM_5A
	bg_hidden_item_event 8, 42, 3, ITEM_HEART_SCALE, FLAG_HIDDEN_ITEM_5B

Route109_MapEvents:: @ 8381D44
	map_events Route109_EventObjects, Route109_MapWarps, 0x0, Route109_MapBGEvents
