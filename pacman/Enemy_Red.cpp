#include "Enemy_Red.h"

Enemy_Red::Enemy_Red(Stage*data,Object*data2)
{
	image1[0] = LoadGraph("images/Ô“G1.png");
	image1[1] = LoadGraph("images/Ô“G5.png");
	image2[0] = LoadGraph("images/Ô“G2.png");
	image2[1] = LoadGraph("images/Ô“G6.png");
	image3[0] = LoadGraph("images/Ô“G3.png");
	image3[1] = LoadGraph("images/Ô“G7.png");
	image4[0] = LoadGraph("images/Ô“G4.png");
	image4[1] = LoadGraph("images/Ô“G8.png");

	nowway = ENEMY_NORMAL_LEFT;

	stage = data;
	player = data2;

	x = 14*DOT_SIZE-11;
	y = 14*DOT_SIZE-11;

	enemydic.direction = 0;
	enemydic.x_direction = 0;
	enemydic.y_direction = 0;

}

void Enemy_Red::UpDate()
{
	if (animeFlg == true) {
		Animaition();
		animeFlg = false;
	}
	else {

	}

	if (CheckHitKey(KEY_INPUT_0) == true) {
		nowway = ENEMY_NORMAL_LEFT;
	}
	else if (CheckHitKey(KEY_INPUT_1) == true) {
		nowway = ENEMY_NORMAL_DOWN;
	}
	else if (CheckHitKey(KEY_INPUT_2) == true) {
		nowway = ENEMY_NORMAL_RIGHT;
	}
	else if (CheckHitKey(KEY_INPUT_3) == true) {
		nowway = ENEMY_NORMAL_UP;
	}
	else if (CheckHitKey(KEY_INPUT_4) == true) {
		ijike = ToggleFlg(ijike);
	}

	BlockX = x / 22;
	BlockY = y / 22;

	Animaition();

	if (x % DOT_SIZE == 11 && y % DOT_SIZE == 11) {
		MoveRocation( player->GetX(), player->GetY(), x, y, &enemydic.x_direction, &enemydic.y_direction, &enemydic.direction);
		x += enemydic.x_direction;
		y += enemydic.y_direction;
	}
	else
	{
		x += enemydic.x_direction;
		y += enemydic.y_direction;
	}
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
	DrawRotaGraph(x, y, 0.5,0,nowdraw, TRUE);

	if (HitFlg == true) {
		DrawString(1000, 300, "Hit", 0x00ffff);

	}

	DrawFormatString(800, 600, 0xff00ff, "%d,%d",BlockX, BlockY);
	//DrawBox(selectrocation[0] * DOT_SIZE, selectrocation[1] * DOT_SIZE, selectrocation[0] * DOT_SIZE + DOT_SIZE, selectrocation[1] * DOT_SIZE + DOT_SIZE, 0xff0000, TRUE);

	
}

//void Enemy_Red::SelectRocation()
//{
//	int selectx = 0;
//	int selecty = 0;
//
//	if (CheckHitKey(KEY_INPUT_P) == true) {
//		selectflg = false;
//	}
//
//	while (selectflg!=true)
//	{
//		nowselect = GetRand(812)+29;
//
//		selecty = nowselect / 28;
//		selectx = nowselect % 28;
//
//		if (stage->GetStageData(selectx, selecty) == 0) 
//		{
//			selectrocation[0] = selectx;
//			selectrocation[1] = selecty;
//			selectflg = true;
//
//		}
//		else {
//			continue;
//		}
//	}
//}
