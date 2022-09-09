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
	FruitsType = 0;

	SetX = 1050;
	SetY = 100;


	for (sy = 0; sy < STAGE_HEIGHT; sy++) 
	{
		for (sx = 0; sx < STAGE_WIDTH * 2; sx++)
		{
			SetEsa(sx, sy);
		}
	}


	//for (int i = 0; i < 245; i++)
	//{
	//	if (i < 240)
	//	{
	//		EsaType = 0;
	//		esa[i] = new ESA(SetX, SetY, EsaType);
	//	}
	//	else if (i >= 240 && i < 244)
	//	{
	//		EsaType = 1;
	//		esa[i] = new ESA(SetX, SetY, EsaType);
	//	}
	//	else
	//	{
			EsaType = 2;
			esa[244] = new ESA(SetX, SetY, EsaType, FruitsType);
	//	}

			for (int i = 0; i < 244; i++)
			{
				esa[i]->SetImage(EsaImage[EsaType]);
			}
		//else
		//{
		//	//do 現在のステージ数持ってくる
		//	esa[244]->SetImage(FruitsImage[7]);
		//}

		//SetX += 20;
		//if (SetX >= 1250)
		//{
		//	SetX = 1050;
		//	SetY += 20;
		//}

	//}
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
		esa[244]->ChangeFlg();
		esa[244]->SetImage(FruitsImage[FruitsType]);
		CreatePieces--;
	}
	if (CreatePieces == 1 && (ESA::ResidueEsa == 74))
	{
		esa[244]->ChangeFlg();
		esa[244]->SetImage(FruitsImage[FruitsType]);
		CreatePieces--;
	}
	if (esa[244]->GetFlg() == TRUE)
	{
		FruitsTimer++;
		if (FruitsTimer > 600)
		{
			//flgで管理するか？
			esa[244]->ChangeFlg();
			FruitsTimer = 0;
		}
	}


}

void EsaControll::SetEsa(int x, int y)
{
	static int i = 0;


	//if (stage->GetStageData(sx, sy) == 0)
	if (stage->StageTS[x][y] == 0)
	{	
		EsaType = 0;
		esa[i]= new ESA(x * DOT_SIZE + 11, y * DOT_SIZE + 11, EsaType);
		i++;
	}
	//else if (stage->GetStageData(sx, sy) == 4)
	else if (stage->StageTS[x][y] == 4)
	{
		EsaType = 1;
		esa[i] = new ESA(x * DOT_SIZE + 11, y * DOT_SIZE + 11, EsaType);
		i++;
	}
	else
	{
		i++;
	}
	//(sx * DOT_SIZE + 11, sy * DOT_SIZE + 11, 0x00ff00);
}

void EsaControll::DrawEsa()
{
	for (int i = 0; i < 245; i++)
	{
		if (esa[i]->GetFlg() == TRUE)
		{
			esa[i]->Draw();
		}
	}
}