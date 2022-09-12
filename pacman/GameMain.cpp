#include "GameMain.h"
#include"Object.h"
#include"Player.h"
#include"Esa.h"
#include"Stage.h"


GameMain::GameMain()
{

    stage = new Stage();
    stage->MapInit(); 
    esacontroll = new EsaControll(stage);
    esa = esacontroll->Getesa();
    player = new Player(stage);
    enemy_red = new Enemy_Red(stage,player);


    stage->LoadData();


}

AbstractScene* GameMain::Update(XINPUT_STATE data)
{

    player->Init(data);
    player->UpDate();
 
    for (int i = 0; i < D_ESA_MAX; i++)
    {
        if (CheckHitPlayer_Esa(player, esa[i]) == true)
        {
            if (esa[i]->GetFlg() == TRUE)
            {
                esa[i]->ChangeFlg();
                if (esa[i]->GetType() != 2)
                {          
                    ESA::ResidueEsa--;
                }
            }
        }
    }
    esacontroll->CreateFruits();
    
    enemy_red->UpDate();

    return this;
}

void GameMain::Draw() const
{
    player->Draw();
    enemy_red->Draw();
    esacontroll->DrawEsa();
    stage->MapSet();

}
