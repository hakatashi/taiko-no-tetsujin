//graph.cpp
	//�`�惁�C��
	GLOBAL void graph_main();

//key.cpp
	//���݂̃L�[���͏������s��
	GLOBAL int GetHitKeyStateAll_2();
	//�󂯎�����L�[�ԍ��̌��݂̓��͏�Ԃ�Ԃ�
	GLOBAL int CheckStateKey(unsigned char Handle);
	GLOBAL void InputStateKey(unsigned char Handle, int k);

//laod.cpp
	//�f�[�^�̃��[�h
	GLOBAL void load();

//ch.cpp
	GLOBAL void calc_ch();

//ini.cpp
	GLOBAL void ini();

//bullet.cpp
	GLOBAL void bullet_main();

//fps.cpp
	GLOBAL void fps_wait();
	GLOBAL void draw_fps(int x, int y);

//kekka.cpp
	GLOBAL void kekka_main();

//music.cpp
	GLOBAL void play_se();
	GLOBAL void clear_se_flag();
	GLOBAL void calc_music();

//board.cpp
	GLOBAL void board_main();