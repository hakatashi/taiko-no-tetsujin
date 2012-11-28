#include "../include/GV.h"

extern void enter_kekka(int n, int knd, double x, double y);
extern int serch_kekka();

//スコア加算
void add_score(int knd){
	int score[3]={20,0,-50};
	ch.state+=score[knd];
	if(ch.state<0)
		ch.state=0;
	if(ch.state>1000)
		ch.state=1000;
}

//登録可能な弾を見つける
int serch_bullet(){
	int i;
	for(i=0;i<BULLET_MAX;i++){
		if(bullet[i].flag==0){
			return i;
		}
	}
	return -1;
}

//弾を実際に登録する
void enter_bullet(int n, int knd, double spd){
	bullet[n].flag=1;
	bullet[n].x=HIT_X+stage.spd*180;
	bullet[n].y=HIT_Y;
	bullet[n].knd=knd;
	bullet[n].spd=spd;
}

//弾の登録計算
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

//弾の計算
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
本当はここで、ヒットした弾IDと弾の座標を記憶しておき、
ヒットが近かった物を結果ヒットとする処理と、
もし同じ距離の２つヒットした弾があれば左側をﾋｯﾄとする処理を追加する必要がある
*/

//ヒットしたデータを格納するもの
#define HIT_DAT_MAX 20
typedef struct{
	int flag,id,knd;
	double x;
}hit_dat_t;

//ヒットしたデータを格納する登録可能番号を返す
int serch_hit_dat(hit_dat_t hit_dat[]){
	int i;
	for(i=0;i<HIT_DAT_MAX;i++){
		if(hit_dat[i].flag==0){
			return i;
		}
	}
	return -1;
}

//ヒットしたデータを登録する
void enter_hit_dat(int n, int id, int knd, double x, hit_dat_t hit_dat[]){
	hit_dat[n].flag=1;
	hit_dat[n].id=id;
	hit_dat[n].knd=knd;
	hit_dat[n].x=x;
}

//ヒットしたかどうかを判定する
void hit_bullet(){
	int i,j,k,knd;
	double x,pre_x,x0,x1;
	double line_x[3]={PERFECT_X,GOOD_X,BOO_X};
	hit_dat_t hit_dat[HIT_DAT_MAX];
	memset(hit_dat,0,sizeof(hit_dat_t)*HIT_DAT_MAX);

	for(i=0;i<BULLET_MAX;i++){//弾分ループ
		if(bullet[i].flag==1){//弾が存在していて
			knd=-1;
			pre_x=bullet[i].x+bullet[i].spd;
			x=bullet[i].x;
			for(j=0;j<3;j++){
				x0=HIT_X-line_x[j];
				x1=HIT_X+line_x[j];
				if(x<x0 && x0<pre_x || x<x1 && x1<pre_x || x0<x && x<x1 || x0<pre_x && pre_x<x1){//距離ヒット以内なら
					knd=j;
					break;
				}
			}
			//距離OKでその時たたいていたら
			if(knd!=-1 && (ch.don==1  && bullet[i].knd==0 || bullet[i].knd==1 && ch.ka==1)){
				if((k=serch_hit_dat(hit_dat))!=-1){
					enter_hit_dat(k,i,knd,bullet[i].x,hit_dat);
				}
			}
		}
	}
	int num=0;
	for(i=0;i<HIT_DAT_MAX;i++){//ヒットした分
		if(hit_dat[i].flag==1){//数える
			num++;
		}
	}
	if(num>0){//ヒットしたもんがあったら
		/*ここでヒットしたデータをkndごとにソートする*/
		/*今回はここは省略し、単にHIT_Xに近い物をヒットとする*/
		for (i = 0; i < num - 1; i++) {
			for (j = i + 1; j < num; j++) {
				if (fabs(hit_dat[i].x-HIT_X) > fabs(hit_dat[j].x-HIT_X)) {
					hit_dat_t t;
					t=hit_dat[i];	hit_dat[i]=hit_dat[j];	hit_dat[j]=t;
				}
			}
		}
		i=hit_dat[0].id; knd=hit_dat[0].knd; x=hit_dat[0].x;
		//登録処理
		if((k=serch_kekka())!=-1){
			enter_kekka(k,knd,x,HIT_Y-40);
			add_score(knd);
		}
		bullet[i].flag=0;
	}
	//効果音を鳴らす
	if(ch.don==1)
		se_flag[0]=1;
	if(ch.ka==1)
		se_flag[1]=1;
}

void auto_play(){
	int i;
	double x,x0,x1;
	for(i=0;i<BULLET_MAX;i++){//弾分ループ
		if(bullet[i].flag==1){//弾が存在していて
			x=bullet[i].x;
			x0=HIT_X-1;
			x1=HIT_X+1;
			if(x0<x && x<x1){//距離ヒット以内なら
				if(bullet[i].knd==0)
					ch.don=1;
				if(bullet[i].knd==1)
					ch.ka=1;
			}
		}
	}
}

void bullet_main(){

	/*ここの注釈を外すとオートプレイになる*/
	//	auto_play();

	input_bullet();
	calc_bullet();
	hit_bullet();
}
