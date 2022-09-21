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
	if (x < 11) {
		x = 615;
	}
	else if (x > 615) {
		x = 11;
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

		if (NowGameFlg == true) {
			Animaition();

			TargetRocation(player->GetX(), player->GetY(), player->GetDirection());

			if (enemyijike == false && backflg == false) {

				if (trackFlg == true) {

					if (int_x % DOT_SIZE == 11 && int_y % DOT_SIZE == 11) {
						Rocation(player->GetX(), player->GetY(),
							int_x, int_y, &enemydic.direction, &enemydic.x_direction, &enemydic.y_direction);
						x = int_x;
						y = int_y;
						x += speed * enemydic.x_direction;
						y += speed * enemydic.y_direction;
					}
					else {
						x += speed * enemydic.x_direction;
						y += speed * enemydic.y_direction;
					}
				}
				else {
					if (int_x % DOT_SIZE == 11 && int_y % DOT_SIZE == 11) {

						Rocation(targetxpoint, targetypoint,
							int_x, int_y, &enemydic.direction, &enemydic.x_direction, &enemydic.y_direction);
						x = int_x;
						y = int_y;
						x += speed * enemydic.x_direction;
						y += speed * enemydic.y_direction;
					}
					else {
						x += speed * enemydic.x_direction;
						y += speed * enemydic.y_direction;
					}

				}

				if (CheckHitPlayer(player, this) == true && NowGameFlg == true) {
					//NowGameFlg = false;
				}
			}
			else if (enemyijike == true && backflg == false) {
				if (int_x % DOT_SIZE == 11 && int_y % DOT_SIZE == 11) {
					RunAway(player->GetX(), player->GetY(),
						int_x, int_y, &enemydic.direction, &enemydic.x_direction, &enemydic.y_direction);
					x += ijikespeed * enemydic.x_direction;
					y += ijikespeed * enemydic.y_direction;
				}
				else {

					x = int_x;
					y = int_y;
					x += ijikespeed * enemydic.x_direction;
					y += ijikespeed * enemydic.y_direction;
				}

				ijiketimer++;

				if (ijiketimer == ijikecount) {
					enemyijike = false;
					ijiketimer = 0;
				}

				if (CheckHitPlayer(player, this) == true && NowGameFlg == true) {
					backflg = true;
				}

			}
			else if (backflg == true) {
				if ((int_x != 14 * DOT_SIZE - 11 || int_y != 12 * DOT_SIZE - 11) && enemyijike == true) {
					if (int_x % DOT_SIZE == 11 && int_y % DOT_SIZE == 11) {
						Rocation(14 * DOT_SIZE, 12 * DOT_SIZE,
							int_x, int_y, &enemydic.direction, &enemydic.x_direction, &enemydic.y_direction);
						x = int_x;
						y = int_y;
						x += backspeed * enemydic.x_direction;
						y += backspeed * enemydic.y_direction;
					}
					else {
						x += backspeed * enemydic.x_direction;
						y += backspeed * enemydic.y_direction;
					}
				}
				else if (enemyijike == true) {

					x = 14 * DOT_SIZE;
					y = 15 * DOT_SIZE;
					enemyijike = false;

					enemydic.direction = 1;
				}
				else if (backflg == true && enemyijike == false && enemydic.direction == 1) {
					ExistAnime(this);

					x += 0.5 * enemydic.x_direction;
					y += 0.5 * enemydic.y_direction;

					if (int_y == 12 * DOT_SIZE - 11) {
						backflg = false;
						y += 0.5;
						x -= 11;
					}
				}
			}
		}
		else {

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

	if (enemyijike != true) {
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
	else if (enemyijike == true && backflg == false) {
		if (nowflg2 == false) {
			if (nowflg != true) {
				nowdraw = ijikeimage1[0];
			}
			else {
				nowdraw = ijikeimage1[1];
			}
		}
		else {
			if (nowflg != true) {
				nowdraw = ijikeimage2[0];
			}
			else {
				nowdraw = ijikeimage2[1];
			}
		}

		if (ijiketimer >= ijikecount - ONE_SECOND - 20 && ijiketimer % 10 == 0) {
			nowflg2 = !(nowflg2);
		}

	}
	else if (backflg == true) {
		switch (enemydic.direction)
		{
		case ENEMY_NORMAL_UP:
			nowdraw = medamaimage[2];
			break;
		case ENEMY_NORMAL_RIGHT:
			nowdraw = medamaimage[1];
			break;
		case ENEMY_NORMAL_DOWN:
			nowdraw = medamaimage[3];
			break;
		case ENEMY_NORMAL_LEFT:
			nowdraw = medamaimage[0];
			break;
		default:
			break;
		}
	}
}

void Enemy_Cyan::Draw() const
{
	if (NowGameFlg == true) {
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

	if (trackFlg == false) {

		targetxpoint = 24 * DOT_SIZE;
		targetypoint = 26 * DOT_SIZE;
	}
	else {
		targetxpoint = roundf(x + (x - EX) * 2);
		targetypoint = roundf(y + (y - EY) * 2);
	}


}

