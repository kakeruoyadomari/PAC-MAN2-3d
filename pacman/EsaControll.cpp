#include"Esa.h"
#include"Player.h"

int EsaControll::esacount = 0;

EsaControll::EsaControll(Stage*data)
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
	esa[ESA_MAX] = new ESA(FruitsX+STAGE_LEFT_SPACE, FruitsY, EsaType, FruitsType);

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

bool EsaControll::CheckHitPlayer_Esa(Object* player, ESA* esa)
{
	if (esa == nullptr)
	{
		return FALSE;
	}
	float rangeX = player->GetX() - esa->GetX() + STAGE_LEFT_SPACE;
	float rangeY = player->GetY() - esa->GetY();
	double range = sqrt(rangeX * rangeX + rangeY * rangeY);
	double sum_radius = double(player->GetRadius()) + double(esa->GetRadius());

	if (range <= sum_radius)
	{
		return true;
	}


	return false;
}