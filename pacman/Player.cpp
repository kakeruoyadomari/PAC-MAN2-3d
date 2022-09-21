#include "Player.h"
#include"Stage.h"
#include "DxLib.h"

Player::Player(Stage* data)
{

	speed = 0.1;     //�ړ����x
	drawflg = true;      //�v���C���[�\���t���O
	ismove = true;//false�E�E�E�~�܂�,true�E�E�E����
	playerimg[0] = LoadGraph("images/pac1.png");   //�v���C���[�摜�p�ϐ�
	playerimg[1] = LoadGraph("images/pac2.png");
	playerimg[2] = LoadGraph("images/pac3.png");
	playeranim = 0;

	x = 16*DOT_SIZE-11;
	y = 18*DOT_SIZE-11;      //���Wx,y
	radius = 4;

	int_x = 0;
	int_y = 0;


	plyrdrct.direction = 4;
	plyrdrct.x_direction = -1;
	plyrdrct.y_direction = 0;

	stage = data;

	nowdraw = playerimg[0];
}

void Player::PlayerDisplay()
{
	if (drawflg == true)
	{
		switch (plyrdrct.direction)
		{
		case PLAYER_NORMAL_UP:
			nowdirect = PI / 2;
			break;
		case PLAYER_NORMAL_RIGHT:
			nowdirect = PI;
			break;
		case PLAYER_NORMAL_DOWN:
			nowdirect = PI + PI / 2;

			break;
		case PLAYER_NORMAL_LEFT:
			nowdirect = 0;
			break;
		}
	}
}



void Player::MovePlayer()
{
	int_x = roundf(x);
	int_y = roundf(y);

	if (x < 4) {
		x = 630;
	}
	else if (x > 630) {
		x = 4;
	}

	if (control.Buttons[XINPUT_BUTTON_DPAD_UP] || control.ThumbLY > 10000 || (adovanced_direction == PLAYER_NORMAL_UP)) {
		adovanced_direction = PLAYER_NORMAL_UP;
		if (CheckHitWall(int_x, int_y, PLAYER_NORMAL_UP) == false) {
			if (int_x % DOT_SIZE == 11) {
				plyrdrct.x_direction = 0;
				plyrdrct.y_direction = -1;
				plyrdrct.direction = PLAYER_NORMAL_UP;
				speed = RoundSpeed;
			}
		}
	}

	if (control.Buttons[XINPUT_BUTTON_DPAD_DOWN] || control.ThumbLY < -10000 || (adovanced_direction == PLAYER_NORMAL_DOWN)) {
		adovanced_direction = PLAYER_NORMAL_DOWN;
		if (CheckHitWall(int_x, int_y, PLAYER_NORMAL_DOWN) == false) {
			if (int_x % DOT_SIZE == 11) {
				plyrdrct.x_direction = 0;
				plyrdrct.y_direction = 1;
				plyrdrct.direction = PLAYER_NORMAL_DOWN;
				speed = RoundSpeed;
			}
		}
	}

	if (control.Buttons[XINPUT_BUTTON_DPAD_RIGHT] || control.ThumbLX > 10000 || (adovanced_direction == PLAYER_NORMAL_RIGHT)) {
		adovanced_direction = PLAYER_NORMAL_RIGHT;
		if (CheckHitWall(int_x, int_y, PLAYER_NORMAL_RIGHT) == false) {
			if (int_y % DOT_SIZE == 11) {
				plyrdrct.x_direction = 1;
				plyrdrct.y_direction = 0;
				plyrdrct.direction = PLAYER_NORMAL_RIGHT;
				speed = RoundSpeed;
			}
		}
	}

	if (control.Buttons[XINPUT_BUTTON_DPAD_LEFT] || control.ThumbLX < -10000 || (adovanced_direction == PLAYER_NORMAL_LEFT)) {
		adovanced_direction = PLAYER_NORMAL_LEFT;
		if (CheckHitWall(int_x, int_y, PLAYER_NORMAL_LEFT) == false) {
			if (int_y % DOT_SIZE == 11) {
				plyrdrct.x_direction = -1;
				plyrdrct.y_direction = 0;
				plyrdrct.direction = PLAYER_NORMAL_LEFT;
				speed = RoundSpeed;
			}
		}
	}


	// キー入力がなかったときも当たり判定
	if (CheckHitWall(int_x, int_y, plyrdrct.direction) == true) {
		speed = 0;
		plyrdrct.x_direction = 0;
		plyrdrct.y_direction = 0;
	}

	x += speed * plyrdrct.x_direction;
	y += speed * plyrdrct.y_direction;
}
void Player::Init(XINPUT_STATE data)
{
	control = data;
	
}

void Player::UpDate()
{
	if (NowGameFlg == true) {
		Animaition();
		PlayerDisplay();
		MovePlayer();
	}
	else {
		Animaition();
		PlayerDisplay();
	}
	

	/*this->x++;*/
	
}

void Player::Animaition()
{
	if (NowGameFlg == true) {

		if (speed > 0) {
			playeranim++;
			if (playeranim >= 9)
			{
				playeranim = 0;
			}

			nowdraw = playerimg[playeranim / 3];
		}
		else {
			nowdraw = playerimg[0];
		}
	}
	else {
		//ゲームオーバーアニメーション
	}
}

void Player::Draw() const
{
	DrawFormatString(800, 10, 0xffffff, "x:%fl",x);
	DrawFormatString(800, 50, 0xffffff, "y:%fl",y);
	DrawFormatString(800, 100, 0xffffff, "direction:%d", adovanced_direction);
	DrawRotaGraph(x+STAGE_LEFT_SPACE, y, 1.8, nowdirect, nowdraw, TRUE, FALSE);
	DrawPixel(x+STAGE_LEFT_SPACE, y, 0x00ff00);
}
