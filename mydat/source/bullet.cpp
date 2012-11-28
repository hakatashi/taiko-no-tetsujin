#include "../include/GV.h"

extern void enter_kekka(int n, int knd, double x, double y);
extern int serch_kekka();

//�X�R�A���Z
void add_score(int knd){
	int score[3]={20,0,-50};
	ch.state+=score[knd];
	if(ch.state<0)
		ch.state=0;
	if(ch.state>1000)
		ch.state=1000;
}

//�o�^�\�Ȓe��������
int serch_bullet(){
	int i;
	for(i=0;i<BULLET_MAX;i++){
		if(bullet[i].flag==0){
			return i;
		}
	}
	return -1;
}

//�e�����ۂɓo�^����
void enter_bullet(int n, int knd, double spd){
	bullet[n].flag=1;
	bullet[n].x=HIT_X+stage.spd*180;
	bullet[n].y=HIT_Y;
	bullet[n].knd=knd;
	bullet[n].spd=spd;
}

//�e�̓o�^�v�Z
void input_bullet(){
	int k;
	double sc0=stage.cnt*16.6666666666, sc1=(stage.cnt+1)*16.6666666666;
	double cnt=music.term*humen[stage.humen_cnt].cnt;
	if(sc0<=cnt && cnt<sc1){
		if((k=serch_bullet())!=-1){
			enter_bullet(k,humen[stage.humen_cnt].knd-1,stage.spd);
		}
		stage.humen_cnt++;
	}
}

//�e�̌v�Z
void calc_bullet(){
	int i,j,k;
	for(i=0;i<BULLET_MAX;i++){
		if(bullet[i].flag==1){
			bullet[i].x-=bullet[i].spd;
			bullet[i].cnt++;
			if(bullet[i].x<HIT_X-BOO_X){
				if((k=serch_kekka())!=-1){
					enter_kekka(k,2,bullet[i].x,HIT_Y-40);
					add_score(2);
				}
				bullet[i].flag=0;
			}
		}
	}
	for (i = 0; i < BULLET_MAX; i++) {
		for (j = i + 1; j < BULLET_MAX; j++) {
			if (bullet[i].flag==1 && bullet[j].flag==1 && bullet[i].x < bullet[j].x) {
				bullet_t t;
				t=bullet[i];	bullet[i]=bullet[j];	bullet[j]=t;
			}
		}
	}
}

/*
�{���͂����ŁA�q�b�g�����eID�ƒe�̍��W���L�����Ă����A
�q�b�g���߂������������ʃq�b�g�Ƃ��鏈���ƁA
�������������̂Q�q�b�g�����e������΍�����˯ĂƂ��鏈����ǉ�����K�v������
*/

//�q�b�g�����f�[�^���i�[�������
#define HIT_DAT_MAX 20
typedef struct{
	int flag,id,knd;
	double x;
}hit_dat_t;

//�q�b�g�����f�[�^���i�[����o�^�\�ԍ���Ԃ�
int serch_hit_dat(hit_dat_t hit_dat[]){
	int i;
	for(i=0;i<HIT_DAT_MAX;i++){
		if(hit_dat[i].flag==0){
			return i;
		}
	}
	return -1;
}

//�q�b�g�����f�[�^��o�^����
void enter_hit_dat(int n, int id, int knd, double x, hit_dat_t hit_dat[]){
	hit_dat[n].flag=1;
	hit_dat[n].id=id;
	hit_dat[n].knd=knd;
	hit_dat[n].x=x;
}

//�q�b�g�������ǂ����𔻒肷��
void hit_bullet(){
	int i,j,k,knd;
	double x,pre_x,x0,x1;
	double line_x[3]={PERFECT_X,GOOD_X,BOO_X};
	hit_dat_t hit_dat[HIT_DAT_MAX];
	memset(hit_dat,0,sizeof(hit_dat_t)*HIT_DAT_MAX);

	for(i=0;i<BULLET_MAX;i++){//�e�����[�v
		if(bullet[i].flag==1){//�e�����݂��Ă���
			knd=-1;
			pre_x=bullet[i].x+bullet[i].spd;
			x=bullet[i].x;
			for(j=0;j<3;j++){
				x0=HIT_X-line_x[j];
				x1=HIT_X+line_x[j];
				if(x<x0 && x0<pre_x || x<x1 && x1<pre_x || x0<x && x<x1 || x0<pre_x && pre_x<x1){//�����q�b�g�ȓ��Ȃ�
					knd=j;
					break;
				}
			}
			//����OK�ł��̎��������Ă�����
			if(knd!=-1 && (ch.don==1  && bullet[i].knd==0 || bullet[i].knd==1 && ch.ka==1)){
				if((k=serch_hit_dat(hit_dat))!=-1){
					enter_hit_dat(k,i,knd,bullet[i].x,hit_dat);
				}
			}
		}
	}
	int num=0;
	for(i=0;i<HIT_DAT_MAX;i++){//�q�b�g������
		if(hit_dat[i].flag==1){//������
			num++;
		}
	}
	if(num>0){//�q�b�g�������񂪂�������
		/*�����Ńq�b�g�����f�[�^��knd���ƂɃ\�[�g����*/
		/*����͂����͏ȗ����A�P��HIT_X�ɋ߂������q�b�g�Ƃ���*/
		for (i = 0; i < num - 1; i++) {
			for (j = i + 1; j < num; j++) {
				if (fabs(hit_dat[i].x-HIT_X) > fabs(hit_dat[j].x-HIT_X)) {
					hit_dat_t t;
					t=hit_dat[i];	hit_dat[i]=hit_dat[j];	hit_dat[j]=t;
				}
			}
		}
		i=hit_dat[0].id; knd=hit_dat[0].knd; x=hit_dat[0].x;
		//�o�^����
		if((k=serch_kekka())!=-1){
			enter_kekka(k,knd,x,HIT_Y-40);
			add_score(knd);
		}
		bullet[i].flag=0;
	}
	//���ʉ���炷
	if(ch.don==1)
		se_flag[0]=1;
	if(ch.ka==1)
		se_flag[1]=1;
}

void auto_play(){
	int i;
	double x,x0,x1;
	for(i=0;i<BULLET_MAX;i++){//�e�����[�v
		if(bullet[i].flag==1){//�e�����݂��Ă���
			x=bullet[i].x;
			x0=HIT_X-1;
			x1=HIT_X+1;
			if(x0<x && x<x1){//�����q�b�g�ȓ��Ȃ�
				if(bullet[i].knd==0)
					ch.don=1;
				if(bullet[i].knd==1)
					ch.ka=1;
			}
		}
	}
}

void bullet_main(){

	/*�����̒��߂��O���ƃI�[�g�v���C�ɂȂ�*/
	//	auto_play();

	input_bullet();
	calc_bullet();
	hit_bullet();
}
