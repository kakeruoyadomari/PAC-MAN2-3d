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

	if (min(py, ey) == py && CheckHitWall(ex, ey, 1) == false) {
		*dic = 1;
		*dicY = -1;
	}
	else if (min(py, ey) == ey && CheckHitWall(ex, ey, 3) == false) {
		*dic = 3;
		*dicY = 1;
	}
	else if (min(px, ex) == px && CheckHitWall(ex, ey, 4) == false) {
		*dic = 4;
		*dicX = -1;
	}
	else if (CheckHitWall(ex, ey, 3) == false) {
		*dic = 2;
		*dicX = 1;
	}


}

Enemy::Enemy()
{
	animeFlg = false;
	speed = 0;

	ijikeimage1[0] = LoadGraph("images/��1.png");
	ijikeimage1[1] = LoadGraph("images/��2.png");
	ijikeimage2[0] = LoadGraph("images/��1.png");
	ijikeimage2[1] = LoadGraph("images/��2.png");

	medamaimage[0] = LoadGraph("images/��1.png");
	medamaimage[1] = LoadGraph("images/��2.png");
	medamaimage[2] = LoadGraph("images/��3.png");
	medamaimage[3] = LoadGraph("images/��4.png");

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