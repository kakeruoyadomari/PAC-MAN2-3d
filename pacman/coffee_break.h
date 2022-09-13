#pragma once
#include "AbstractScene.h"
#include "Player.h"

class Coffee : public AbstractScene {
private:
	Player* player;

	int Breaktype = 0;

public:
	Coffee();


	void Break1();
	void Break2();
	void Break3();



	//描画以外の更新を実装する
	virtual AbstractScene* Update(XINPUT_STATE data) override;

	//描画に関することを実装する
	virtual void Draw() const override;


};