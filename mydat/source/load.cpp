#include "../include/GV.h"

void load(){
	img_back[0]=LoadGraph("dat/img/back.png");
	img_taiko[0]=LoadGraph("dat/img/taiko.png");
	img_taiko[1]=LoadGraph("dat/img/taiko2.png");
	img_effect[0]=LoadGraph("dat/img/hit.png");

	img_kekka[0]=LoadGraph("dat/img/kekka0.png");
	img_kekka[1]=LoadGraph("dat/img/kekka1.png");
	img_kekka[2]=LoadGraph("dat/img/kekka2.png");

	img_board[0]=LoadGraph("dat/img/score.png");
	img_board[1]=LoadGraph("dat/img/oya.png");

	sound_se[0]=LoadSoundMem("dat/se/don.wav");
	sound_se[1]=LoadSoundMem("dat/se/ka.wav");

	music.handle=LoadSoundMem("dat/music/0.ogg");

	color[0] = GetColor(255,255,255);//”’
	color[1] = GetColor(  0,  0,  0);//•
	color[2] = GetColor(255,  0,  0);//Ô
	color[3] = GetColor(  0,255,  0);//—Î
	color[4] = GetColor(  0,  0,255);//Â
	color[5] = GetColor(255,255,  0);//‰©F
	color[6] = GetColor(  0,255,255);//Â—Î
	color[7] = GetColor(255,  0,255);//‡
}