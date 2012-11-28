#define _GLOBAL_INSTANCE_ 
#include "../include/GV.h"

//ループで必ず行う３大処理
int ProcessLoop(){
	if(ProcessMessage()!=0)return -1;//プロセス処理がエラーなら-1を返す
	if(ClearDrawScreen()!=0)return -1;//画面クリア処理がエラーなら-1を返す
	GetHitKeyStateAll_2();//現在のキー入力処理を行う
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow){
    ChangeWindowMode(TRUE);//ウィンドウモード
    if(DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK )!=0) return -1;//初期化と裏画面化

	load();//データロード
	ini();//初期化

	while(ProcessLoop()==0){//メインループ
		clear_se_flag();//効果音フラグを初期化
		calc_ch();//入力に対する計算
		bullet_main();//弾の計算メイン
		kekka_main();//弾ヒット結果表示メイン
		board_main();//ボード計算メイン
		graph_main();//描画メイン
		draw_fps(0,460);//FPS表示
		play_se();//効果音
		calc_music();
		fps_wait();//fps制御
		stage.cnt++; count++;
		if(CheckStateKey(KEY_INPUT_ESCAPE)==1)break;//エスケープが入力されたらブレイク
        ScreenFlip();//裏画面反映
    }

    DxLib_End();//ＤＸライブラリ終了処理
    return 0;
}