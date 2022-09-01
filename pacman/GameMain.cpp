#include "GameMain.h"
#include"Object.h"
#include"Player.h"
#include"Esa.h"
#include"Stage.h"

Player* player;


GameMain::GameMain()
{
    player = new Player();

    esacontroll = new EsaControll();
    esa = esacontroll->Getesa();
    stage = new Stage();

    stage->LoadData();
    stage->MapInit();
}

AbstractScene* GameMain::Update(XINPUT_STATE data)
{

    player->Init(data);
    player->UpDate();
    for (int i = 0; i < 244; i++)
    {
        if (CheckHitPlayer_Esa(player, esa[i]) == TRUE)
        {
            delete esa[i];
        }
    }

    

    return this;
}

void GameMain::Draw() const
{
    player->PlayerDisplay();
    player->Draw();
    esacontroll->DrawEsa();
    stage->MapSet();

}
