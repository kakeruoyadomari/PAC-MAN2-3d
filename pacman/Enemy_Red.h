#pragma once
#include "Enemy.h"

class Enemy_Red : public Enemy
{
private:
	int spart1 = 0;
	int spart2 = 0;
	int SpartSpeed=0;
public:
	Enemy_Red(Player* plyr,int *data);

	int GetSpart() { return spart1; }
	int GetSpart2() { return spart2; }

	void ChangeSpartSpeed() { SpartSpeed+=float(1)/float(16); }

	void UpDate() override;
	void Animaition() override;
	void Draw() const override;
	void TargetRocation(float, float, int) override;

};
