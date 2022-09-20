#include "Enemy_Pink.h"

Enemy_Pink::Enemy_Pink()
{
	image1[0] = LoadGraph("images/Pink1.png");
	image1[1] = LoadGraph("images/Pink5.png");
	image2[0] = LoadGraph("images/Pink2.png");
	image2[1] = LoadGraph("images/Pink6.png");
	image3[0] = LoadGraph("images/Pink3.png");
	image3[1] = LoadGraph("images/Pink7.png");
	image4[0] = LoadGraph("images/Pink4.png");
	image4[1] = LoadGraph("images/Pink8.png");

	nowway = ENEMY_NORMAL_LEFT;
	x = 14 * DOT_SIZE;
	y = 15 * DOT_SIZE - 11;

	enemydic.direction = 1;
	enemydic.x_direction = 0;
	enemydic.y_direction = -1;

	nowdraw = image3[0];
}

void Enemy_Pink::UpDate()
{

	int_x = roundf(x);
	int_y = roundf(y);

	if (x < 4) {
		x = 630;
	}
	else if (x > 630) {
		x = 4;
	}

	if (existhome == false&& existedanim ==false) {

		if (hometimer == 0) {
			if (enemydic.direction == 1) {
				enemydic.direction = 3;
				enemydic.y_direction = 1;
			}
			else {
				enemydic.direction = 1;
				enemydic.y_direction = -1;
			}

		}

		y += enemydic.y_direction;
		Animaition();
	}
	else if(existhome == true && existedanim == false){
		ExistAnime(this);

		x += 0.5 * enemydic.x_direction;
		y += 0.5 * enemydic.y_direction;
		
		if (int_y == 12 * DOT_SIZE -10) {
			existedanim = true;
			y += 0.5;
			x -= 11;
		}
		Animaition();
	}
	else if(existedanim == true){
		if (GamePlayFlg == true) {
			Animaition();
			if (TrackTime++ / 660 == 1) {
				trackFlg = ToggleFlg(trackFlg);
				TrackTime = 0;
			}

			if (trackFlg == true) {

				TargetRocation(player->GetX(), player->GetY(), player->GetDirection());

				if (int_x % DOT_SIZE == 11 && int_y % DOT_SIZE == 11) {
					Rocation(targetxpoint, targetypoint,
						int_x, int_y, &enemydic.direction, &enemydic.x_direction, &enemydic.y_direction);
					x += enemydic.x_direction;
					y += enemydic.y_direction;
				}
				else {
					x += enemydic.x_direction;
					y += enemydic.y_direction;
				}
			}
			else {/*
				if (int_x % DOT_SIZE == 11 && int_y % DOT_SIZE == 11) {
					Rocation(26 * DOT_SIZE, 4 * DOT_SIZE,
						int_x, int_y, &enemydic.direction, &enemydic.x_direction, &enemydic.y_direction);
					x += enemydic.x_direction;
					y += enemydic.y_direction;
				}
				else {
					x += enemydic.x_direction;
					y += enemydic.y_direction;
				}*/
				TargetRocation(player->GetX(), player->GetY(), player->GetDirection());


				if (int_x % DOT_SIZE == 11 && int_y % DOT_SIZE == 11) {
					Rocation(targetxpoint, targetypoint,
						int_x, int_y, &enemydic.direction, &enemydic.x_direction, &enemydic.y_direction);
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

		if (CheckHitPlayer(player, this) == true) {
			//GamePlayFlg = false;
		}
	}
}
void Enemy_Pink::Animaition()
{
	animcount++;

	if (animcount % 10 == 0) {
		nowflg = ToggleFlg(nowflg);
		animcount = 1;
	}

	if (x < 4) {
		x = 630;
	}
	else if (x > 630) {
		x = 4;
	}

	if (ijike != true) {
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
	else if (ijike == true) {
		if (nowflg != true) {
			nowdraw = ijikeimage1[0];
		}
		else {
			nowdraw = ijikeimage1[1];
		}
	}
}

void Enemy_Pink::Draw() const
{
	if (GamePlayFlg == true) {
		DrawRotaGraph(x + STAGE_LEFT_SPACE, y, 1, 0, nowdraw, TRUE);
		if (existhome == true && existedanim == true) {
			DrawString(800, 300, "ƒsƒ“ƒNŠO", 0x0f0500);
		}
		DrawBox(targetxpoint+STAGE_LEFT_SPACE, targetypoint, targetxpoint + DOT_SIZE+ STAGE_LEFT_SPACE, targetypoint + DOT_SIZE, 0xff0000,true);
	}
}

void Enemy_Pink::TargetRocation(float x, float y, int dic)
{


	switch (dic)
	{
	case 1:
		 targetypoint = y + DOT_SIZE* -3;
		 targetxpoint = x;
		break;
	case 2:
		targetypoint = y;
		targetxpoint = x+ DOT_SIZE* 3;
		break;
	case 3:
		targetypoint = y + DOT_SIZE * 3;
		targetxpoint = x;
		break;
	case 4:
		targetypoint = y;
		targetxpoint = x + DOT_SIZE * -3;
		break;
	default:
		targetypoint = y;
		targetxpoint = x;
		break;
	}
}
