#include "GameMain.h"
#include"Object.h"
#include"Player.h"
#include"Esa.h"

Esa* esa;

GameMain::GameMain()
{
    player = new Player();
    esa = new Esa();
}

AbstractScene* GameMain::Update(XINPUT_STATE data)
{

    player->UpDate();

    return this;
}

void GameMain::Draw() const
{
    player->Draw();
    esa->Draw();
}
