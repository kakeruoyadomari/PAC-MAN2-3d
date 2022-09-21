#include "Esa.h"
#include "Player.h"
#include "Object.h"

int ESA::ResidueEsa = 0;
ESA::ESA(int X, int Y, int EsaType)
{		
	x = X;
	y = Y;
	Esaflg = TRUE;
	Flashflg = true;
	EsaScore = EsaType * 10;
	Type = EsaType;
	radius = 2;

	ResidueEsa++;
	
	//EsaImg = 0;
}

ESA::ESA(int FruitsX, int FruitsY, int EsaType, int FruitsType, int FruitsScore)
{
	x = FruitsX;
	y = FruitsY;
	Flashflg = true;
	Esaflg = false;
	FruitsType = FruitsType;
	EsaScore = 10;
	Type = EsaType;
	radius = 2;
}

ESA::~ESA()
{
	if (Type != 2)
	{
		ResidueEsa--;
	}
}

void ESA::UpDate()
{

}

void ESA::Animaition()
{

}

void ESA::Draw() const
{
	if (Flashflg == true)
	{
		DrawRotaGraph(x, y, 1, 0, EsaImg, TRUE);
	}
	DrawFormatString(0, 0, 0xffffff, "residue:%d", ResidueEsa);
}

