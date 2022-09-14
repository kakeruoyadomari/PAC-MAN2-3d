#pragma once
#include"DxLib.h"
#include"Stage.h"


class Object
{
protected:
	int x;		//ç¿ïWX
	int y;		//ç¿ïWY
	int radius;		//îºåa

	static Stage* stage;


public:
	virtual void UpDate() = 0;
	virtual void Animaition() = 0;
	virtual void Draw() const = 0;
	int GetX() const { return x; }
	int GetY() const { return y; }
	int GetRadius() const { return radius; }

	bool CheckHitWall(int, int, int);
};

//float absf(void* num);
bool CheckHitPlayer_Esa(Object* player, Object* esa);
