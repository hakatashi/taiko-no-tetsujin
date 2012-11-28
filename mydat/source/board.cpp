#include "../include/GV.h"

void calc_oya(){
	if(oya.flag==0){
		if(oya.cnt>120 && GetRand(100)==0){
			oya.flag=1;
			oya.cnt=0;
			oya.knd=GetRand(1);
		}
	}
	if(oya.flag==1){
		switch(oya.knd){
			case 0:
				oya.angle=(PI/12)*sin(PI2/50*oya.cnt);
				if(oya.cnt==50){
					oya.angle=0;
					oya.cnt=0;
					oya.flag=0;
				}
				break;
			case 1:
				oya.y=OYA_Y-sin(PI2/140*oya.cnt)*25;
				if(oya.cnt==70){
					oya.y=OYA_Y;
					oya.cnt=0;
					oya.flag=0;
				}
				break;
		}
	}
	oya.cnt++;
}

void board_main(){
	calc_oya();
}