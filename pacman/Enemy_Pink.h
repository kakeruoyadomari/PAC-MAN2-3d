#pragma once
#include "Enemy.h"
class Enemy_Pink :
    public Enemy
{
public:
	Enemy_Pink();

	void UpDate() override;
	void Animaition() override;
	void Draw() const override;
	void TargetRocation(float, float, int) override;
};

