#pragma once
#include "Enemy.h"

class Enemy_Red : public Enemy
{
private:
	int BlockX;
	int BlockY;

public:
	Enemy_Red(Stage*data,Object*data2);

	void UpDate() override;
	void Animaition() override;
	void Draw() const override;
};
