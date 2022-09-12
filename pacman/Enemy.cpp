#include"Enemy.h"
#include"Enemy_Red.h"
#include"Stage.h"
#include"math.h"

bool Enemy::trackFlg=false;


bool Enemy::CheckHitPlayer(int ex, int xy)
{
	return false;
}

Enemy::Enemy()
{
	animeFlg = false;
	speed = 0;

	ijikeimage1[0] = LoadGraph("images/黒1.png");
	ijikeimage1[1] = LoadGraph("images/黒2.png");
	ijikeimage2[0] = LoadGraph("images/白1.png");
	ijikeimage2[1] = LoadGraph("images/白2.png");

	medamaimage[0] = LoadGraph("images/目1.png");
	medamaimage[1] = LoadGraph("images/目2.png");
	medamaimage[2] = LoadGraph("images/目3.png");
	medamaimage[3] = LoadGraph("images/目4.png");

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



int Enemy::GetDistance(int from_x, int from_y, int to_x, int to_y)
{
	int cx = from_x - to_x;
	int cy = from_y - to_y;

	if (cx < 0) cx *= -1;
	if (cy < 0) cy *= -1;

	// 推定移動コストを計算
	return cx + cy;
}

void Enemy::MoveRocation(int px, int py,int ex,int ey, int* dicX, int* dicY,int* dic)
{
	*dicX = 0;
	*dicY = 0;
	*dic = 0;

	if (min(abs(px*ex),abs(py*ey))==abs(px*ex)) {
		if (min(ey, py) == ey) {
			*dicY = 1;
			*dic = 3;
		}
		else {
			*dicY = -1;
			*dic = 1;
		}
	}
	else if(min(py,px)==py) {
		if (min(ex, px) == ex) {
			*dicX = 1;
			*dic = 2;
		}
		else {
			*dicX = -1;
			*dic = 4;
		}
	}
}
