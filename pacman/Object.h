#pragma once
#include"DxLib.h"


class Object
{
private:
	int x = 0;
	int y = 0;
	int h = 0;
	int w = 0;
	int radius = 0;

public:
	virtual void UpDate() = 0;
	virtual void Animaition() = 0;
	virtual void Draw() const = 0;

};

