#include "Esa.h"
Esa::Esa()
{
	x = 100;
	y = 100;
	EsaImg = LoadGraph("images/小さい玉.png");
	PowerEsaImg = LoadGraph("images/デカい玉.png");
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