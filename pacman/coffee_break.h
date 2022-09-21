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
	bool animeFlg = false;      //アニメーションフラグ
	int animcount = 0;      //アニメーションの秒数
	static bool trackFlg;      //追いかけるフラグ
	bool ijike = false;     //いじけ状態
	int nowway = 0;     //現在の向き
	int Enowdraw = 0;      //現在の描画
	int E3draw = 0;
	bool nowflg = false;      //現在のアニメーションの切り替わり
	float EnemySpeed;			//スピード

	int ijikeimage1[2]{ 0,0 };      //いじけ状態白
	int image1[2]{ 0,0 };      //画像１の差分２枚
	int image2[2]{ 0,0 };      //画像２の差分２枚   
	int image3[2]{ 0,0 };      //画像３の差分２枚
	int image4[2]{ 0,0 };      //画像４の差分２枚

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


	//描画以外の更新を実装する
	virtual AbstractScene* Update(XINPUT_STATE data) override;

	//描画に関することを実装する
	virtual void Draw() const override;


};