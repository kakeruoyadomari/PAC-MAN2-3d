#include"Enemy.h"
#include"Enemy_Red.h"
#include"Stage.h"
#include"math.h"

bool Enemy::trackFlg=false;
Player* Enemy::player = 0;
Enemy* Enemy::enemy_red = 0;
bool Enemy::HitFlg = false;
int Enemy::hometimer = hometimer = 22;



Enemy::Enemy()
{
	animeFlg = false;
	speed = 0;

	ijikeimage1[0] = LoadGraph("images/Black1.png");
	ijikeimage1[1] = LoadGraph("images/Black2.png");
	ijikeimage2[0] = LoadGraph("images/White1.png");
	ijikeimage2[1] = LoadGraph("images/White2.png");

	medamaimage[0] = LoadGraph("images/Eye1.png");
	medamaimage[1] = LoadGraph("images/Eye2.png");
	medamaimage[2] = LoadGraph("images/Eye3.png");
	medamaimage[3] = LoadGraph("images/Eye4.png");

	enemydic.direction = 0;
	enemydic.x_direction = 0;
	enemydic.y_direction = 0;

}

void Enemy::ExistAnime(Enemy* data)
{
	if (data->GetX() > 14*DOT_SIZE) {
		data->SetDirection(4);
		data->SetXDirection(-1);
		data->SetYDirection(0);

	}
	else if (data->GetX() < 14 * DOT_SIZE) {
		data->SetDirection(2);
		data->SetXDirection(1);
		data->SetYDirection(0);

	}
	else {
		data->SetDirection(1);
		data->SetXDirection(0);
		data->SetYDirection(-1);
	}
	Animaition();
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
		gx = abs(px/DOT_SIZE - ex/DOT_SIZE);
		gy = abs(py/DOT_SIZE - ey/DOT_SIZE);
		gz = ex / DOT_SIZE - px/DOT_SIZE;
		break;
	case 2:
		gy = abs(px / DOT_SIZE - ex / DOT_SIZE);
		gx = abs(py / DOT_SIZE - ey / DOT_SIZE);
		gz = ey / DOT_SIZE - py / DOT_SIZE;
		break;
	case 3:
		gx = abs(px / DOT_SIZE - ex / DOT_SIZE);
		gy = abs(py / DOT_SIZE - ey / DOT_SIZE);
		gz = px / DOT_SIZE - ex / DOT_SIZE;
		break;
	case 4:
		gy = abs(px / DOT_SIZE - ex / DOT_SIZE);
		gx = abs(py / DOT_SIZE - ey / DOT_SIZE);
		gz = py / DOT_SIZE - ey / DOT_SIZE;
		break;
	default:
		break;
	}

	if (CheckHitWall(ex, ey, *dic) == false) {
		if (CheckHitWall(ex, ey, localdic1) == false &&min(gx,gy)==gy&& gz > 0) {
		
			*dic = localdic1;

		}
		else if (CheckHitWall(ex, ey, localdic2) == false && min(gx, gy) == gy&&gz<0) {

			*dic = localdic2;
		}
		else {
			*dic = *dic;
		}
	}
	else {
		if (CheckHitWall(ex, ey, localdic1) == false && min(gx, gy) == gy && gz > 0) {
			*dic = localdic1;
		}
		else if (CheckHitWall(ex, ey, localdic2) == false && min(gx, gy) == gy && gz < 0) {
			*dic = localdic2;
		}
		else if (CheckHitWall(ex, ey, localdic1) == false && gz > 0) {
			*dic = localdic1;
		}
		else if (CheckHitWall(ex, ey, localdic2) == false && gz < 0) {
			*dic = localdic2;
		}
		else if (CheckHitWall(ex, ey, localdic1) == false) {
			*dic = localdic1;
		}
		else {
			*dic = localdic2;
		}
	}

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
