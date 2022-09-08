#include "GameMain.h"
#include"Object.h"
#include"Player.h"
#include"Esa.h"
#include"Stage.h"


GameMain::GameMain()
{
    player = new Player();
    enemy_red = new Enemy_Red();

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
    for (int i = 0; i < D_ESA_MAX; i++)
    {
        if (CheckHitPlayer_Esa(player, esa[i]) == true)
        {
            esa[i]->ChangeFlg();
        }
    }

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
