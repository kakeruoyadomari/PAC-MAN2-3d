#include"DxLib.h"
#include "Object.h"
#include<math.h>
#include"Player.h"
Stage* Object::stage = 0;

//float absf(void* num)
//{
//	if (*(float*)num < 0)
//	{
//		*(float*)num = *(float*)num * -1;
//	}
//	return *(float*)num;
//}

bool CheckHitPlayer_Esa(Object* player, Object* esa)
{
	if (esa == nullptr)
	{
		return FALSE;
	}
	float rangeX = player->GetX() - esa->GetX();
	float rangeY = player->GetY() - esa->GetY();
	double range = sqrt(rangeX * rangeX + rangeY * rangeY);
	double sum_radius = double(player->GetRadius()) + double(esa->GetRadius());
	
	if (range <= sum_radius)
	{
		return true;
	}


	return false;
}

bool Object::CheckHitWall(float f_x, float f_y, int dir)
{

	int x = 0;
	int y=0;

	x = roundf(f_x);
	y = roundf(f_y);

	int dx = 0;
	int dy = 0;
	int wall = 0;
	int ex = 0;
	int ey = 0;



	switch (dir)
	{
	case 1:
		dx = 0; dy = -1;
		ex = x / DOT_SIZE;
		ey = (y + 10) / DOT_SIZE;
		break;
	case 2:
		dx = 1; dy = 0;
		ex = (x - 11) / DOT_SIZE;
		ey = y / DOT_SIZE;
		break;
	case 3:
		dx = 0; dy = 1;
		ex = x / DOT_SIZE;
		ey = (y - 11) / DOT_SIZE;
		break;
	case 4:
		dx = -1; dy = 0;
		ex = (x + 10) / DOT_SIZE;
		ey = y / DOT_SIZE;
		break;
	default:
		dx = 0; dy = 0;
		ex = x / DOT_SIZE;
		ey = y / DOT_SIZE;
		break;
	}

	if (ex < STAGE_WIDTH * 2 && ey < STAGE_HEIGHT) {
		wall = stage->GetStageData(ex + dx, ey + dy);
	}

	if (wall == 1) {
		return true;
	}
	else {
		return false;
	}
}
