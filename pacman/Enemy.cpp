#include"Enemy.h"

Enemy::Enemy()
{
	animeFlg = false;

	ijikeimage[0] = LoadGraph("images/•1.png");
	ijikeimage[1] = LoadGraph("images/•2.png");
	ijikeimage[2] = LoadGraph("images/”’1.png");
	ijikeimage[3] = LoadGraph("images/”’2.png");

	medamaimage[0] = LoadGraph("images/–Ú1.png");
	medamaimage[1] = LoadGraph("images/–Ú2.png");
	medamaimage[2] = LoadGraph("images/–Ú3.png");
	medamaimage[3] = LoadGraph("images/–Ú4.png");
}
