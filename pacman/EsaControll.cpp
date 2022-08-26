#include"Esa.h"

EsaControll::EsaControll()
{
	EsaImage[0] = LoadGraph("images/è¨Ç≥Ç¢ã .png");
	EsaImage[1] = LoadGraph("images/ÉfÉJÇ¢ã .png");

	SetX = 10;
	SetY = 100;

	for (int i = 0; i < 244; i++)
	{
		if (i < 240)
		{
			EsaType = 0;
		}
		else
		{
			EsaType = 1;
		}
		//for (int j = 0; j < 10; j++)
		//{
			SetX += 5;
		//	for ()
		//	{
		//		SetX = 100;
		//		SetY += 50;
		//		esa[i] = new ESA(SetX, SetY);
		//	}
		//}
		esa[i] = new ESA(SetX, SetY);
		esa[i]->SetImage(EsaImage[EsaType]);
	}
}

void EsaControll::SetEsa()
{

}

void EsaControll::DrawEsa()
{
	for (int i = 0; i < 244; i++)
	{
		if (esa[i]->GetFlg() == TRUE)
		{
			esa[i]->Draw();
		}
	}
}