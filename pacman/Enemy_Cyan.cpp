#include "Enemy_Cyan.h"

Enemy_Cyan::Enemy_Cyan()
{
	image1[0] = LoadGraph("images/Cyan1.png");
	image1[1] = LoadGraph("images/Cyan5.png");
	image2[0] = LoadGraph("images/Cyan2.png");
	image2[1] = LoadGraph("images/Cyan6.png");
	image3[0] = LoadGraph("images/Cyan3.png");
	image3[1] = LoadGraph("images/Cyan7.png");
	image4[0] = LoadGraph("images/Cyan4.png");
	image4[1] = LoadGraph("images/Cyan8.png");


	nowway = ENEMY_NORMAL_LEFT;
	x = 12 * DOT_SIZE+11;
	y = 15 * DOT_SIZE - 11;

	enemydic.direction = 1;
	enemydic.x_direction = 0;
	enemydic.y_direction = -1;

	nowdraw = image3[0];
}

void Enemy_Cyan::UpDate()
{

	int_x = roundf(x);
	int_y = roundf(y);


	if (x < 4) {
		x = 630;
	}
	else if (x > 630) {
		x = 4;
	}

	if (existhome == false && existedanim == false) {

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
	else if (existhome == true && existedanim == false) {
		ExistAnime(this);

		x += 0.5 * enemydic.x_direction;
		y += 0.5 * enemydic.y_direction;

		if (int_y == 12 * DOT_SIZE - 10) {
			existedanim = true;
			y += 0.5;
			x -= 11;
		}
	}
	else if (existedanim == true) {

		if (GamePlayFlg == true) {
			Animaition();
			if (trackcount++ / 660 == 1) {
				trackFlg = ToggleFlg(trackFlg);
				trackcount = 0;
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

void Enemy_Cyan::Animaition()
{
	animcount++;

	if (animcount % 10 == 0) {
		nowflg = ToggleFlg(nowflg);
		animcount = 1;
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

void Enemy_Cyan::Draw() const
{
	if (GamePlayFlg == true) {
		DrawRotaGraph(x + STAGE_LEFT_SPACE, y, 1, 0, nowdraw, TRUE);
		if (existhome == true && existedanim == true) {
			DrawString(800, 400, "ƒVƒAƒ“ŠO", 0x00050f);
		}
		DrawBox(targetxpoint + STAGE_LEFT_SPACE, targetypoint, targetxpoint + DOT_SIZE + STAGE_LEFT_SPACE, targetypoint + DOT_SIZE, 0x0000ff, true);
	}
}

void Enemy_Cyan::TargetRocation(float x, float y, int dic)
{
	float EX = enemy_red->GetX();
	float EY = enemy_red->GetY();

	targetxpoint = roundf( x + (x - EX)*2);
	targetypoint = roundf( y + (y -EY)*2);
}

