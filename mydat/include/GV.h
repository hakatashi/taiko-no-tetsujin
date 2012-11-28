#include "../include/DxLib.h"
#include <math.h>
#include <stdlib.h>
#include "define.h"

#ifdef _GLOBAL_INSTANCE_
#define GLOBAL
#else
#define GLOBAL extern 
#endif

#include "function.h"

//画像用変数宣言部
GLOBAL int img_back[10];	//バック画像
GLOBAL int img_taiko[10];	//たいこ画像
GLOBAL int img_effect[10];	//エフェクト画像
GLOBAL int img_kekka[10];	//ヒット結果表示画像
GLOBAL int img_board[10];	//ボード画像

GLOBAL int count;	//カウンタ
GLOBAL int color[10];	//色情報

GLOBAL int sound_se[SE_MAX];//サウンドハンドル
GLOBAL int se_flag[SE_MAX];//効果音再生フラグ

//構造体変数宣言部
GLOBAL ch_t ch;
GLOBAL bullet_t bullet[BULLET_MAX];//弾
GLOBAL kekka_t kekka[KEKKA_MAX];//ヒット結果
GLOBAL oya_t oya;
GLOBAL music_t music;
GLOBAL stage_t stage;
GLOBAL humen_t humen[HUMEN_MAX];//譜面