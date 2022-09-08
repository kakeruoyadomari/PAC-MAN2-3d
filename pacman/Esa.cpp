#include "Esa.h"
#include "Player.h"
#include "Object.h"

int ESA::ResidueEsa = 0;
ESA::ESA(int X, int Y, int EsaType)
{		
	x = X;
	y = Y;
	Esaflg = TRUE;
	EsaScore = 10;
	Type = EsaType;
	radius = 2;

	ResidueEsa++;
	
	//EsaImg = 0;
}

ESA::ESA(int X, int Y, int EsaType, int FruitsType)
{
	x = X;
	y = Y;
	Esaflg = TRUE;
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
	DrawRotaGraph(x, y, 1, 0, EsaImg, TRUE);
	DrawFormatString(0, 0, 0xffffff, "residue:%d", ResidueEsa);
}

