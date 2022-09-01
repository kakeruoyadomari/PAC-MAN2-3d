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
	playerimg[1] = LoadGraph("images/pac2.png");
	playerimg[2] = LoadGraph("images/pac3.png");
	playeranim = 0;

	x = 500.0;
	y = 100.0;      //���Wx,y
	radius = 4;

}

void Player::PlayerDisplay()
{
	//	//�v���C���[�̕\��
	//if (flg == true)
	//{
	//	if (speed < 0)
	//	{
	//		DrawRotaGraph((int)x, (int)y, 1.0f, 0, playerimg[1], true, TRUE);//TRUE�ɂ�����摜���]�Ō��TRUE
	//	}
	//	else if (speed > 0)
	//	{
	//		DrawRotaGraph((int)x, (int)y, 1.0f, 0, playerimg[2], true, FALSE);
	//	}
	//	else
	//	{
	//		DrawRotaGraph((int)x, (int)y, 1.0f, 0, playerimg[0], true, FALSE);
	//	}
	//}
	if (flg == true)
	{
		switch (PlayerDirection)
		{
		case 0:
			DrawRotaGraph(x, y, 1.0, 1.5707963267948966, playerimg[playeranim / 3], TRUE, FALSE);
			ChangeSpeed();
			y -= movepixel;
			//fallspeed = 11;
			playeranim++;
			if (playeranim >= 9)
			{
				playeranim = 0;
			}
			break;
		case 1:
			DrawRotaGraph(x, y, 1.0, 3.141592653589793, playerimg[playeranim / 3], TRUE, FALSE);
			ChangeSpeed();
			x += movepixel;
			//fallspeed = 1;
			playeranim++;
			if (playeranim >= 9)
			{
				playeranim = 0;
			}
			break;
		case 2:
			DrawRotaGraph(x, y, 1.0, 4.71238898038469, playerimg[playeranim / 3], TRUE, FALSE);
			ChangeSpeed(); 
			y += movepixel;
			//fallspeed = 17;
			playeranim++;
			if (playeranim >= 9)
			{
				playeranim = 0;
			}
			break;
		case 3:
			DrawRotaGraph(x, y, 1.0, 0, playerimg[playeranim / 3], TRUE, FALSE);
			ChangeSpeed();
			x -= movepixel;
			playeranim++;
			if (playeranim >= 9)
			{
				playeranim = 0;
			}
			break;
		}
	}
}
//void Player::NotOverhang()
//{
//	//��ʂ��͂ݏo���Ȃ��悤�ɂ���
//	if ((int)x < 37) {
//		x = 37.0;
//		speed = 0;
//	}
//
//	if ((int)x > SCREEN_WIDTH - 180) {
//		x = (float)(SCREEN_WIDTH - 180);
//		speed = 0;
//	}
//
//	//if (m_y > SCREEN_HEIGHT - m_y)m_y = SCREEN_HEIGHT - m_y;
//}

void Player::ChangeSpeed()
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
	//int num = 3;



	if (control.Buttons[XINPUT_BUTTON_DPAD_UP] || control.ThumbLY > 10000) PlayerDirection = 0;   //�X�e�B�b�N�ƕ����L�[
	if (control.Buttons[XINPUT_BUTTON_DPAD_RIGHT] || control.ThumbLX > 10000) PlayerDirection = 1;   //�X�e�B�b�N�ƕ����L�[
	if (control.Buttons[XINPUT_BUTTON_DPAD_DOWN] || control.ThumbLY < -10000) PlayerDirection = 2;   //�X�e�B�b�N�ƕ����L�[
	if (control.Buttons[XINPUT_BUTTON_DPAD_LEFT] || control.ThumbLX < -10000) PlayerDirection = 3;   //�X�e�B�b�N�ƕ����L�[
	
	////���E�ړ�
	//if (flg == TRUE)
	//{
	//	NotOverhang();
	//	if (control.ThumbLX < -2000||control.Buttons[XINPUT_BUTTON_DPAD_LEFT]) {
	//		//��//�g����
	//		x += ;
	//	}
	//	else if (control.ThumbLX > 2000|| control.Buttons[XINPUT_BUTTON_DPAD_RIGHT]) {
	//		//�E//�g����
	//		x += ;
	//	}
	//	else {
	//		StopMotion();
	//	}
	//}
	////PLbox.PL_SetAreaVecter(x, y, ismove);

}
void Player::PlayerControl() {
	if (flg == TRUE) {
	
	}
}
void Player::StopMotion(void) {

	//if (speed >= 0) {			//�v���X�����ւ̉����� �E����
	//	if (speed != 0) {
	//		speed -= ACCELERATION;
	//		x += speed;
	//		if (speed < 0)speed = 0;
	//	}
	//}
	//else if (speed <= 0) {	//�}�C�i�X�����̉����� ������
	//	if (speed != 0) {
	//		speed += ACCELERATION;
	//		x += speed;
	//		if (speed > 0)speed = 0;
	//	}
	//}

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
}

int Player::Image()
{
	//if ((player = LoadGraph("images/pac1.png")) == -1)return -1;
	//if ((playerrun = LoadGraph("images/�p�b�N�}��2.png")) == -1)return -1;
	//if ((playerrun2 = LoadGraph("images/�p�b�N�}��3.png")) == -1)return -1;
	return 0;
}