#include"Esa.h"
#include"Player.h"
#include "Object.h"

int EsaControll::esacount = 0;

EsaControll::EsaControll(Stage*data, int stageCount)
{
	stage = data;

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
	FruitsScore = 100;
	FruitsX = 310;
	FruitsY = 517;


	for (sy = 0; sy < STAGE_HEIGHT; sy++) 
	{
		for (sx = 0; sx < STAGE_WIDTH * 2; sx++)
		{
			SetEsa(sx ,sy, stage);
		}
	}


	EsaType = 2;

	if (stageCount == 1)
	{
		FruitsType = 0;
		FruitsScore = 100;
	}
	else if (stageCount == 2)
	{
		FruitsType = 1;
		FruitsScore = 300;
	}
	else if (stageCount == 3 || stageCount == 4)
	{
		FruitsType = 2;
		FruitsScore = 500;
	}
	else if (stageCount == 5 || stageCount == 6)
	{
		FruitsType = 3;
		FruitsScore = 700;
	}
	else if (stageCount == 7 || stageCount == 8)
	{
		FruitsType = 4;
		FruitsScore = 1000;
	}
	else if (stageCount == 9 || stageCount == 10)
	{
		FruitsType = 5;
		FruitsScore = 2000;
	}
	else if (stageCount == 11 || stageCount == 12)
	{
		FruitsType = 6;
		FruitsScore = 3000;
	}
	else
	{
		FruitsType = 7;
		FruitsScore = 5000;
	}
	esa[ESA_MAX] = new ESA(FruitsX + STAGE_LEFT_SPACE, FruitsY, EsaType, FruitsType, FruitsScore);


	for (int i = 0; i < ESA_MAX; i++)
	{
		if (esa[i]->GetType() == 0)
		{
			esa[i]->SetImage(EsaImage[0]);
		}
		if (esa[i]->GetType() == 1)
		{
			esa[i]->SetImage(EsaImage[1]);
		}
	}
	esa[ESA_MAX]->SetImage(FruitsImage[FruitsType]);
			
}

void  EsaControll::CreateFruits()
{
	int FruitsX = 400;
	int FruitsY = 400;
	int EsaType = 2;
	int FruitsType = 0;
	static int FruitsTimer = 0;

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
			esa[244]->ChangeFlg();
			FruitsTimer = 0;
		}
	}


}



void EsaControll::SetEsa(int sx, int sy, Stage* stage)
{


	if (stage->GetStageData(sx, sy) == 0)
	{	
		EsaType = 0;
		esa[esacount]= new ESA(sx * DOT_SIZE + 11+STAGE_LEFT_SPACE, sy * DOT_SIZE + 11, EsaType);
		esacount++;
	}
	else if (stage->GetStageData(sx, sy) == 4)
	//else if (stage->StageTS[x][y] == 4)
	{
		EsaType = 1;
		esa[esacount] = new ESA(sx * DOT_SIZE + 11+STAGE_LEFT_SPACE, sy * DOT_SIZE + 11, EsaType);
		esacount++;
	}
}

void EsaControll::DrawEsa()
{
	for (int i = 0; i < 245; i++)
	{
		if (esa[i]->GetFlg() == true)
		{
			esa[i]->Draw();
		}
	}
}

void EsaControll::FlashEsa()
{
	static int FlashTime = 0;
	for (int i = 0; i < ESA_MAX; i++)
	{
		if (esa[i]->GetType() == 1)
		{
			if (FlashTime > 30)
			{
				esa[i]->ChangeFlashFlg();
			}
		}
	}
	if (FlashTime > 30)
	{
		FlashTime = 0;
	}
	FlashTime++;
}