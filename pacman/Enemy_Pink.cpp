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
		Animaition();
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
					NowGameFlg = false;
				}
			}
			else if (enemyijike == true && backflg == false){
				if (int_x % DOT_SIZE == 11 && int_y % DOT_SIZE == 11) {
					RunAway(player->GetX(), player->GetY(),
						int_x, int_y, &enemydic.direction, &enemydic.x_direction, &enemydic.y_direction);
					x += ijikespeed * enemydic.x_direction;
					y += ijikespeed * enemydic.y_direction;
				}
				else {
					x += ijikespeed * enemydic.x_direction;
					y += ijikespeed * enemydic.y_direction;
				}

				ijiketimer++;

				if (ijiketimer == ijikecount) {
					enemyijike = false;
					ijiketimer = 0;
				}

				if (CheckHitPlayer(player, this) == true && NowGameFlg == true) {
					int_x = int_x / DOT_SIZE * DOT_SIZE - 11;
					int_y = int_y / DOT_SIZE * DOT_SIZE - 11;
					backflg = true;
				}

			}
			else if (backflg == true) {
				if ((int_x != 14 * DOT_SIZE - 11 || int_y != 12 * DOT_SIZE - 11) && enemyijike == true) {
					if (int_x % DOT_SIZE == 11 && int_y % DOT_SIZE == 11) {
						Rocation(14 * DOT_SIZE-11, 12 * DOT_SIZE-11,
							int_x, int_y, &enemydic.direction, &enemydic.x_direction, &enemydic.y_direction);

						x += backspeed * enemydic.x_direction;
						y += backspeed * enemydic.y_direction;
					}
					else {
						x = int_x - 1 * enemydic.x_direction;
						y = int_y - 1 * enemydic.y_direction;
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
void Enemy_Pink::Animaition()
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

void Enemy_Pink::Draw() const
{
	if (NowGameFlg == true) {
		DrawRotaGraph(x + STAGE_LEFT_SPACE, y, 1, 0, nowdraw, TRUE);
		if (existhome == true && existedanim == true) {
			DrawString(800, 300, "?s???N?O", 0x0f0500);
		}
	}
}

void Enemy_Pink::TargetRocation(float x, float y, int dic)
{

	if (trackFlg == false) {

		targetxpoint = 24 * DOT_SIZE;
		targetypoint = 26 * DOT_SIZE;
	}
	else {
		switch (dic)
		{
		case 1:
			targetypoint = y + DOT_SIZE * -3;
			targetxpoint = x;
			break;
		case 2:
			targetypoint = y;
			targetxpoint = x + DOT_SIZE * 3;
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
	
}
