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