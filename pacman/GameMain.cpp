#include "GameMain.h"
#include"Object.h"
#include"Player.h"
#include"Esa.h"

Player* player;


Player* player;

GameMain::GameMain()
{
    player = new Player();
    esacontroll = new EsaControll();
}

AbstractScene* GameMain::Update(XINPUT_STATE data)
{
    player->Init(data);
    player->UpDate();

    return this;
}

void GameMain::Draw() const
{
    player->PlayerDisplay();
    //player->Draw();
    player->Draw();
    esacontroll->DrawEsa();
}
