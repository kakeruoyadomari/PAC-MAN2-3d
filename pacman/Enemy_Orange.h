#pragma once
#include "Enemy.h"
class Enemy_Orange :
    public Enemy
{
private:
	bool randomflg;
public:
	Enemy_Orange();

	void UpDate() override;
	void Animaition() override;
	void Draw() const override;
	void TargetRocation(float, float, int) override;

};

