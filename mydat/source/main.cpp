#define _GLOBAL_INSTANCE_ 
#include "../include/GV.h"

//���[�v�ŕK���s���R�又��
int ProcessLoop(){
	if(ProcessMessage()!=0)return -1;//�v���Z�X�������G���[�Ȃ�-1��Ԃ�
	if(ClearDrawScreen()!=0)return -1;//��ʃN���A�������G���[�Ȃ�-1��Ԃ�
	GetHitKeyStateAll_2();//���݂̃L�[���͏������s��
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow){
    ChangeWindowMode(TRUE);//�E�B���h�E���[�h
    if(DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK )!=0) return -1;//�������Ɨ���ʉ�

	load();//�f�[�^���[�h
	ini();//������

	while(ProcessLoop()==0){//���C�����[�v
		clear_se_flag();//���ʉ��t���O��������
		calc_ch();//���͂ɑ΂���v�Z
		bullet_main();//�e�̌v�Z���C��
		kekka_main();//�e�q�b�g���ʕ\�����C��
		board_main();//�{�[�h�v�Z���C��
		graph_main();//�`�惁�C��
		draw_fps(0,460);//FPS�\��
		play_se();//���ʉ�
		calc_music();
		fps_wait();//fps����
		stage.cnt++; count++;
		if(CheckStateKey(KEY_INPUT_ESCAPE)==1)break;//�G�X�P�[�v�����͂��ꂽ��u���C�N
        ScreenFlip();//����ʔ��f
    }

    DxLib_End();//�c�w���C�u�����I������
    return 0;
}