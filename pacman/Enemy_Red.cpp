#include "Enemy_Red.h"

Enemy_Red::Enemy_Red(Player* plyr,int*data)
{
	image1[0] = LoadGraph("images/Red1.png");
	image1[1] = LoadGraph("images/Red5.png");
	image2[0] = LoadGraph("images/Red2.png");
	image2[1] = LoadGraph("images/Red6.png");
	image3[0] = LoadGraph("images/Red3.png");
	image3[1] = LoadGraph("images/Red7.png");
	image4[0] = LoadGraph("images/Red4.png");
	image4[1] = LoadGraph("images/Red8.png");

	stageCount = data;
	player = plyr;
	enemy_red = this;

	nowway = ENEMY_NORMAL_LEFT;
	x = 14 * DOT_SIZE - 11;
	y = 12 * DOT_SIZE - 11;

	enemydic.direction = 4;
	enemydic.x_direction = -1;
	enemydic.y_direction = 0;

	nowdraw = image1[0];

}

void Enemy_Red::UpDate()
{
	int_x = roundf(x);
	int_y = roundf(y);

	if (x < 4) {
		x = 630;
	}
	else if (x > 630) {
		x = 4;
	}

	if (GamePlayFlg == true) {
		Animaition();
		if (TrackTime++ / 660 == 1) {
			trackFlg = ToggleFlg(trackFlg);
			TrackTime = 0;
		}

		if (trackFlg == true) {

			if (int_x % DOT_SIZE == 11 && int_y % DOT_SIZE == 11) {
				Rocation(player->GetX(), player->GetY(),
					x, y, &enemydic.direction, &enemydic.x_direction, &enemydic.y_direction);
				x += enemydic.x_direction;
				y += enemydic.y_direction;
			}
			else {
				x += enemydic.x_direction;
				y += enemydic.y_direction;
			}
		}
		else {
			/*if (x % DOT_SIZE == 11 && y % DOT_SIZE == 11) {
				Rocation(26 * DOT_SIZE, 4 * DOT_SIZE,
					x, y, &enemydic.direction, &enemydic.x_direction, &enemydic.y_direction);
				x += enemydic.x_direction;
				y += enemydic.y_direction;
			}
			else {
				x += enemydic.x_direction;
				y += enemydic.y_direction;
			}*/
			if (int_x % DOT_SIZE == 11 && int_y % DOT_SIZE == 11) {
				Rocation(player->GetX(), player->GetY(),
					x, y, &enemydic.direction, &enemydic.x_direction, &enemydic.y_direction);
				x += enemydic.x_direction;
				y += enemydic.y_direction;
			}
			else {
				x += enemydic.x_direction;
				y += enemydic.y_direction;
			}
		}
	}
	else {
		
	}

	//if (CheckHitPlayer(player, this) == true) {
	//	GamePlayFlg = false;
	//}


	
}

void Enemy_Red::Animaition()
{
	animcount++;

	if (animcount % 10 == 0) {
		nowflg = ToggleFlg(nowflg);
		animcount = 1;
	}

	if (ijike!=true) {
		switch (enemydic.direction)
		{
		case ENEMY_NORMAL_UP:
			if (nowflg != true) {
				nowdraw = image3[0];
			}
			else
			{
				nowdraw = image3[1];
			}
			break;
		case ENEMY_NORMAL_RIGHT:
			if (nowflg != true) {
				nowdraw = image2[0];
			}
			else
			{
				nowdraw = image2[1];
			}
			break;
		case ENEMY_NORMAL_DOWN:
			if (nowflg != true) {
				nowdraw = image4[0];
			}
			else
			{
				nowdraw = image4[1];
			}
			break;
		case ENEMY_NORMAL_LEFT:
			if (nowflg != true) {
				nowdraw = image1[0];
			}
			else
			{
				nowdraw = image1[1];
			}
			break;
		default:
			break;
		}
	}
	else if(ijike==true){
		if (nowflg != true) {
			nowdraw = ijikeimage1[0];
		}
		else {
			nowdraw = ijikeimage1[1];
		}
	}
}

void Enemy_Red::Draw() const
{
	if (GamePlayFlg == true) {
		DrawRotaGraph(x + STAGE_LEFT_SPACE, y, 1, 0, nowdraw, TRUE);
	}
}

void Enemy_Red::TargetRocation(float, float, int)
{
}
