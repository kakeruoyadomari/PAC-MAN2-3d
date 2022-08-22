#include "Esa.h"
Esa::Esa()
{
	x = 100;
	y = 100;
	EsaImg = LoadGraph("images/è¨Ç≥Ç¢ã .png");
	PowerEsaImg = LoadGraph("images/ÉfÉJÇ¢ã .png");
}

void Esa::UpDate()
{

}

void Esa::Animaition()
{

}

void Esa::Draw() const
{
	DrawGraph(x, y, EsaImg, TRUE);
}