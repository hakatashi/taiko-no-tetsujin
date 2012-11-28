#include "../include/GV.h"

//�t���O�̏�����
void clear_se_flag(){
	memset(se_flag,0,sizeof(int)*SE_MAX);
}

//�����Ă���t���O�̌��ʉ���炷
void play_se(){
	int i;
	for(i=0;i<SE_MAX;i++){
		if(se_flag[i]==1){
			if(CheckSoundMem(sound_se[i])!=0){
				StopSoundMem(sound_se[i]);
			}
			PlaySoundMem(sound_se[i],DX_PLAYTYPE_BACK);
		}
	}
}

void calc_music(){
	if(stage.cnt==180){
		PlaySoundMem(music.handle,DX_PLAYTYPE_BACK);
		music.flag=1;
	}
	//���y�Ɠ�������鏈��
	if(stage.cnt>180){
		int t=stage.cnt-180;
		if(t%60==59){
			int gettm=GetSoundCurrentTime(music.handle);
			int nowflame=(int)(t*16.6666);
			if(abs(gettm-nowflame)>100){
				StopSoundMem(music.handle);
				SetSoundCurrentTime( (int)(t*16.666666) , music.handle);
				PlaySoundMem(music.handle, DX_PLAYTYPE_BACK,FALSE);
			}
		}
	}
}