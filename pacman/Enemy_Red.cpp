#include "Enemy_Red.h"

Enemy_Red::Enemy_Red(Stage*data,Object*data2)
{
	image1[0] = LoadGraph("images/�ԓG1.png");
	image1[1] = LoadGraph("images/�ԓG5.png");
	image2[0] = LoadGraph("images/�ԓG2.png");
	image2[1] = LoadGraph("images/�ԓG6.png");
	image3[0] = LoadGraph("images/�ԓG3.png");
	image3[1] = LoadGraph("images/�ԓG7.png");
	image4[0] = LoadGraph("images/�ԓG4.png");
	image4[1] = LoadGraph("images/�ԓG8.png");

	nowway = ENEMY_NORMAL_LEFT;

	stage = data;
	player = data2;
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

	GetMousePoint(&x, &y);

	BlockX = x / 22;
	BlockY = y / 22;

	Animaition();

	if (CheckHitWall(x, y, nowway) == true) {
		nowdraw = medamaimage[0];
		HitFlg = true;
	}
	else {
		HitFlg = false;
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
		switch (nowway)
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
