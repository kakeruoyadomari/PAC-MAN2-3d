#pragma once
#include "AbstractScene.h"

class Title : public AbstractScene {
private:
	int WaitTime;
	int PosY;
	int GameState;
	int MenuNumber;
	int MenuY;

	int TitleImage;
	int Menu;
	int Time;
public:
	Title() {
     MenuY = 0;
	 WaitTime = 0;

	 //�^�C�g���摜
	 TitleImage = LoadGraph("images/Title.png");

	 //���j���[
	 Menu = LoadGraph("images/start.png");
	}
	
	// �f�X�g���N�^
	~Title() {
		
	};

	//�`��ȊO�̍X�V����������
	virtual AbstractScene* Update(XINPUT_STATE data) override;

	//�`��Ɋւ��邱�Ƃ���������
	virtual void Draw() const override;


};