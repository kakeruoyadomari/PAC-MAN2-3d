#pragma once
#include "AbstractScene.h"

class Title : public AbstractScene {
private:
	int WaitTime;
	int PosY;
	int GameState;
	int MenuNumber;
	int MenuY;
public:
	Title() {
     MenuY = 0;
	}
	
	// �f�X�g���N�^
	~Title() {
		
	};

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update(XINPUT_STATE data) override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;


};