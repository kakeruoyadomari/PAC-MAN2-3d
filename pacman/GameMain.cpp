#include "GameMain.h"
#include"Object.h"
#include"Player.h"
#include"Stage.h"

GameMain::GameMain()
{
    player = new Player();
    stage = new Stage();

    stage->LoadData();
    stage->MapInit();
}

AbstractScene* GameMain::Update(XINPUT_STATE data)
{

    player->UpDate();

    return this;
}

void GameMain::Draw() const
{
    player->Draw();
    stage->MapSet();
}
