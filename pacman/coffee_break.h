#pragma once
#include "AbstractScene.h"
#include "Player.h"

class Coffee : public AbstractScene {
private:
	int Pacimg[3];
	int Pacanim;
	int PacSize;
	int PacSpeed;
	int PNowdraw;
	int PacX;
	int PacY;
	float Nowdirect;
	int PDirection;
	enum PDirection
	{
		PLAYER_NORMAL_UP = 1,
		PLAYER_NORMAL_RIGHT,
		PLAYER_NORMAL_DOWN,
		PLAYER_NORMAL_LEFT
	};


	int EnemyX;
	int EnemyY;
	bool animeFlg = false;      //�A�j���[�V�����t���O
	int animcount = 0;      //�A�j���[�V�����̕b��
	static bool trackFlg;      //�ǂ�������t���O
	bool ijike = false;     //���������
	int nowway = 0;     //���݂̌���
	int Enowdraw = 0;      //���݂̕`��
	int E3draw = 0;
	bool nowflg = false;      //���݂̃A�j���[�V�����̐؂�ւ��
	float EnemySpeed;			//�X�s�[�h

	int ijikeimage1[2]{ 0,0 };      //��������Ԕ�
	int image1[2]{ 0,0 };      //�摜�P�̍����Q��
	int image2[2]{ 0,0 };      //�摜�Q�̍����Q��   
	int image3[2]{ 0,0 };      //�摜�R�̍����Q��
	int image4[2]{ 0,0 };      //�摜�S�̍����Q��

	int kugi;
	int billibilli[4];
	int naki[2];

	int kega[2];
	int nige[2];

	enum EDirection
	{
		ENEMY_NORMAL_UP = 1,
		ENEMY_NORMAL_RIGHT,
		ENEMY_NORMAL_DOWN,
		ENEMY_NORMAL_LEFT,
		ENEMY_IJIKE_BLACK,
		ENEMY_IJIKE_WHITE,
		ENEMY_MEDAMA_UP,
		ENEMY_MEDAMA_RIGHT,
		ENEMY_MEDAMA_DOWN,
		ENEMY_MEDAMA_LEFT
	};

	int CoffeeBreakType;
	int PlayTime;
	int* stageCount;


public:
	Coffee(int*);


	void CoffeeBreak1();
	void Draw1() const;
	void CoffeeBreak2();
	void Draw2() const;
	void CoffeeBreak3();
	void Draw3() const;

	void PacAnimation();
	void PacDirection();


	bool ToggleFlg(bool flg) { flg = !(flg); return flg; }
	void EnemyAnimaition();


	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update(XINPUT_STATE data) override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;


};