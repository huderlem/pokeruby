#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "palette.h"
#include "rom_8077ABC.h"
#include "trig.h"

extern s16 gBattleAnimArgs[];
extern u8 gAnimBankAttacker;
extern u8 gAnimBankTarget;
extern u8 gAnimVisualTaskCount;

static void sub_80DA05C(struct Sprite *sprite);
static void sub_80DA0DC(u8 taskId);
static void sub_80DA1EC(struct Sprite *sprite);
static void sub_80DA348(struct Sprite *sprite);
static void sub_80DA410(struct Sprite *sprite);


void sub_80DA034(struct Sprite *sprite)
{
    sub_8078764(sprite, 0);
    sprite->pos1.y += 20;
    sprite->data[1] = 191;
    sprite->callback = sub_80DA05C;
    sprite->callback(sprite);
}

static void sub_80DA05C(struct Sprite *sprite)
{
    sprite->pos2.x = Sin(sprite->data[1], 32);
    sprite->pos2.y = Cos(sprite->data[1], 8);
    sprite->data[1] = (sprite->data[1] + 5) & 0xFF;

    if (++sprite->data[0] == 71)
    {
        DestroyAnimSprite(sprite);
    }
}

void sub_80DA09C(u8 taskId)
{
    gTasks[taskId].data[0] = gBattleAnimArgs[1];
    gTasks[taskId].data[1] = gBattleAnimArgs[0];
    gTasks[taskId].data[2] = IndexOfSpritePaletteTag(0x2719);
    gTasks[taskId].func = sub_80DA0DC;
}

// TODO: This has a small loop that is tricky to match.
__attribute__((naked))
static void sub_80DA0DC(u8 taskId)
{
    asm(".syntax unified\n\
    push {r4-r7,lr}\n\
    lsls r0, 24\n\
    lsrs r5, r0, 24\n\
    ldr r2, _080DA15C @ =gTasks\n\
    lsls r0, r5, 2\n\
    adds r0, r5\n\
    lsls r0, 3\n\
    adds r3, r0, r2\n\
    ldrh r0, [r3, 0x1C]\n\
    adds r1, r0, 0x1\n\
    strh r1, [r3, 0x1C]\n\
    lsls r0, 16\n\
    asrs r0, 16\n\
    movs r4, 0xA\n\
    ldrsh r1, [r3, r4]\n\
    adds r7, r2, 0\n\
    cmp r0, r1\n\
    bne _080DA13A\n\
    movs r0, 0\n\
    strh r0, [r3, 0x1C]\n\
    ldrb r0, [r3, 0xC]\n\
    ldr r2, _080DA160 @ =gPlttBufferFaded\n\
    lsls r0, 4\n\
    movs r3, 0x84\n\
    lsls r3, 1\n\
    adds r1, r0, r3\n\
    lsls r1, 1\n\
    adds r1, r2\n\
    ldrh r6, [r1]\n\
    movs r4, 0x7\n\
    mov r12, r0\n\
    ldr r0, _080DA164 @ =0x00000107\n\
    add r0, r12\n\
    lsls r0, 1\n\
    adds r3, r0, r2\n\
_080DA122:\n\
    ldrh r0, [r3]\n\
    strh r0, [r1]\n\
    subs r3, 0x2\n\
    subs r1, 0x2\n\
    subs r4, 0x1\n\
    cmp r4, 0\n\
    bgt _080DA122\n\
    ldr r0, _080DA168 @ =0x00000101\n\
    add r0, r12\n\
    lsls r0, 1\n\
    adds r0, r2\n\
    strh r6, [r0]\n\
_080DA13A:\n\
    lsls r0, r5, 2\n\
    adds r0, r5\n\
    lsls r0, 3\n\
    adds r0, r7\n\
    ldrh r1, [r0, 0x8]\n\
    subs r1, 0x1\n\
    strh r1, [r0, 0x8]\n\
    lsls r1, 16\n\
    cmp r1, 0\n\
    bne _080DA154\n\
    adds r0, r5, 0\n\
    bl DestroyAnimVisualTask\n\
_080DA154:\n\
    pop {r4-r7}\n\
    pop {r0}\n\
    bx r0\n\
    .align 2, 0\n\
_080DA15C: .4byte gTasks\n\
_080DA160: .4byte gPlttBufferFaded\n\
_080DA164: .4byte 0x00000107\n\
_080DA168: .4byte 0x00000101\n\
    .syntax divided\n");
}

void sub_80DA16C(struct Sprite *sprite)
{
    InitAnimSpritePos(sprite, 1);

    if (GetBattlerSide(gAnimBankAttacker) != B_SIDE_PLAYER)
    {
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];
    }

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[1] = sprite->pos1.x;
    sprite->data[2] = GetBattlerSpriteCoord(gAnimBankTarget, 2) + gBattleAnimArgs[2];
    sprite->data[3] = sprite->pos1.y;
    sprite->data[4] = GetBattlerSpriteCoord(gAnimBankTarget, 3) + gBattleAnimArgs[3];

    InitAnimSpriteTranslationDeltas(sprite);
    sprite->callback = sub_80785E4;
    StoreSpriteCallbackInData(sprite, sub_80DA1EC);
}

static void sub_80DA1EC(struct Sprite *sprite)
{
    if (TranslateAnimSpriteByDeltas(sprite))
    {
        DestroyAnimSprite(sprite);
    }
}

void sub_80DA208(struct Sprite *sprite)
{
    if (GetBattlerSide(gAnimBankAttacker) != B_SIDE_PLAYER)
    {
        gBattleAnimArgs[0] = -gBattleAnimArgs[0];
        gBattleAnimArgs[1] = -gBattleAnimArgs[1];
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];
        gBattleAnimArgs[3] = -gBattleAnimArgs[3];
    }

    if (IsContest())
    {
        gBattleAnimArgs[1] = -gBattleAnimArgs[1];
        gBattleAnimArgs[3] = -gBattleAnimArgs[3];
    }

    sprite->pos1.x = GetBattlerSpriteCoord(gAnimBankAttacker, 2);
    sprite->pos1.y = GetBattlerSpriteCoord(gAnimBankAttacker, 3);
    sprite->pos1.x += gBattleAnimArgs[0];
    sprite->pos1.y += gBattleAnimArgs[1];
    sprite->data[0] = gBattleAnimArgs[4];

    if (gBattleAnimArgs[6] == 0)
    {
        sprite->data[2] = GetBattlerSpriteCoord(gAnimBankTarget, 2);
        sprite->data[4] = GetBattlerSpriteCoord(gAnimBankTarget, 3);
    }
    else
    {
        SetAverageBattlerPositions(gAnimBankTarget, 1, &sprite->data[2], &sprite->data[4]);
    }

    sprite->data[2] += gBattleAnimArgs[2];
    sprite->data[4] += gBattleAnimArgs[3];
    sprite->callback = StartTranslateAnimSpriteByDeltas;
    StoreSpriteCallbackInData(sprite, DestroyAnimSprite);
    SeekSpriteAnim(sprite, gBattleAnimArgs[5]);
}

void sub_80DA300(struct Sprite *sprite)
{
    InitAnimSpritePos(sprite, 1);

    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->callback = sub_80DA348;
    gSprites[GetAnimBattlerSpriteId(0)].invisible = 1;
}

static void sub_80DA348(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
    }
    else
    {
        sprite->data[2] += sprite->data[1];
        sprite->pos2.y -= (sprite->data[2] >> 8);
    }

    if (sprite->pos1.y + sprite->pos2.y < -32)
    {
        DestroyAnimSprite(sprite);
    }
}

void sub_80DA38C(struct Sprite *sprite)
{
    if (GetBattlerSide(gAnimBankAttacker) != B_SIDE_PLAYER)
    {
        sprite->pos1.x = 272;
        sprite->pos1.y = -32;
        StartSpriteAffineAnim(sprite, 1);
    }
    else
    {
        sprite->pos1.x = -32;
        sprite->pos1.y = -32;
    }

    sprite->data[0] = gBattleAnimArgs[0];
    sprite->data[1] = sprite->pos1.x;
    sprite->data[2] = GetBattlerSpriteCoord(gAnimBankTarget, 2);
    sprite->data[3] = sprite->pos1.y;
    sprite->data[4] = GetBattlerSpriteCoord(gAnimBankTarget, 3);

    InitAnimSpriteTranslationDeltas(sprite);
    sprite->callback = sub_80DA410;
}

static void sub_80DA410(struct Sprite *sprite)
{
    sprite->data[0] = 1;
    TranslateAnimSpriteByDeltas(sprite);

    if (((u16)sprite->data[3] >> 8) > 200)
    {
        sprite->pos1.x += sprite->pos2.x;
        sprite->pos2.x = 0;
        sprite->data[3] &= 0xFF;
    }

    if ((u32)(sprite->pos1.x + sprite->pos2.x + 32) > 304
        || sprite->pos1.y + sprite->pos2.y > 160)
    {
        gSprites[GetAnimBattlerSpriteId(0)].invisible = 0;
        DestroyAnimSprite(sprite);
    }
}

void sub_80DA48C(struct Sprite *sprite)
{
    if (sprite->data[0]-- <= 0)
    {
        if (sprite->oam.affineMode & 1)
        {
            FreeOamMatrix(sprite->oam.matrixNum);
            sprite->oam.affineMode = 0;
        }
        
        DestroySprite(sprite);
        gAnimVisualTaskCount--;
    }
}
