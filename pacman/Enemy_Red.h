#pragma once
#include "Enemy.h"

class Enemy_Red : public Enemy
{
private:
	int BlockX;
	int BlockY;

public:
	Enemy_Red();

	void UpDate() override;
	void Animaition() override;
	void Draw() const override;
};
