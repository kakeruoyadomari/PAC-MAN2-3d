#pragma once
#include"DxLib.h"
#include"Stage.h"
#include <math.h>

class Object
{
protected:
	float x;		//ç¿ïWX
	float y;		//ç¿ïWY
	int radius;		//îºåa
	int int_x;
	int int_y;
	static Stage* stage;


public:

	virtual void UpDate() = 0;
	virtual void Animaition() = 0;
	virtual void Draw() const = 0;
	int GetX() const { return x; }
	int GetY() const { return y; }
	int GetRadius() const { return radius; }
	bool CheckHitWall(float f_x, float f_y, int);
};

//float absf(void* num);
bool CheckHitPlayer_Esa(Object* player, Object* esa);
