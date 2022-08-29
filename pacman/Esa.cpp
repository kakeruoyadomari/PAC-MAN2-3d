#include "Esa.h"
ESA::ESA(int X, int Y)
{		
	x = X;
	y = Y;
	Esaflg = TRUE;
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
	
	DrawGraph(x, y, EsaImg, TRUE);
}

