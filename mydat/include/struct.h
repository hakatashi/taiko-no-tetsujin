//���������̃G�t�F�N�g�\���p
typedef struct{
	int flag;
	int cnt;
}ch_hit_t;

//�L�����N�^�[�Ɋւ���\����
typedef struct{
	int flag;		//�t���O
	int cnt;		//�J�E���^
	int score;		//�X�R�A
	int num;		//�c�@��
	int state;		//�X�e�[�^�X
	int don,ka;	//�h���A�J�������ꂽ��
	ch_hit_t hit;
}ch_t;

//�e
typedef struct{
	int flag;
	int knd;
	int cnt;
	double spd;
	double x,y;
}bullet_t;

//�q�b�g����
typedef struct{
	int flag;
	int knd;
	int cnt;
	double range;
	double x,y;
}kekka_t;

//����̃{�[�h�ɕ\�������e����
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