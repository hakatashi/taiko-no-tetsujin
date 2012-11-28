//押した時のエフェクト表示用
typedef struct{
	int flag;
	int cnt;
}ch_hit_t;

//キャラクターに関する構造体
typedef struct{
	int flag;		//フラグ
	int cnt;		//カウンタ
	int score;		//スコア
	int num;		//残機数
	int state;		//ステータス
	int don,ka;	//ドン、カが押されたか
	ch_hit_t hit;
}ch_t;

//弾
typedef struct{
	int flag;
	int knd;
	int cnt;
	double spd;
	double x,y;
}bullet_t;

//ヒット結果
typedef struct{
	int flag;
	int knd;
	int cnt;
	double range;
	double x,y;
}kekka_t;

//左上のボードに表示される親太鼓
typedef struct{
	int flag;
	int cnt;
	int knd;
	double x,y;
	double angle;
}oya_t;

typedef struct{
	int flag;
	int handle;
	double term;
}music_t;

typedef struct{
	int flag;
	int cnt;
	int spd;
	int humen_cnt;
}stage_t;

typedef struct{
	int flag;
	int cnt;
	int knd;
}humen_t;