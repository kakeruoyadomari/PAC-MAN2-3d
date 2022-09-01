#include"Esa.h"
#include"Player.h"
EsaControll::EsaControll()
{
	EsaImage[0] = LoadGraph("images/è¨Ç≥Ç¢ã .png");
	EsaImage[1] = LoadGraph("images/ÉfÉJÇ¢ã .png");

	SetX = 100;
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

		esa[i] = new ESA(SetX, SetY);
		esa[i]->SetImage(EsaImage[EsaType]);

		SetX += 20;
		if (SetX >= 300)
		{
			SetX = 100;
			SetY += 20;
		}

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