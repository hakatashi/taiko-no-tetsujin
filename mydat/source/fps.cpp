#include "../include/GV.h"

//�e�o�r
#define FLAME 60

//fps�̃J�E���^�A60�t���[����1���ƂȂ鎞�����L�^����ϐ�
int fps_count,count0t;
//���ς��v�Z���邽��60���1�����Ԃ��L�^
int f[FLAME];
//����fps
double ave;

//fps����
void fps_wait(){
    int term,i,gnt;
    static int t=0;
    if(fps_count==0){//60�t���[����1��ڂȂ�
        if(t==0)//���S�ɍŏ��Ȃ�܂��Ȃ�
            term=0;
        else//�O��L�^�������Ԃ����Ɍv�Z
            term=count0t+1000-GetNowCount();
    }
    else    //�҂ׂ�����=���݂���ׂ�����-���݂̎���
        term = (int)(count0t+fps_count*(1000.0/FLAME))-GetNowCount();
    if(term>0)//�҂ׂ����Ԃ����҂�
        Sleep(term);
    gnt=GetNowCount();
    if(fps_count==0)//60�t���[����1�x������
        count0t=gnt;
    f[fps_count]=gnt-t;//�P���������Ԃ��L�^
    t=gnt;
    //���όv�Z
    if(fps_count==FLAME-1){
        ave=0;
        for(i=0;i<FLAME;i++)
            ave+=f[i];
        ave/=FLAME;
    }
    fps_count = (++fps_count)%FLAME ;
}

//fps�\��
void draw_fps(int x, int y){
    if(ave!=0){
        DrawFormatString(x, y,color[0],"[%.1f]",1000/ave);
		if(1000/ave<40)
			DrawFormatString(x, y,color[1],"�ُ�ł��B�ċN�����ĉ�����");
    }
    return;
}