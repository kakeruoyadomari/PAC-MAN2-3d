#include "Player.h"
#include "DxLib.h"
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Player::Player()
{
	speed = 40;     //�ړ����x
	flg = true;      //�v���C���[�\���t���O
	ismove = false;//false�E�E�E�~�܂�,true�E�E�E����
	playerimg[0] = LoadGraph("images/pac1.png");   //�v���C���[�摜�p�ϐ�
	playerimg[1] = LoadGraph("images/�p�b�N�}��2.png");
	playerimg[2] = LoadGraph("images/�p�b�N�}��3.png");
	playeranim = 0;

	x = 100.0;
	y = 100.0;      //���Wx,y

	playerzanki = 3;
}

void Player::PlayerDisplay()
{
	//to do ���ꂢ�ɂ���
	if (flg == true)
	{
		switch (PlayerDirection)
		{
		case 0://��
			DrawRotaGraph(x, y, 1.0, 1.5707963267948966, playerimg[playeranim / 3], TRUE, FALSE);
			Speedflg();
			y -= movepixel;
			playeranim++;
			if (playeranim >= 9)
			{
				playeranim = 0;
			}
			break;
		case 1://�E
			DrawRotaGraph(x, y, 1.0, 3.141592653589793, playerimg[playeranim / 3], TRUE, FALSE);
			Speedflg(); 
			x += movepixel;
			playeranim++;
			if (playeranim >= 9)
			{
				playeranim = 0;
			}
			break;
		case 2://��
			DrawRotaGraph(x, y, 1.0, 4.71238898038469, playerimg[playeranim / 3], TRUE, FALSE);
			Speedflg(); 
			y += movepixel;
			playeranim++;
			if (playeranim >= 9)
			{
				playeranim = 0;
			}
			break;
		case 3://��
			DrawRotaGraph(x, y, 1.0, 0, playerimg[playeranim / 3], TRUE, FALSE);
			Speedflg();
			x -= movepixel;
			playeranim++;
			if (playeranim > 9)
			{
				playeranim = 0;
			}
			break;
		}
	}
	
}

void Player::Speedflg()
{
	int flamespeed = 16;
	static int speedflg = 0;
	movepixel = 0;

	speedflg = speed + speedflg;
	while (speedflg > flamespeed)
	{
		speedflg = speedflg - flamespeed;
		movepixel++;
	}
}

void Player::MovePlayer()
{



	if (control.Buttons[XINPUT_BUTTON_DPAD_UP] || control.ThumbLY > 10000) PlayerDirection = 0;   //�X�e�B�b�N�ƕ����L�[
	if (control.Buttons[XINPUT_BUTTON_DPAD_RIGHT] || control.ThumbLX > 10000) PlayerDirection = 1;   //�X�e�B�b�N�ƕ����L�[
	if (control.Buttons[XINPUT_BUTTON_DPAD_DOWN] || control.ThumbLY < -10000) PlayerDirection = 2;   //�X�e�B�b�N�ƕ����L�[
	if (control.Buttons[XINPUT_BUTTON_DPAD_LEFT] || control.ThumbLX < -10000) PlayerDirection = 3;   //�X�e�B�b�N�ƕ����L�[
	
	

}
void Player::Init(XINPUT_STATE data)
{
	control = data;
	
}
void Player::UpDate()
{
	MovePlayer();
	/*this->x++;*/
	
}

void Player::Animaition()
{
	
}

void Player::Draw() const
{
	DrawFormatString(20, 40, 0xffffff, "%d", this->x);
	DrawFormatString(580, 450, 0xFFD700, "�~%d",playerzanki);
	DrawGraph(550, 460, playerimg[1], false);

	
}

int Player::Image()
{
	return 0;
}