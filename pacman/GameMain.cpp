#include "GameMain.h"
#include"Object.h"
#include"Player.h"


Player* player;

GameMain::GameMain()
{
    player = new Player();
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
    player->Draw();
}
