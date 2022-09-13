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



	//•`‰æˆÈŠO‚ÌXV‚ğÀ‘•‚·‚é
	virtual AbstractScene* Update(XINPUT_STATE data) override;

	//•`‰æ‚ÉŠÖ‚·‚é‚±‚Æ‚ğÀ‘•‚·‚é
	virtual void Draw() const override;


};