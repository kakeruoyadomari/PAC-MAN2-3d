#include "Player.h"
#include"Stage.h"
#include "DxLib.h"
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Player::Player(Stage* data)
{

	speed = 1;     //�ړ����x
	drawflg = true;      //�v���C���[�\���t���O
	ismove = true;//false�E�E�E�~�܂�,true�E�E�E����
	playerimg[0] = LoadGraph("images/pac1.png");   //�v���C���[�摜�p�ϐ�
	playerimg[1] = LoadGraph("images/pac2.png");
	playerimg[2] = LoadGraph("images/pac3.png");
	playeranim = 0;

	x = 16*DOT_SIZE-11;
	y = 14*DOT_SIZE-11;      //���Wx,y
	radius = 4;

	plyrdrct.x_direction = 1;
	plyrdrct.y_direction = 0;

	stage = data;
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

	int dx = 0;

	
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

		if (control.Buttons[XINPUT_BUTTON_DPAD_UP] || control.ThumbLY > 10000) {
			if (CheckHitWall(x, y, PLAYER_NORMAL_UP) == false) {
				if (x % DOT_SIZE == 11) {
					plyrdrct.x_direction = 0;
					plyrdrct.y_direction = -1;
					plyrdrct.direction = PLAYER_NORMAL_UP;
					speed = 1;
				}
			}
		}

		if (control.Buttons[XINPUT_BUTTON_DPAD_DOWN] || control.ThumbLY < -10000) {
			if (CheckHitWall(x,y,PLAYER_NORMAL_DOWN)==false) {
				if (x % DOT_SIZE == 11) {
					plyrdrct.x_direction = 0;
					plyrdrct.y_direction = 1;
					plyrdrct.direction = PLAYER_NORMAL_DOWN;
					speed = 1;
				}
			}
		}

		if (control.Buttons[XINPUT_BUTTON_DPAD_RIGHT] || control.ThumbLX > 10000){
			if (CheckHitWall(x, y, PLAYER_NORMAL_RIGHT) == false) {
				if (y % DOT_SIZE == 11) {
					plyrdrct.x_direction = 1;
					plyrdrct.y_direction = 0;
					plyrdrct.direction = PLAYER_NORMAL_RIGHT;
					speed = 1;
				}
			}
		}

		if (control.Buttons[XINPUT_BUTTON_DPAD_LEFT] || control.ThumbLX < -10000) {
			if (CheckHitWall(x, y, PLAYER_NORMAL_LEFT) == false) {
				if (y % DOT_SIZE == 11) {
					plyrdrct.x_direction = -1;
					plyrdrct.y_direction = 0;
					plyrdrct.direction = PLAYER_NORMAL_LEFT;
					speed = 1;
				}
			}
		}


		// キー入力がなかったときも当たり判定
		if (CheckHitWall(x, y, plyrdrct.direction) == true&&(x%DOT_SIZE==11||y%DOT_SIZE==11)) {
			speed = 0;
			plyrdrct.x_direction = 0;
			plyrdrct.y_direction = 0;
		}
		

		x += speed * plyrdrct.x_direction;
		y += speed * plyrdrct.y_direction;



	//if(speed!=0){
	//	 //パックマン移動中（マス目の中間にいるとき）
	//	speed -= 1;//パックマンの移動処理
	//	
	//}
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

void Player::Draw() const
{
	DrawRotaGraph(x, y, 1, nowdirect, nowdraw, TRUE, FALSE);
	DrawPixel(x, y, 0x00ff00);
}

int Player::Image()
{
	//if ((player = LoadGraph("images/pac1.png")) == -1)return -1;
	//if ((playerrun = LoadGraph("images/�p�b�N�}��2.png")) == -1)return -1;
	//if ((playerrun2 = LoadGraph("images/�p�b�N�}��3.png")) == -1)return -1;
	return 0;
}