#pragma once
#include"DxLib.h"


class Object
{
protected:
	int x;		//À•WX
	int y;		//À•WY
	int radius;		//”¼Œa

public:
	virtual void UpDate() = 0;
	virtual void Animaition() = 0;
	virtual void Draw() const = 0;
	int GetX() const { return x; }
	int GetY() const { return y; }
	int GetRadius() const { return radius; }
};

