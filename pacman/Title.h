#pragma once
#include "AbstractScene.h"

class Title : public AbstractScene {
private:


public:
	Title() {


	}


	// �f�X�g���N�^
	~Title() {

	};

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update(XINPUT_STATE data) override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;


};