#include "Player.h"
#include"Stage.h"
#include "DxLib.h"
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Stage stage;

Player::Player()
{

	speed = 1;     //�ړ����x
	drawflg = true;      //�v���C���[�\���t���O
	ismove = true;//false�E�E�E�~�܂�,true�E�E�E����
	playerimg[0] = LoadGraph("images/pac1.png");   //�v���C���[�摜�p�ϐ�
	playerimg[1] = LoadGraph("images/pac2.png");
	playerimg[2] = LoadGraph("images/pac3.png");
	playeranim = 0;

	x = 13;
	y = 16;      //���Wx,y
	radius = 4;

	plyrdrct.x_direction = 0;
	plyrdrct.y_direction = 0;
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
	
		//if (mv == 0) {
		//			 //足元判定
		//			if (gMap[y][x] == 1) {
		//				 Sound「ぱくっ！！」
		//				gScore += 10;
		//				gMap[y][x] = 0;
		//			}
		//			if (gMap[y][x] == 2) {
		//				 パワー餌食べる
		//				gScore += 50;
		//				gMap[y][x] = 0;
		//			}
		// //足元判定
		//if (stage.GetStageData(y,x) == 0) {
		//	 //Sound「ぱくっ！！」
		//	gScore += 10;
		//	StagePixel[y][x] = 1;//餌で移動してるところをみてう
		//}

		 //マス目にいるときだけキー入力判定
		if (control.Buttons[XINPUT_BUTTON_DPAD_UP] || control.ThumbLY > 10000) {
			if (stage.CheckWall(x, y, 0, -1)==0) {
				plyrdrct.x_direction = 0;
				plyrdrct.y_direction = -1;
				plyrdrct.direction = PLAYER_NORMAL_UP;

			}
		}
		else if (control.Buttons[XINPUT_BUTTON_DPAD_DOWN] || control.ThumbLY < -10000) {
			if (!stage.CheckWall(x, y, 0, 1)==0) {
				plyrdrct.x_direction = 0;
				plyrdrct.y_direction = 1;
				plyrdrct.direction = PLAYER_NORMAL_DOWN;
			}
		}
		else if (control.Buttons[XINPUT_BUTTON_DPAD_RIGHT] || control.ThumbLX > 10000){
			if (!stage.CheckWall(x, y, 1, 0)==0) {
				plyrdrct.x_direction = -1;
				plyrdrct.y_direction = 0;
				plyrdrct.direction = PLAYER_NORMAL_RIGHT;
			}
		}
		else if (control.Buttons[XINPUT_BUTTON_DPAD_LEFT] || control.ThumbLX < -10000) {
			if (!stage.CheckWall(x, y, -1, 0)==0) {
				plyrdrct.x_direction = 1;
				plyrdrct.y_direction = 0;
				plyrdrct.direction = PLAYER_NORMAL_LEFT;
			}
		}
		else {	// キー入力がなかったときも当たり判定
			switch (plyrdrct.direction)
			{
			case PLAYER_NORMAL_UP:
				if (stage.CheckWall(x, y, 0, -1)!=0) {
					speed = 0;
				}
				else {
					speed = 11;
				}
				break;
			case PLAYER_NORMAL_RIGHT:
				if (stage.CheckWall(x, y, 1, 0) != 0) {
					speed = 0;
				}
				else {
					speed = 11;
				}
				break;
			case PLAYER_NORMAL_DOWN:
				if (stage.CheckWall(x, y, 0, 1) != 0) {
					speed = 0;
				}
				else {
					speed = 11;
				}
				break;
			case PLAYER_NORMAL_LEFT:
				if (stage.CheckWall(x, y, -1, 0) != 0) {
					speed = 0;
				}
				else {
					speed = 11;
				}
				break;
			default:
				break;
			}
			
		}
	
	//if(speed!=0){
	//	 //パックマン移動中（マス目の中間にいるとき）
	//	speed -= 1;//パックマンの移動処理
	//	
	//}


		if (stage.CheckWall(x, y, plyrdrct.x_direction, plyrdrct.y_direction) != 0) {
			plyrdrct.x_direction = 0; plyrdrct.y_direction = 0;
			speed = 0;
		}
		else {
			x += plyrdrct.x_direction;
			y += plyrdrct.y_direction;
			speed = 0;//dx=0;dy=0;
		}
		speed--;

		moveX = x  * 22 + (11 - speed)*2 * plyrdrct.x_direction;
		moveY = y  * 22 + (11 - speed)*2 * plyrdrct.y_direction;
}
void Player::Init(XINPUT_STATE data)
{
	control = data;
	
}
void Player::UpDate()
{
	MovePlayer();
	Animaition();
	PlayerDisplay();
	/*this->x++;*/
	
}

void Player::Animaition()
{
	playeranim++;
	if (playeranim >= 9)
	{
		playeranim = 0;
	}

	nowdraw = playerimg[playeranim / 3];


}

void Player::Draw() const
{
	DrawRotaGraph(moveX, moveY, 1.0, nowdirect, nowdraw, TRUE, FALSE);
}

int Player::Image()
{
	//if ((player = LoadGraph("images/pac1.png")) == -1)return -1;
	//if ((playerrun = LoadGraph("images/�p�b�N�}��2.png")) == -1)return -1;
	//if ((playerrun2 = LoadGraph("images/�p�b�N�}��3.png")) == -1)return -1;
	return 0;
}