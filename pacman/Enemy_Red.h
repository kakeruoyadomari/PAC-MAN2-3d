#pragma once
#include "Enemy.h"

class Enemy_Red : public Enemy
{
private:

public:
	Enemy_Red(Player* plyr,int *data);

	void UpDate() override;
	void Animaition() override;
	void Draw() const override;
	void TargetRocation(float, float, int) override;

};
