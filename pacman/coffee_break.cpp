#include "DxLib.h"
#include "coffee_break.h"
#include"GameMain.h"

Coffee::Coffee(int data, int life)
{
    stageCount = new int;
    *stageCount = data;
    CoffeeBreakType = 1;
    PlayerLife = new int;
    *PlayerLife = life;

    //Pacman
    Pacimg[0] = LoadGraph("images/pac1.png");
    Pacimg[1] = LoadGraph("images/pac2.png");
    Pacimg[2] = LoadGraph("images/pac3.png");
    Pacanim = 0;
    PacSize = 1;
    PacSpeed = 6;
    PacX = 1300;
    PacY = 360;
    Nowdirect = 0;
    PDirection = PLAYER_NORMAL_LEFT;

    //Enemy
    EnemyX = 1400;
    EnemyY = 360;
    EnemySpeed = 6;

    if (CoffeeBreakType == 2)
    {
        PacSpeed = 3;
        EnemySpeed = 3;
    }

    image1[0] = LoadGraph("images/ê‘ìG1.png");
    image1[1] = LoadGraph("images/ê‘ìG5.png");
    image2[0] = LoadGraph("images/ê‘ìG2.png");
    image2[1] = LoadGraph("images/ê‘ìG6.png");
    image3[0] = LoadGraph("images/ê‘ìG3.png");
    image3[1] = LoadGraph("images/ê‘ìG7.png");
    image4[0] = LoadGraph("images/ê‘ìG4.png");
    image4[1] = LoadGraph("images/ê‘ìG8.png");

    ijikeimage1[0] = LoadGraph("images/çï1.png");
    ijikeimage1[1] = LoadGraph("images/çï2.png");

    kugi = LoadGraph("images/kugi.png");
    billibilli[0] = LoadGraph("images/biribiri0.png");
    billibilli[1] = LoadGraph("images/biribiri1.png");
    billibilli[2] = LoadGraph("images/biribiri2.png");
    billibilli[3] = LoadGraph("images/biribiri3.png");
    naki[0] = LoadGraph("images/naki0.png");
    naki[1] = LoadGraph("images/naki1.png");
    kega[0] = LoadGraph("images/kega0.png");
    kega[1] = LoadGraph("images/kega1.png");
    nige[0] = LoadGraph("images/nige0.png");
    nige[1] = LoadGraph("images/nige1.png");


    nowway = ENEMY_NORMAL_LEFT;


    PlayTime = 0;
}

AbstractScene* Coffee::Update(XINPUT_STATE data) {

    if (data.Buttons[XINPUT_BUTTON_START] || CheckHitKey(KEY_INPUT_SPACE)) {
        return new GameMain(*stageCount,*PlayerLife);
    }

    if (PlayTime < 540)
    {
        switch (CoffeeBreakType)
        {
        case 1:
            CoffeeBreak1();
            break;
        case 2:
            CoffeeBreak2();
            break;
        case 3:
            CoffeeBreak3();
            break;
        }
    }
    else
    {
        return new GameMain(*stageCount,*PlayerLife);
    }

    PlayTime++;
    // é©ï™é©êgÇÃÉ|ÉCÉìÉ^
    return this;
}

void Coffee::Draw() const {

    SetFontSize(50);
    DrawFormatString(20, 20, 0xffffff, "Coffee:%d", CoffeeBreakType, true);
    DrawFormatString(20, 60, 0xffffff, "Time:%d", PlayTime, true);

    switch (CoffeeBreakType)
    {
    case 1:
        Draw1();
        break;
    case 2:
        Draw2();
        break;
    case 3:
        Draw3();
        break;
    }
}

void Coffee::CoffeeBreak1()
{
    PacAnimation();
    PacDirection();
    EnemyAnimaition();

    PacX = PacX - PacSpeed;
    if (PacX < -200)
    {
        PacSpeed = -6;
        PacSize = 3;
        PDirection = PLAYER_NORMAL_RIGHT;
    }

    EnemyX = EnemyX - EnemySpeed;
    if (EnemyX < -100)
    {
        EnemySpeed = -6;
        nowway = ENEMY_NORMAL_RIGHT;
        ijike = true;
    }
    

}

void Coffee::Draw1() const
{
    DrawRotaGraph(PacX, PacY, PacSize, Nowdirect, PNowdraw, TRUE, FALSE);
    DrawRotaGraph(EnemyX, EnemyY, 0.5, 0, Enowdraw, TRUE);
}

void Coffee::CoffeeBreak2()
{
    PacAnimation();
    PacDirection();
    EnemyAnimaition();

    PacX = PacX - PacSpeed;
    EnemyX = EnemyX - EnemySpeed;
    if (PlayTime >= 254)
    {
        EnemySpeed = 0.01;
    }
    if (PlayTime >= 270)
    {
        EnemySpeed = 0;;
    }
    if (PlayTime >= 350)
    {
        EnemyX = 610;
    }
}

void Coffee::Draw2() const
{ 
    DrawRotaGraph(636, 363, 1.0, 0, kugi, TRUE);
    DrawRotaGraph(PacX, PacY, PacSize, Nowdirect, PNowdraw, TRUE, FALSE);
    if (PlayTime >= 254 && PlayTime <= 260)
    {
        DrawRotaGraph(630, 363, 1.0, 0, billibilli[0], TRUE);
    }
    else if (PlayTime > 260 && PlayTime <= 265)
    {
        DrawRotaGraph(630, 363, 1.0, 0, billibilli[1], TRUE);
    }
    else if (PlayTime > 265 && PlayTime <= 350)
    {
        DrawRotaGraph(630, 363, 1.0, 0, billibilli[2], TRUE);
    }
    if (PlayTime >= 350)
    {
        DrawRotaGraph(630, 365, 1.0, 0, billibilli[3], TRUE);
    }
    if (PlayTime >= 0 && PlayTime <= 350)
    {
        DrawRotaGraph(EnemyX, EnemyY, 0.5, 0, Enowdraw, TRUE);
    }
    else if (PlayTime >= 350 && PlayTime <= 430)
    {
        DrawRotaGraph(EnemyX, EnemyY, 1.2, 0, naki[0], TRUE);
    }
    else
    {
        DrawRotaGraph(EnemyX, EnemyY, 1.2, 0, naki[1], TRUE);
    }
}

void Coffee::CoffeeBreak3()
{
    PacAnimation();
    PacDirection();
    EnemyAnimaition();

    PacX = PacX - PacSpeed;
    EnemyX = EnemyX - EnemySpeed;
    if (EnemyX < -100)
    {
        PacSpeed = 0;
        EnemySpeed = -5;
        nowway = ENEMY_NORMAL_RIGHT;
    }
}

void Coffee::Draw3() const
{
    DrawRotaGraph(PacX, PacY, PacSize, Nowdirect, PNowdraw, TRUE, FALSE);
    DrawRotaGraph(EnemyX, EnemyY, 1.2, 0, E3draw, TRUE);
}

void Coffee::PacAnimation()
{
    if (PacSpeed != 0) {
        Pacanim++;
        if (Pacanim >= 9)
        {
            Pacanim = 0;
        }

        PNowdraw = Pacimg[Pacanim / 3];
    }
    else {
        PNowdraw = Pacimg[0];
    }
}


void Coffee::EnemyAnimaition()
{
    animcount++;

    if (animcount % 10 == 0) {
        nowflg = ToggleFlg(nowflg);
        animcount = 1;
    }

    if (ijike != true) {
        switch (nowway)
        {
        case ENEMY_NORMAL_UP:
            if (nowflg != true) {
                Enowdraw = image3[0];
            }
            else
            {
                Enowdraw = image3[1];
            }
            break;
        case ENEMY_NORMAL_RIGHT:
            if (nowflg != true) {
                Enowdraw = image2[0];
                E3draw = nige[0];
            }
            else
            {
                Enowdraw = image2[1];
                E3draw = nige[1];
            }
            break;
        case ENEMY_NORMAL_DOWN:
            if (nowflg != true) {
                Enowdraw = image4[0];
            }
            else
            {
                Enowdraw = image4[1];
            }
            break;
        case ENEMY_NORMAL_LEFT:
            if (nowflg != true) {
                Enowdraw = image1[0];
                E3draw = kega[0];
            }
            else
            {
                Enowdraw = image1[1];
                E3draw = kega[1];
            }
            break;
        default:
            break;
        }
    }
    else if (ijike == true) {
        if (nowflg != true) {
            Enowdraw = ijikeimage1[0];
        }
        else {
            Enowdraw = ijikeimage1[1];
        }
    }
}

void Coffee::PacDirection()
{
       switch (PDirection)
       {
       case PLAYER_NORMAL_UP:
           Nowdirect = PI / 2;
           break;
       case PLAYER_NORMAL_RIGHT:
           Nowdirect = PI;
           break;
       case PLAYER_NORMAL_DOWN:
           Nowdirect = PI + PI / 2;
           break;
       case PLAYER_NORMAL_LEFT:
           Nowdirect = 0;
           break;
        }
}