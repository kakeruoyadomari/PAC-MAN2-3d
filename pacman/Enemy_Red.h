#pragma once
#include "Enemy.h"
class Enemy_Red : public Enemy
{
public:
	void UpDate() override;
	void Animaition() override;
	void Draw() const override;
};

