#include "GameMain.h"
#include"Object.h"
#include"Player.h"
#include"Esa.h"
#include"Stage.h"


GameMain::GameMain(int data, int life)
{
    stageCount = new int;
    *stageCount = data + 1;

    PlayerLife = new int;
    *PlayerLife = life;

    stage = new Stage();
    stage->MapInit(); 
    esacontroll = new EsaControll(stage,*stageCount);
    esa = esacontroll->Getesa();
    player = new Player(stage, *PlayerLife);
    enemy_red = new Enemy_Red(player,stageCount);
    enemy_cyan = new Enemy_Cyan();
    enemy_orange = new Enemy_Orange();
    enemy_pink = new Enemy_Pink();



    startTimer = 450;


    stage->LoadData();

    enemy_pink->GetExistHome(true);


        ExistCount1 = 30;
        ExistCount2 = 90;
    
}

AbstractScene* GameMain::Update(XINPUT_STATE data)
{

    if (player->GetClearFlg() == false&&startTimer <= 0&&GameOverFlg == false) {

        player->Init(data);
        player->UpDate();

        for (int i = 0; i <= D_ESA_MAX; i++)
        {
            if (CheckHitPlayer_Esa(player, esa[i]) == true)
            {
                if (esa[i]->GetFlg() == TRUE)
                {
                    esa[i]->ChangeFlg();
                    if (esa[i]->GetType() != 2)
                    {
                        if (esa[i]->GetType() == 1) {
                            enemy_red->ChangeAllIjike();
                            if(enemy_red->GetExistFlg() == true) enemy_red->ChangeIjike();
                            if(enemy_pink->GetExistFlg() == true) enemy_pink->ChangeIjike();
                            if(enemy_cyan->GetExistFlg() == true) enemy_cyan->ChangeIjike();
                            if(enemy_orange->GetExistFlg() == true) enemy_orange->ChangeIjike();
                        }
                        ESA::ResidueEsa--;
                    }
                }
            }
        }

        enemy_red->EnemyTrackCounter(enemy_red->GetIjikeFlg(), enemy_pink->GetIjikeFlg(),
            enemy_cyan->GetIjikeFlg(), enemy_orange->GetIjikeFlg());

        if (data.Buttons[XINPUT_BUTTON_B]) {
            player->ToggleClearFlg();
        }

        esacontroll->CreateFruits();
        esacontroll->FlashEsa();
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

    if (player->GetNowGameFlg() == false)
    {
        GameoverAnim = true;
        DeadFlg = true;

        if (*PlayerLife > 0)
        {
            if (GameoverAnim == true && animcount++ < 80) {
                player->UpDate();
            }
            else {
                DeadFlg = false;
                animcount = 0;

                player = new Player(stage, *PlayerLife);
                enemy_red = new Enemy_Red(player, stageCount);
                enemy_cyan = new Enemy_Cyan();
                enemy_orange = new Enemy_Orange();
                enemy_pink = new Enemy_Pink();
                *PlayerLife -= 1;
            }
        }
        else if(*PlayerLife == 0)
        {
            GameOverFlg = true;
        }
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
    else if(startTimer > 300){
        stage->MapSet();
        esacontroll->DrawEsa();
        SetFontSize(35);
        DrawString(11 * DOT_SIZE+STAGE_LEFT_SPACE, 11 * DOT_SIZE, "PLAYER", 0x000ff0);
        DrawString(12 * DOT_SIZE+STAGE_LEFT_SPACE, 17 * DOT_SIZE, "READY", 0xff0000);
    }
    else if (DeadFlg == true&&GameOverFlg == false) {
        stage->MapSet();
        player->Draw();
    }
    else if (GameOverFlg == true) {

    }

}

void GameMain::ResetMain()
{
    ESA::ResidueEsa = 0;

    stage = new Stage();
    stage->MapInit();
    esacontroll->ResetCount();
    esacontroll = new EsaControll(stage, *stageCount);
    esa = esacontroll->Getesa();
    player = new Player(stage,*PlayerLife);
    enemy_red = new Enemy_Red(player, stageCount);
    enemy_cyan = new Enemy_Cyan();
    enemy_orange = new Enemy_Orange();
    enemy_pink = new Enemy_Pink();
    stage->LoadData();

    *stageCount += 1;

    

    startTimer = 450;

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
