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



	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update(XINPUT_STATE data) override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;


};