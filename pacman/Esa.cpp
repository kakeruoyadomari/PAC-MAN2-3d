#include "Esa.h"
Esa::Esa()
{
	x = 100;
	y = 100;
	EsaImg = LoadGraph("images/��������.png");
	PowerEsaImg = LoadGraph("images/�f�J����.png");
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