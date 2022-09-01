#include "Esa.h"
#include "Player.h"
#include "Object.h"
ESA::ESA(int X, int Y)
{		
	x = X;
	y = Y;
	Esaflg = TRUE;
	radius = 2;
	//EsaImg = 0;
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
}

