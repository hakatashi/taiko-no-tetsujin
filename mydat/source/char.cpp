#include "../include/GV.h"

void calc_ch(){
	
	//���͂ɑ΂��ăX�e�[�^�X��ω�������
	if(CheckStateKey(KEY_INPUT_LEFT)==1 || CheckStateKey(KEY_INPUT_RIGHT)==1)
		ch.ka=1;
	else
		ch.ka=0;

	if(CheckStateKey(KEY_INPUT_DOWN)==1)
		ch.don=1;
	else
		ch.don=0;

	//���͂��s��ꂽ���ɂ�����G�t�F�N�g��o�^
	if(ch.ka==1 || ch.don==1){
		ch.hit.flag=1;
	}
	if(ch.hit.flag==1){
		ch.hit.cnt++;
		if(ch.hit.cnt>HIT_EFFECT_CNT){
			ch.hit.flag=0;
			ch.hit.cnt=0;
		}
	}
}