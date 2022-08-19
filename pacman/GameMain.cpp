#include "GameMain.h"
#include"Object.h"
#include"Player.h"

GameMain::GameMain()
{
    player = new Player();
}

AbstractScene* GameMain::Update(XINPUT_STATE data)
{

    player->UpData();

    return this;
}

void GameMain::Draw() const
{
    player->Draw();
}
