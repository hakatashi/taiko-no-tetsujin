#include "../include/GV.h"

void load_humen(){
	int i=0,cnt=0;
	int c;
	FILE *fp;
	fp=fopen("dat/humen/0.txt","r");
	if(fp==NULL)
		return;
	while((c=fgetc(fp))!=EOF){
		if(c==' '||c=='\n')continue;
		if(c!='0'){
			humen[i].flag=1;
			humen[i].cnt=cnt;
			humen[i].knd=c-'0';
			i++;
		}
		cnt++;
	}
	fclose(fp);
}

void ini(){

	memset(&ch,0,sizeof(ch_t));//�L������񏉊���
	memset(&oya,0,sizeof(oya_t));//�e���ۏ�񏉊���
	memset(&stage,0,sizeof(stage_t));//�X�e�[�W�Ɋւ��鏉����
	memset(bullet,0,sizeof(bullet_t)*BULLET_MAX);//�e��񏉊���
	memset(kekka,0,sizeof(kekka_t)*KEKKA_MAX);//���ʕ\����񏉊���
	memset(humen,0,sizeof(humen_t)*HUMEN_MAX);//���ʕ\����񏉊���

	ch.state=400;//�ŏ��̃X�R�A��400��
	oya.x=OYA_X, oya.y=OYA_Y;

	music.flag=0;
	music.term=363.5625/8;
	stage.spd=3;

	load_humen();
}
