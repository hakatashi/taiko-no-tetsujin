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

//�摜�p�ϐ��錾��
GLOBAL int img_back[10];	//�o�b�N�摜
GLOBAL int img_taiko[10];	//�������摜
GLOBAL int img_effect[10];	//�G�t�F�N�g�摜
GLOBAL int img_kekka[10];	//�q�b�g���ʕ\���摜
GLOBAL int img_board[10];	//�{�[�h�摜

GLOBAL int count;	//�J�E���^
GLOBAL int color[10];	//�F���

GLOBAL int sound_se[SE_MAX];//�T�E���h�n���h��
GLOBAL int se_flag[SE_MAX];//���ʉ��Đ��t���O

//�\���̕ϐ��錾��
GLOBAL ch_t ch;
GLOBAL bullet_t bullet[BULLET_MAX];//�e
GLOBAL kekka_t kekka[KEKKA_MAX];//�q�b�g����
GLOBAL oya_t oya;
GLOBAL music_t music;
GLOBAL stage_t stage;
GLOBAL humen_t humen[HUMEN_MAX];//����