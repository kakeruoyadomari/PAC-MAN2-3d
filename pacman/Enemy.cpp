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

	ijikeimage1[0] = LoadGraph("images/•1.png");
	ijikeimage1[1] = LoadGraph("images/•2.png");
	ijikeimage2[0] = LoadGraph("images/”’1.png");
	ijikeimage2[1] = LoadGraph("images/”’2.png");

	medamaimage[0] = LoadGraph("images/–Ú1.png");
	medamaimage[1] = LoadGraph("images/–Ú2.png");
	medamaimage[2] = LoadGraph("images/–Ú3.png");
	medamaimage[3] = LoadGraph("images/–Ú4.png");

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