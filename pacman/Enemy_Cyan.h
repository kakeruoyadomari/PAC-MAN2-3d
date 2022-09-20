#pragma once
#include "Enemy.h"
class Enemy_Cyan : public Enemy
{
public:
	Enemy_Cyan();

	void UpDate() override;
	void Animaition() override;
	void Draw() const override;
	void TargetRocation(float, float, int) override;

};

