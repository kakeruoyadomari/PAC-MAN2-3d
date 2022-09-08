#include"Esa.h"
#include"Player.h"
EsaControll::EsaControll()
{
	EsaImage[0] = LoadGraph("images/Small.png");
	EsaImage[1] = LoadGraph("images/Power.png");

	FruitsImage[0] = LoadGraph("images/Cherry.png");
	FruitsImage[1] = LoadGraph("images/Strawberry.png");
	FruitsImage[2] = LoadGraph("images/Orange.png");
	FruitsImage[3] = LoadGraph("images/Apple.png");
	FruitsImage[4] = LoadGraph("images/Melon.png");
	FruitsImage[5] = LoadGraph("images/Galaxian.png");
	FruitsImage[6] = LoadGraph("images/Bell.png");
	FruitsImage[7] = LoadGraph("images/Key.png");

	CreatePieces = 2;

	SetX = 100;
	SetY = 100;

	for (int i = 0; i < 244; i++)
	{
		if (i < 240)
		{
			EsaType = 0;
		}
		else if (i >= 240 && i < 244)
		{
			EsaType = 1;
		}

		esa[i] = new ESA(SetX, SetY, EsaType);
		esa[i]->SetImage(EsaImage[EsaType]);
		//else
		//{
		//	//do 現在のステージ数持ってくる
		//	esa[244]->SetImage(FruitsImage[7]);
		//}

		SetX += 20;
		if (SetX >= 300)
		{
			SetX = 100;
			SetY += 20;
		}

	}
}

void  EsaControll::CreateFruits()
{
	int FruitsX = 400;
	int FruitsY = 400;
	int EsaType = 2;
	int FruitsType = 0;
	static int FruitsTimer = 0;

	//do 現在のステージ数持ってくる
	if (CreatePieces == 2 && (ESA::ResidueEsa == /*174*/240))
	{
		esa[244] = new ESA(FruitsX, FruitsY, EsaType, FruitsType);
		esa[244]->SetImage(FruitsImage[FruitsType]);
		CreatePieces--;
	}
	if (CreatePieces == 1 && (ESA::ResidueEsa == 74))
	{
		esa[244] = new ESA(FruitsX, FruitsY, EsaType, FruitsType);
		esa[244]->SetImage(FruitsImage[FruitsType]);
		CreatePieces--;
	}
	if (esa[244] != nullptr)
	{
		FruitsTimer++;
		if (FruitsTimer > 600)
		{
			//flgで管理するか？
			delete esa[244];
			esa[244] = nullptr;
			FruitsTimer = 0;
		}
	}


}

void EsaControll::SetEsa()
{

}

void EsaControll::DrawEsa()
{
	for (int i = 0; i < 245; i++)
	{
		if (esa[i] == nullptr)
		{
			break;
		}
		else if (esa[i]->GetFlg() == TRUE)
		{
			esa[i]->Draw();
		}
	}
}