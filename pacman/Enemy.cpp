#include"Enemy.h"
#include"Enemy_Red.h"
#include"Stage.h"
#include"math.h"

bool Enemy::trackFlg=false;

bool Enemy::CheckHitWall(int ex, int ey,int dir)
{
	int x = 0;
	int y = 0;
	int dx = 0;
	int dy = 0;
	int wall = 0;

	switch (dir)
	{
	case ENEMY_NORMAL_UP:
		dx = 0; dy = -1;
		break;
	case ENEMY_NORMAL_RIGHT:
		dx = 1; dy = 0;
		break;
	case ENEMY_NORMAL_DOWN:
		dx = 0; dy = 1;
		break;
	case ENEMY_NORMAL_LEFT:
		dx = -1; dy = 0;
		break;
	default:
		dx = 0; dy = 0;
		break;
	}

	x = ex / DOT_SIZE;
	y = ey / DOT_SIZE;

	if (x < STAGE_WIDTH*2 || y < STAGE_HEIGHT) {
		wall = stage->GetStageData(x + dx, y + dy);
		//wall = stage->GetStageData(x , y);
	}

	if (wall == 1) {
		return true;
	}
	else{
		return false;
	}
}

bool Enemy::CheckHitPlayer(int ex, int xy)
{
	return false;
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