#pragma once
#include"DxLib.h"
#include"Stage.h"
#include<math.h>

class Object
{
protected:
	float x;		//ç¿ïWX
	float y;		//ç¿ïWY
	int int_x;
	int int_y;
	int radius=18;		//îºåa

	static Stage* stage;

	static int* stageCount;

	static bool GamePlayFlg;

	static bool GameClearFlg;

	static const int RoundSpeed;

public:



	virtual void UpDate() = 0;
	virtual void Animaition() = 0;
	virtual void Draw() const = 0;
	 float GetX() const { return x; }
	 float GetY() const { return y; }
	 int GetRadius() const { return radius; }

	 bool GetClearFlg() { return GameClearFlg; }

	bool ToggleFlg(bool flg) { flg = !(flg); return flg; }

	void ToggleClearFlg() { GameClearFlg = !(GameClearFlg); }


	bool CheckHitWall(int, int, int);
	bool CheckHitPlayer(Object* player,Object* enemy);

};

//float absf(void* num);
