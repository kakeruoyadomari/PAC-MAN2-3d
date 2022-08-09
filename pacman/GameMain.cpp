#include "GameMain.h"
#include"Object.h"
#include"Player.h"

GameMain::GameMain()
{
    obj = new Object();
    player = new Player();
}

AbstractScene* GameMain::Update(XINPUT_STATE data)
{

    obj->UpData();
    player->UpData();

    return this;
}

void GameMain::Draw() const
{
    obj->Draw();
    player->Draw();
}
