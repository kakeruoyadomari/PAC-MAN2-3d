#include"DxLib.h"
#include "Object.h"
#include<math.h>

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