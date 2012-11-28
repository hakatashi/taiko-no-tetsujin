#include "../include/GV.h"
int serch_kekka(){
	int i;
	for(i=0;i<KEKKA_MAX;i++){
		if(kekka[i].flag==0){
			return i;
		}
	}
	return -1;
}
void enter_kekka(int n, int knd, double x, double y){
	kekka[n].flag=1;
	kekka[n].knd=knd;
	kekka[n].range=0;
	kekka[n].cnt=0;
	kekka[n].x=x;
	kekka[n].y=y;
}

void calc_kekka(){
	int i,j;
	for(i=0;i<KEKKA_MAX;i++){
		if(kekka[i].flag==1){
			if(kekka[i].cnt<6)
				kekka[i].range+=0.25;
			else if(kekka[i].cnt<8)
				kekka[i].range-=0.25;
			kekka[i].cnt++;
			if(kekka[i].cnt>60)
				kekka[i].flag=0;
		}
	}
	for(i=0;i<KEKKA_MAX-2;i++){
		if(kekka[i].flag==0){
			for(j=i;j<KEKKA_MAX-1;j++){
				kekka[j]=kekka[j+1];
			}
		}
	}
}

void kekka_main(){
	calc_kekka();
}
