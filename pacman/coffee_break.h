#pragma once
#include "AbstractScene.h"
#include "Player.h"

class Coffee : public AbstractScene {
private:
	int Pacimg[3];
	int Pacanim;
	int PacSize;
	int PacSpeed;
	int Nowdraw;
	int PacX;
	int PacY;
	float Nowdirect;
	int PDirection;
	enum Direction
	{
		PLAYER_NORMAL_UP = 1,
		PLAYER_NORMAL_RIGHT,
		PLAYER_NORMAL_DOWN,
		PLAYER_NORMAL_LEFT
	};

	int CoffeeBreakType = 0;

public:
	Coffee();


	void CoffeeBreak1();
	void Draw1() const;
	void CoffeeBreak2();
	void Draw2() const;
	void CoffeeBreak3();
	void Draw3() const;

	void PacAnimation();
	void PacDirection();

	//描画以外の更新を実装する
	virtual AbstractScene* Update(XINPUT_STATE data) override;

	//描画に関することを実装する
	virtual void Draw() const override;


};