#include "../include/GV.h"

//‘½d’è‹`
int DrawRotaGraphF( double xd, double yd, double ExRate, double Angle, int GrHandle, int TransFlag, int TurnFlag = FALSE  ) {
	return DrawRotaGraphF((float)xd,(float)yd,ExRate,Angle,GrHandle,TransFlag,TurnFlag);
}

//”wŒi•`‰æ
void graph_back(){
	DrawGraph(0,0,img_back[0],FALSE);
	if(ch.hit.flag==1){
		DrawRotaGraphF(HIT_X,HIT_Y,0.8+0.2*sin(PI2/HIT_EFFECT_CNT*ch.hit.cnt),0.0,img_effect[0],TRUE);
	}
	else
		DrawRotaGraphF(HIT_X,HIT_Y,0.8,0.0,img_effect[0],TRUE);
}


//ƒqƒbƒg‚µ‚½‚Æ‚«‚ÌŒ‹‰Ê•\¦•`‰æ
void graph_kekka_eff(){
	int i,flag=0;
	for(i=0;i<KEKKA_MAX;i++){
		if(kekka[i].flag==1){
			if((kekka[i].knd==0 || kekka[i].knd==1) && kekka[i].cnt<20){
				SetDrawBlendMode( DX_BLENDMODE_ADD,(int)(128-128.0/20*kekka[i].cnt)) ;
				DrawRotaGraphF(HIT_X,HIT_Y,0.6+1.0/20*kekka[i].cnt,0,img_taiko[kekka[i].knd],TRUE);
				DrawRotaGraphF(HIT_X,HIT_Y,0.9+2.0/20*kekka[i].cnt,0,img_taiko[kekka[i].knd],TRUE);
				DrawRotaGraphF(HIT_X,HIT_Y,1.2+3.0/20*kekka[i].cnt,0,img_taiko[kekka[i].knd],TRUE);
				SetDrawBlendMode( DX_BLENDMODE_NOBLEND,0) ;
			}
		}
	}
}

//’e•`‰æ
void graph_bullet(){
	int i;
	for(i=0;i<BULLET_MAX;i++){
		if(bullet[i].flag==1){
			DrawRotaGraphF(bullet[i].x, bullet[i].y, 1.0, 0.0, img_taiko[bullet[i].knd], TRUE);
		}
	}
}

//ƒqƒbƒg‚µ‚½‚Æ‚«‚ÌŒ‹‰Ê•\¦•`‰æ
void graph_kekka(){
	int i,flag=0;
	for(i=0;i<KEKKA_MAX;i++){
		if(kekka[i].flag==1){
			DrawRotaGraphF(kekka[i].x, kekka[i].y, kekka[i].range, 0.0, img_kekka[kekka[i].knd], TRUE);
		}
	}
}

//ƒ{[ƒhŠÖŒW‚Ì•`‰æ
void graph_board(){
	int i,n;
	//ƒXƒRƒA‚ğ•`‰æ
	n=(int)(ch.state/(1000/43.0));
	for(i=0;i<n;i++){
		if(i<23)
			SetDrawBright(255,(int)(255/23.0*i),0);
		else
			SetDrawBright(255-(int)(255/20.0*(i-23)),255,0);
		DrawRotaGraph(271+7*i, 40, 1.0f, 0.0f, img_board[0], TRUE);
	}
	SetDrawBright(255,255,255);
	DrawRotaGraphF(oya.x, oya.y, 1.0, oya.angle, img_board[1], TRUE);
}

//•`‰æƒƒCƒ“
void graph_main(){
	graph_back();
	graph_kekka_eff();
	graph_bullet();
	graph_kekka();
	graph_board();
}