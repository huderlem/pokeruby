#include "global.h"
#include "battle.h"
#include "data2.h"
#include "decompress.h"
#include "main.h"
#include "overworld.h"
#include "palette.h"
#include "sprite.h"
#include "text_window.h"
#include "trainer.h"

struct BattleBackground
{
    const void *tileset;
    const void *tilemap;
    const void *entryTileset;
    const void *entryTilemap;
    const void *palette;
};

extern u16 gBattleTypeFlags;
extern u16 gTrainerBattleOpponent;
extern u8 gBattleTerrain;
extern u16 gPlttBufferFaded[];
extern u16 gPlttBufferUnfaded[];
extern struct SpriteTemplate gSpriteTemplate_81F96D0[];
extern struct Window gUnknown_03004210;
extern const struct BattleBackground gBattleTerrainTable[];
extern const u8 gBattleTerrainTiles_Building[];
extern const u8 gBattleTerrainTilemap_Building[];
extern const u8 gBattleTerrainPalette_BattleTower[];
extern const u8 gBattleTerrainTiles_Cave[];
extern const u8 gBattleTerrainTilemap_Cave[];
extern const u8 gBattleTerrainPalette_Groudon[];
extern const u8 gBattleTerrainTiles_Water[];
extern const u8 gBattleTerrainTilemap_Water[];
extern const u8 gBattleTerrainPalette_Kyogre[];
extern const u8 gBattleTerrainPalette_BuildingLeader[];
extern const u8 gBattleTerrainTiles_Stadium[];
extern const u8 gBattleTerrainTilemap_Stadium[];
extern const u8 gBattleTerrainPalette_StadiumSteven[];
extern const u8 gBattleTerrainPalette_BuildingGym[];
extern const u8 gBattleTerrainPalette_StadiumMagma[];
extern const u8 gBattleTerrainPalette_StadiumAqua[];
extern const u8 gBattleTerrainPalette_StadiumSidney[];
extern const u8 gBattleTerrainPalette_StadiumPhoebe[];
extern const u8 gBattleTerrainPalette_StadiumGlacia[];
extern const u8 gBattleTerrainPalette_StadiumDrake[];

static void sub_800D6C4(void);


__attribute__((naked))
void unref_sub_800D42C(void)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    mov r7, r10\n\
    mov r6, r9\n\
    mov r5, r8\n\
    push {r5-r7}\n\
    sub sp, 0x24\n\
    mov r9, r0\n\
    str r1, [sp]\n\
    str r2, [sp, 0x4]\n\
    adds r5, r3, 0\n\
    movs r0, 0x1\n\
    mov r1, r9\n\
    ands r0, r1\n\
    cmp r0, 0\n\
    bne _0800D44C\n\
    b _0800D5E4\n\
_0800D44C:\n\
    asrs r0, r1, 1\n\
    adds r0, 0x4\n\
    lsls r0, 24\n\
    lsrs r0, 24\n\
    str r0, [sp, 0x8]\n\
    movs r0, 0\n\
    ldr r2, [sp]\n\
    cmp r0, r2\n\
    blt _0800D460\n\
    b _0800D674\n\
_0800D460:\n\
    movs r4, 0x8\n\
    subs r1, r4, r1\n\
    str r1, [sp, 0x10]\n\
_0800D466:\n\
    movs r7, 0\n\
    adds r0, 0x1\n\
    str r0, [sp, 0x14]\n\
    ldr r0, [sp, 0x10]\n\
    cmp r7, r0\n\
    bge _0800D4E2\n\
    ldr r1, [sp, 0x8]\n\
    lsls r1, 8\n\
    str r1, [sp, 0x18]\n\
    movs r2, 0\n\
    mov r10, r2\n\
    mov r0, r9\n\
    movs r4, 0x8\n\
    subs r0, r4, r0\n\
    str r0, [sp, 0xC]\n\
_0800D484:\n\
    movs r3, 0\n\
    asrs r0, r7, 1\n\
    adds r1, r7, 0\n\
    movs r2, 0x1\n\
    ands r1, r2\n\
    str r1, [sp, 0x20]\n\
    lsls r0, 8\n\
    mov r8, r0\n\
    mov r12, r5\n\
_0800D496:\n\
    lsls r1, r3, 5\n\
    ldr r4, [sp, 0x18]\n\
    adds r0, r5, r4\n\
    adds r0, r1\n\
    mov r1, r8\n\
    adds r2, r0, r1\n\
    mov r1, r12\n\
    add r1, r8\n\
    movs r6, 0xF\n\
_0800D4A8:\n\
    ldr r4, [sp, 0x20]\n\
    cmp r4, 0\n\
    bne _0800D4B8\n\
    strb r4, [r1]\n\
    add r4, sp, 0x20\n\
    ldrb r4, [r4]\n\
    strb r4, [r2, 0x10]\n\
    b _0800D4C6\n\
_0800D4B8:\n\
    mov r0, r10\n\
    strb r0, [r1, 0x10]\n\
    movs r4, 0x80\n\
    lsls r4, 1\n\
    adds r4, r2, r4\n\
    str r4, [sp, 0x1C]\n\
    strb r0, [r4]\n\
_0800D4C6:\n\
    adds r2, 0x1\n\
    adds r1, 0x1\n\
    subs r6, 0x1\n\
    cmp r6, 0\n\
    bge _0800D4A8\n\
    movs r0, 0x20\n\
    add r12, r0\n\
    adds r3, 0x1\n\
    cmp r3, 0x7\n\
    ble _0800D496\n\
    adds r7, 0x1\n\
    ldr r1, [sp, 0xC]\n\
    cmp r7, r1\n\
    blt _0800D484\n\
_0800D4E2:\n\
    movs r7, 0\n\
    movs r2, 0\n\
_0800D4E6:\n\
    movs r6, 0\n\
    adds r4, r7, 0x1\n\
    mov r8, r4\n\
    lsls r4, r7, 5\n\
_0800D4EE:\n\
    adds r0, r6, 0x1\n\
    mov r10, r0\n\
    lsls r1, r6, 8\n\
    adds r0, r1, 0\n\
    adds r0, 0xC0\n\
    adds r0, r5, r0\n\
    adds r0, r4\n\
    adds r1, r5, r1\n\
    adds r1, r4\n\
    movs r3, 0x1F\n\
_0800D502:\n\
    strb r2, [r1]\n\
    strb r2, [r0]\n\
    adds r0, 0x1\n\
    adds r1, 0x1\n\
    subs r3, 0x1\n\
    cmp r3, 0\n\
    bge _0800D502\n\
    mov r6, r10\n\
    cmp r6, 0x7\n\
    ble _0800D4EE\n\
    mov r7, r8\n\
    cmp r7, 0x1\n\
    ble _0800D4E6\n\
    mov r1, r9\n\
    cmp r1, 0x5\n\
    bne _0800D528\n\
    movs r2, 0x90\n\
    lsls r2, 1\n\
    adds r5, r2\n\
_0800D528:\n\
    movs r7, 0\n\
    cmp r7, r9\n\
    bge _0800D5BE\n\
_0800D52E:\n\
    movs r3, 0\n\
    adds r7, 0x1\n\
    mov r8, r7\n\
    cmp r3, r9\n\
    bge _0800D59E\n\
_0800D538:\n\
    adds r3, 0x1\n\
    mov r10, r3\n\
    ldr r4, [sp, 0x4]\n\
    adds r4, 0x20\n\
    adds r7, r5, 0\n\
    adds r7, 0x20\n\
    movs r0, 0x12\n\
    adds r0, r5\n\
    mov r12, r0\n\
    ldr r2, [sp, 0x4]\n\
    adds r3, r5, 0\n\
    movs r6, 0x3\n\
_0800D550:\n\
    ldrb r0, [r2]\n\
    mov r1, r12\n\
    strb r0, [r1]\n\
    ldrb r0, [r2, 0x1]\n\
    strb r0, [r1, 0x1]\n\
    ldrb r0, [r2, 0x2]\n\
    strb r0, [r1, 0x1E]\n\
    ldrb r0, [r2, 0x3]\n\
    strb r0, [r1, 0x1F]\n\
    movs r0, 0x81\n\
    lsls r0, 1\n\
    adds r1, r3, r0\n\
    ldrb r0, [r2, 0x10]\n\
    strb r0, [r1]\n\
    ldr r0, _0800D5A8 @ =0x00000103\n\
    adds r1, r3, r0\n\
    ldrb r0, [r2, 0x11]\n\
    strb r0, [r1]\n\
    movs r0, 0x90\n\
    lsls r0, 1\n\
    adds r1, r3, r0\n\
    ldrb r0, [r2, 0x12]\n\
    strb r0, [r1]\n\
    ldr r0, _0800D5AC @ =0x00000121\n\
    adds r1, r3, r0\n\
    ldrb r0, [r2, 0x13]\n\
    strb r0, [r1]\n\
    movs r1, 0x4\n\
    add r12, r1\n\
    adds r2, 0x4\n\
    adds r3, 0x4\n\
    subs r6, 0x1\n\
    cmp r6, 0\n\
    bge _0800D550\n\
    str r4, [sp, 0x4]\n\
    adds r5, r7, 0\n\
    mov r3, r10\n\
    cmp r3, r9\n\
    blt _0800D538\n\
_0800D59E:\n\
    mov r2, r9\n\
    cmp r2, 0x7\n\
    bne _0800D5B0\n\
    adds r5, 0x20\n\
    b _0800D5B8\n\
    .align 2, 0\n\
_0800D5A8: .4byte 0x00000103\n\
_0800D5AC: .4byte 0x00000121\n\
_0800D5B0:\n\
    mov r4, r9\n\
    cmp r4, 0x5\n\
    bne _0800D5B8\n\
    adds r5, 0x60\n\
_0800D5B8:\n\
    mov r7, r8\n\
    cmp r7, r9\n\
    blt _0800D52E\n\
_0800D5BE:\n\
    mov r0, r9\n\
    cmp r0, 0x7\n\
    bne _0800D5CC\n\
    movs r1, 0x80\n\
    lsls r1, 1\n\
    adds r5, r1\n\
    b _0800D5D8\n\
_0800D5CC:\n\
    mov r2, r9\n\
    cmp r2, 0x5\n\
    bne _0800D5D8\n\
    movs r4, 0xF0\n\
    lsls r4, 1\n\
    adds r5, r4\n\
_0800D5D8:\n\
    ldr r0, [sp, 0x14]\n\
    ldr r1, [sp]\n\
    cmp r0, r1\n\
    bge _0800D5E2\n\
    b _0800D466\n\
_0800D5E2:\n\
    b _0800D674\n\
_0800D5E4:\n\
    movs r6, 0\n\
    ldr r2, [sp]\n\
    cmp r6, r2\n\
    bge _0800D674\n\
_0800D5EC:\n\
    adds r6, 0x1\n\
    mov r10, r6\n\
    mov r4, r9\n\
    cmp r4, 0x6\n\
    bne _0800D604\n\
    movs r0, 0\n\
    movs r3, 0xFF\n\
_0800D5FA:\n\
    strb r0, [r5]\n\
    adds r5, 0x1\n\
    subs r3, 0x1\n\
    cmp r3, 0\n\
    bge _0800D5FA\n\
_0800D604:\n\
    movs r7, 0\n\
    cmp r7, r9\n\
    bge _0800D658\n\
_0800D60A:\n\
    adds r7, 0x1\n\
    mov r8, r7\n\
    mov r1, r9\n\
    lsls r0, r1, 5\n\
    cmp r1, 0x6\n\
    bne _0800D624\n\
    movs r1, 0\n\
    movs r3, 0x1F\n\
_0800D61A:\n\
    strb r1, [r5]\n\
    adds r5, 0x1\n\
    subs r3, 0x1\n\
    cmp r3, 0\n\
    bge _0800D61A\n\
_0800D624:\n\
    adds r1, r0, 0\n\
    cmp r1, 0\n\
    ble _0800D63E\n\
    adds r3, r1, 0\n\
_0800D62C:\n\
    ldr r2, [sp, 0x4]\n\
    ldrb r0, [r2]\n\
    strb r0, [r5]\n\
    adds r2, 0x1\n\
    str r2, [sp, 0x4]\n\
    adds r5, 0x1\n\
    subs r3, 0x1\n\
    cmp r3, 0\n\
    bne _0800D62C\n\
_0800D63E:\n\
    mov r4, r9\n\
    cmp r4, 0x6\n\
    bne _0800D652\n\
    movs r0, 0\n\
    movs r3, 0x1F\n\
_0800D648:\n\
    strb r0, [r5]\n\
    adds r5, 0x1\n\
    subs r3, 0x1\n\
    cmp r3, 0\n\
    bge _0800D648\n\
_0800D652:\n\
    mov r7, r8\n\
    cmp r7, r9\n\
    blt _0800D60A\n\
_0800D658:\n\
    mov r0, r9\n\
    cmp r0, 0x6\n\
    bne _0800D66C\n\
    movs r0, 0\n\
    movs r3, 0xFF\n\
_0800D662:\n\
    strb r0, [r5]\n\
    adds r5, 0x1\n\
    subs r3, 0x1\n\
    cmp r3, 0\n\
    bge _0800D662\n\
_0800D66C:\n\
    mov r6, r10\n\
    ldr r1, [sp]\n\
    cmp r6, r1\n\
    blt _0800D5EC\n\
_0800D674:\n\
    add sp, 0x24\n\
    pop {r3-r5}\n\
    mov r8, r3\n\
    mov r9, r4\n\
    mov r10, r5\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
.syntax divided\n");
}

void unref_sub_800D684(void)
{
    u8 spriteId;

    ResetSpriteData();
    spriteId = CreateSprite(gSpriteTemplate_81F96D0, 0, 0, 0);
    gSprites[spriteId].invisible = 1;

    SetMainCallback2(sub_800D6C4);
}

static void sub_800D6C4(void)
{
    AnimateSprites();
    BuildOamBuffer();
}

void sub_800D6D4(void)
{
    u16 imeBackup = REG_IME;
    REG_IME = 0;
    REG_IE |= INTR_FLAG_VBLANK;
    REG_IME = imeBackup;
    REG_DISPSTAT = DISPSTAT_VBLANK_INTR;
    REG_BG0CNT = BGCNT_AFF512x512 | BGCNT_SCREENBASE(24);
    REG_BG1CNT = BGCNT_AFF512x512 | BGCNT_SCREENBASE(28) | BGCNT_CHARBASE(1);
    REG_BG2CNT = BGCNT_AFF256x256 | BGCNT_SCREENBASE(30) | BGCNT_CHARBASE(1) | BGCNT_PRIORITY(1);
    REG_BG3CNT = BGCNT_AFF256x256 | BGCNT_SCREENBASE(26) | BGCNT_CHARBASE(2) | BGCNT_PRIORITY(3);
    REG_BLDCNT = 0;
    REG_BLDALPHA = 0;
    REG_BLDY = 0;
    REG_DISPCNT = DISPCNT_OBJWIN_ON | DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_1D_MAP;
}

void sub_800D74C(void)
{
    SetTextWindowBaseTileNum(18);
    LoadTextWindowGraphics_OverridePalSlot(&gUnknown_03004210, 1);
    SetTextWindowBaseTileNum(34);
    LoadTextWindowGraphics_OverridePalSlot(&gUnknown_03004210, 1);

    gPlttBufferUnfaded[92] = 0x7FE0;
    gPlttBufferUnfaded[93] = 0x2529;
    gPlttBufferUnfaded[94] = 0x7FFF;
    gPlttBufferUnfaded[95] = 0x675A;

    CpuSet(&gPlttBufferUnfaded[92], &gPlttBufferFaded[92], 4);
    sub_8032A38();
}

void DrawMainBattleBackground(void)
{
    if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_BATTLE_TOWER | BATTLE_TYPE_EREADER_TRAINER))
    {
        LZDecompressVram(gBattleTerrainTiles_Building, (void*)(VRAM + 0x8000));
        LZDecompressVram(gBattleTerrainTilemap_Building, (void*)(VRAM + 0xD000));
        LoadCompressedPalette(gBattleTerrainPalette_BattleTower, 0x20, 0x60);
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_KYOGRE_GROUDON)
    {
        if (gGameVersion == VERSION_RUBY)
        {
            LZDecompressVram(gBattleTerrainTiles_Cave, (void*)(VRAM + 0x8000));
            LZDecompressVram(gBattleTerrainTilemap_Cave, (void*)(VRAM + 0xD000));
            LoadCompressedPalette(gBattleTerrainPalette_Groudon, 0x20, 0x60);
        }
        else
        {
            LZDecompressVram(gBattleTerrainTiles_Water, (void*)(VRAM + 0x8000));
            LZDecompressVram(gBattleTerrainTilemap_Water, (void*)(VRAM + 0xD000));
            LoadCompressedPalette(gBattleTerrainPalette_Kyogre, 0x20, 0x60);
        }
    }
    else
    {
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            u8 trainerClass = gTrainers[gTrainerBattleOpponent].trainerClass;
            if (trainerClass == TRAINER_CLASS_LEADER)
            {
                LZDecompressVram(gBattleTerrainTiles_Building, (void*)(VRAM + 0x8000));
                LZDecompressVram(gBattleTerrainTilemap_Building, (void*)(VRAM + 0xD000));
                LoadCompressedPalette(gBattleTerrainPalette_BuildingLeader, 0x20, 0x60);
                return;
            }
            else if (trainerClass == TRAINER_CLASS_CHAMPION)
            {
                LZDecompressVram(gBattleTerrainTiles_Stadium, (void*)(VRAM + 0x8000));
                LZDecompressVram(gBattleTerrainTilemap_Stadium, (void*)(VRAM + 0xD000));
                LoadCompressedPalette(gBattleTerrainPalette_StadiumSteven, 0x20, 0x60);
                return;
            }
        }

        switch (GetCurrentMapBattleScene())
        {
        case MAP_BATTLE_SCENE_NORMAL:
            LZDecompressVram(gBattleTerrainTable[gBattleTerrain].tileset, (void*)(VRAM + 0x8000));
            LZDecompressVram(gBattleTerrainTable[gBattleTerrain].tilemap, (void*)(VRAM + 0xD000));
            LoadCompressedPalette(gBattleTerrainTable[gBattleTerrain].palette, 0x20, 0x60);
            break;
        case MAP_BATTLE_SCENE_GYM:
            LZDecompressVram(gBattleTerrainTiles_Building, (void*)(VRAM + 0x8000));
            LZDecompressVram(gBattleTerrainTilemap_Building, (void*)(VRAM + 0xD000));
            LoadCompressedPalette(gBattleTerrainPalette_BuildingGym, 0x20, 0x60);
            break;
        case MAP_BATTLE_SCENE_MAGMA:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void*)(VRAM + 0x8000));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void*)(VRAM + 0xD000));
            LoadCompressedPalette(gBattleTerrainPalette_StadiumMagma, 0x20, 0x60);
            break;
        case MAP_BATTLE_SCENE_AQUA:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void*)(VRAM + 0x8000));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void*)(VRAM + 0xD000));
            LoadCompressedPalette(gBattleTerrainPalette_StadiumAqua, 0x20, 0x60);
            break;
        case MAP_BATTLE_SCENE_SIDNEY:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void*)(VRAM + 0x8000));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void*)(VRAM + 0xD000));
            LoadCompressedPalette(gBattleTerrainPalette_StadiumSidney, 0x20, 0x60);
            break;
        case MAP_BATTLE_SCENE_PHOEBE:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void*)(VRAM + 0x8000));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void*)(VRAM + 0xD000));
            LoadCompressedPalette(gBattleTerrainPalette_StadiumPhoebe, 0x20, 0x60);
            break;
        case MAP_BATTLE_SCENE_GLACIA:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void*)(VRAM + 0x8000));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void*)(VRAM + 0xD000));
            LoadCompressedPalette(gBattleTerrainPalette_StadiumGlacia, 0x20, 0x60);
            break;
        case MAP_BATTLE_SCENE_DRAKE:
            LZDecompressVram(gBattleTerrainTiles_Stadium, (void*)(VRAM + 0x8000));
            LZDecompressVram(gBattleTerrainTilemap_Stadium, (void*)(VRAM + 0xD000));
            LoadCompressedPalette(gBattleTerrainPalette_StadiumDrake, 0x20, 0x60);
            break;
        case MAP_BATTLE_SCENE_BATTLE_TOWER:
            LZDecompressVram(gBattleTerrainTiles_Building, (void*)(VRAM + 0x8000));
            LZDecompressVram(gBattleTerrainTilemap_Building, (void*)(VRAM + 0xD000));
            LoadCompressedPalette(gBattleTerrainPalette_BattleTower, 0x20, 0x60);
            break;
        }
    }
}
