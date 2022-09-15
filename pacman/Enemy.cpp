#include"Enemy.h"
#include"Enemy_Red.h"
#include"Stage.h"
#include"math.h"

bool Enemy::trackFlg=false;


bool Enemy::CheckHitPlayer(int ex, int xy)
{
	return false;
}

void Enemy::Rocation(int px, int py, int ex, int ey, int* dic, int* dicX, int* dicY)
{
	*dicX = 0;
	*dicY = 0;

	int localdic1 = 0;
	int localdic2 = 0;

	int gx = 0;
	int gy = 0;
	int gz = 0;
	int gl = 0;


	if (*dic == 1) {
		localdic1 = 4;
		localdic2 = 2;
	}
	else if (*dic == 4) {
		localdic1 = 3;
		localdic2 = 1;
	}
	else {
		localdic1 = *dic - 1;
		localdic2 = *dic + 1;
	}
	switch (*dic)
	{
	case 1:
		gx = abs(px - ex);
		gy = abs(py - ey);
		gz = px - ex;
		break;
	case 2:
		gy = abs(px - ex);
		gx = abs(py - ey);
		gz = py - ey;
		break;
	case 3:
		gx = abs(px - ex);
		gy = abs(py - ey);
		gz = px - ex;
		break;
	case 4:
		gy = abs(px - ex);
		gx = abs(py - ey);
		gz = py - ey;
		break;
	default:
		break;
	}

	if (CheckHitWall(ex, ey, *dic) == false) {
		
		if (CheckHitWall(ex, ey, localdic1) == false && min(gx,gy)==gx&&gz>0) {
			switch (localdic1)
			{
			case 1:
				*dicY = -1;
				break;
			case 2:
				*dicX = 1;
				break;
			case 3:
				*dicY = 1;
				break;
			case 4:
				*dicX = -1;
				break;
			default:
				*dicX = 0;
				*dicY = 0;
				break;
			}
			*dic = localdic1;

		}
		else if (CheckHitWall(ex, ey, localdic2) == false) {
			switch (localdic2)
			{
			case 1:
				*dicY = -1;
				break;
			case 2:
				*dicX = 1;
				break;
			case 3:
				*dicY = 1;
				break;
			case 4:
				*dicX = -1;
				break;
			default:
				*dicX = 0;
				*dicY = 0;
				break;
			}

			*dic = localdic2;
		}
		else {
			switch (*dic)
			{
			case 1:
				*dicY = -1;
				break;
			case 2:
				*dicX = 1;
				break;
			case 3:
				*dicY = 1;
				break;
			case 4:
				*dicX = -1;
				break;
			default:
				*dicX = 0;
				*dicY = 0;
				break;
			}
		}
	}
	else {
		if (CheckHitWall(ex, ey, localdic1) == false && min(gx, gy) == gx && gz < 0) {
			switch (localdic1)
			{
			case 1:
				*dicY = -1;
				break;
			case 2:
				*dicX = 1;
				break;
			case 3:
				*dicY = 1;
				break;
			case 4:
				*dicX = -1;
				break;
			default:
				*dicX = 0;
				*dicY = 0;
				break;
			}
			*dic = localdic1;

		}else if (CheckHitWall(ex, ey, localdic2) == false && min(gx, gy) == gx && gz > 0) {
			switch (localdic2)
			{
			case 1:
				*dicY = -1;
				break;
			case 2:
				*dicX = 1;
				break;
			case 3:
				*dicY = 1;
				break;
			case 4:
				*dicX = -1;
				break;
			default:
				*dicX = 0;
				*dicY = 0;
				break;
			}

			*dic = localdic2;
		}
		else if(CheckHitWall(ex, ey, localdic1) == false){
			switch (localdic1)
			{
			case 1:
				*dicY = -1;
				break;
			case 2:
				*dicX = 1;
				break;
			case 3:
				*dicY = 1;
				break;
			case 4:
				*dicX = -1;
				break;
			default:
				*dicX = 0;
				*dicY = 0;
				break;
			}
			*dic = localdic1;
		}
		else if(CheckHitWall(ex, ey, localdic2) == false){
			switch (localdic2)
			{
			case 1:
				*dicY = -1;
				break;
			case 2:
				*dicX = 1;
				break;
			case 3:
				*dicY = 1;
				break;
			case 4:
				*dicX = -1;
				break;
			default:
				*dicX = 0;
				*dicY = 0;
				break;
			}

			*dic = localdic2;
		}
		else {
			*dic = *dic;

		}
	}

}

int Enemy::RocationScore(int ex, int ey, int px, int py, int dic)
{

	//if (min(py, ey) == py) {
	//	*dic = 1;
	//	*dicY = -1;
	//}
	//else if (min(py, ey) == ey) {
	//	*dic = 3;
	//	*dicY = 1;
	//}
	//else if (min(px, ex) == px) {
	//	*dic = 4;
	//	*dicX = -1;
	//}
	//else {
	//	*dic = 2;
	//	*dicX = 1;
	//}

	return 0;
}


Enemy::Enemy()
{
	animeFlg = false;
	speed = 0;

	ijikeimage1[0] = LoadGraph("images/çï1.png");
	ijikeimage1[1] = LoadGraph("images/çï2.png");
	ijikeimage2[0] = LoadGraph("images/îí1.png");
	ijikeimage2[1] = LoadGraph("images/îí2.png");

	medamaimage[0] = LoadGraph("images/ñ⁄1.png");
	medamaimage[1] = LoadGraph("images/ñ⁄2.png");
	medamaimage[2] = LoadGraph("images/ñ⁄3.png");
	medamaimage[3] = LoadGraph("images/ñ⁄4.png");

}

void Enemy::AStar(int ex, int ey, int px, int py)
{
	int a = 0;
	int b = 0;
	int c = 0;
	float sq = 0;


	a = ex - px;
	b = ey - py;
	sq = sqrt(a * a + b * b);


}