#include "Player.h"
#include "DxLib.h"
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Player::Player()
{
	speed = 40;     //移動速度
	flg = true;      //プレイヤー表示フラグ
	ismove = false;//false・・・止まる,true・・・動く
	playerimg[0] = LoadGraph("images/pac1.png");   //プレイヤー画像用変数
	playerimg[1] = LoadGraph("images/パックマン2.png");
	playerimg[2] = LoadGraph("images/パックマン3.png");
	playeranim = 0;

	x = 100.0;
	y = 100.0;      //座標x,y

	playerzanki = 3;
}

void Player::PlayerDisplay()
{
	//to do きれいにする
	if (flg == true)
	{
		switch (PlayerDirection)
		{
		case 0://上
			DrawRotaGraph(x, y, 1.0, 1.5707963267948966, playerimg[playeranim / 3], TRUE, FALSE);
			Speedflg();
			y -= movepixel;
			playeranim++;
			if (playeranim >= 9)
			{
				playeranim = 0;
			}
			break;
		case 1://右
			DrawRotaGraph(x, y, 1.0, 3.141592653589793, playerimg[playeranim / 3], TRUE, FALSE);
			Speedflg(); 
			x += movepixel;
			playeranim++;
			if (playeranim >= 9)
			{
				playeranim = 0;
			}
			break;
		case 2://下
			DrawRotaGraph(x, y, 1.0, 4.71238898038469, playerimg[playeranim / 3], TRUE, FALSE);
			Speedflg(); 
			y += movepixel;
			playeranim++;
			if (playeranim >= 9)
			{
				playeranim = 0;
			}
			break;
		case 3://左
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



	if (control.Buttons[XINPUT_BUTTON_DPAD_UP] || control.ThumbLY > 10000) PlayerDirection = 0;   //スティックと方向キー
	if (control.Buttons[XINPUT_BUTTON_DPAD_RIGHT] || control.ThumbLX > 10000) PlayerDirection = 1;   //スティックと方向キー
	if (control.Buttons[XINPUT_BUTTON_DPAD_DOWN] || control.ThumbLY < -10000) PlayerDirection = 2;   //スティックと方向キー
	if (control.Buttons[XINPUT_BUTTON_DPAD_LEFT] || control.ThumbLX < -10000) PlayerDirection = 3;   //スティックと方向キー
	
	

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
	DrawFormatString(580, 450, 0xFFD700, "×%d",playerzanki);
	DrawGraph(550, 460, playerimg[1], false);

	
}

int Player::Image()
{
	return 0;
}