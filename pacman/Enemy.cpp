#include"Enemy.h"
#include"Enemy_Red.h"
#include"Stage.h"

Enemy::Enemy()
{
	animeFlg = false;

	ijikeimage1[0] = LoadGraph("images/��1.png");
	ijikeimage1[1] = LoadGraph("images/��2.png");
	ijikeimage2[0] = LoadGraph("images/��1.png");
	ijikeimage2[1] = LoadGraph("images/��2.png");

	medamaimage[0] = LoadGraph("images/��1.png");
	medamaimage[1] = LoadGraph("images/��2.png");
	medamaimage[2] = LoadGraph("images/��3.png");
	medamaimage[3] = LoadGraph("images/��4.png");
}

