#include "GameMain.h"
#include"Object.h"
#include"Player.h"
#include"Esa.h"
#include"Stage.h"


GameMain::GameMain()
{
    stageCount = new int;

    stage = new Stage();
    stage->MapInit(); 
    esacontroll = new EsaControll(stage);
    esa = esacontroll->Getesa();
    player = new Player(stage);
    enemy_red = new Enemy_Red(player,stageCount);
    enemy_cyan = new Enemy_Cyan();
    enemy_orange = new Enemy_Orange();
    enemy_pink = new Enemy_Pink();


    *stageCount = 1;

    startTimer = 450;


    stage->LoadData();

    enemy_pink->GetExistHome(true);


        ExistCount1 = 30;
        ExistCount2 = 90;
    
}

AbstractScene* GameMain::Update(XINPUT_STATE data)
{

    if (player->GetClearFlg() == false&&startTimer <= 0) {

        player->Init(data);
        player->UpDate();

        for (int i = 0; i < D_ESA_MAX; i++)
        {
            if (esacontroll->CheckHitPlayer_Esa(player, esa[i]) == true)
            {
                if (esa[i]->GetFlg() == TRUE)
                {
                    esa[i]->ChangeFlg();
                    if (esa[i]->GetType() != 2)
                    {
                        if (esa[i]->GetType() == 1)
                        {
                            //‚Ï‚í[‚¦‚³‚µ‚ã‚Æ‚­
                        }
                        ESA::ResidueEsa--;
                    }
                }
            }
        }

        if (data.Buttons[XINPUT_BUTTON_B]) {
            player->ToggleClearFlg();
        }

        esacontroll->CreateFruits();

        enemy_red->UpDate();
        enemy_cyan->UpDate();
        enemy_orange->UpDate();
        enemy_pink->UpDate();

        if (ESA::ResidueEsa == ESA_MAX - ExistCount1) {
            enemy_cyan->GetExistHome(true);
        }
        else if (ESA::ResidueEsa == ESA_MAX - ExistCount2) {
            enemy_orange->GetExistHome(true);
        }
        else if (ESA::ResidueEsa == 0) {
            player->ToggleClearFlg();
        }
    }
    else if(player->GetClearFlg() == true){
        player->ResetImage();
        stage->StageAnimetion();
        AnimeTimer += 1;

        if (AnimeTimer / 300 == 1) {
            ResetMain();
        }
    }
    else {
        startTimer--;
    }

    return this;
}

void GameMain::Draw() const
{
    if (player->GetClearFlg()==false&&startTimer < 300) {
        player->Draw();
        enemy_red->Draw();
        enemy_cyan->Draw();
        enemy_orange->Draw();
        enemy_pink->Draw();
        esacontroll->DrawEsa();
        stage->MapSet();
    }
    else if (player->GetClearFlg() == true) {
        player->Draw();
        stage->MapSet();
    }
    else {
        stage->MapSet();
        esacontroll->DrawEsa();
        SetFontSize(35);
        DrawString(11 * DOT_SIZE+STAGE_LEFT_SPACE, 11 * DOT_SIZE, "PLAYER", 0x000ff0);
        DrawString(12 * DOT_SIZE+STAGE_LEFT_SPACE, 17 * DOT_SIZE, "READY", 0xff0000);
    }

}

void GameMain::ResetMain()
{

    stage = new Stage();
    stage->MapInit();
    esacontroll->ResetCount();
    esacontroll = new EsaControll(stage);
    esa = esacontroll->Getesa();
    player = new Player(stage);
    enemy_red = new Enemy_Red(player, stageCount);
    enemy_cyan = new Enemy_Cyan();
    enemy_orange = new Enemy_Orange();
    enemy_pink = new Enemy_Pink();
    stage->LoadData();

    *stageCount += 1;

    startTimer = 900;

    if (5 > *stageCount && *stageCount > 1) {
        ExistCount1 = 0;
        ExistCount2 = 50;
    }
    else {
        ExistCount1 = 0;
        ExistCount2 = 0;
    }

    player->ToggleClearFlg();
    enemy_pink->GetExistHome(true);
}
