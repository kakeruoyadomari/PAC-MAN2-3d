#pragma once
#include"DxLib.h"


class Object
{
private:
	int x=0;

public:
	virtual void UpData();
	virtual void Draw() const;

};

