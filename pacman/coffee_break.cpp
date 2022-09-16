#include "DxLib.h"
#include "coffee_break.h"
#include"GameMain.h"

Coffee::Coffee()
{
    //Pacman
    Pacimg[0] = LoadGraph("images/pac1.png");
    Pacimg[1] = LoadGraph("images/pac2.png");
    Pacimg[2] = LoadGraph("images/pac3.png");
    Pacanim = 0;
    PacSize = 1;
    PacSpeed = 3;
    PacX = 1300;
    PacY = 360;
    Nowdirect = 0;
    PDirection = PLAYER_NORMAL_LEFT;

    //Enemy
    EnemyX = 1400;
    EnemyY = 360;
    EnemySpeed = 3;
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

    kugi = LoadGraph("images/coffee_enemy.png");

    nowway = ENEMY_NORMAL_LEFT;

    CoffeeBreakType = 1;
}

AbstractScene* Coffee::Update(XINPUT_STATE data) {

    if (data.Buttons[XINPUT_BUTTON_START] || CheckHitKey(KEY_INPUT_SPACE)) {
        return new GameMain();
    }


    switch (CoffeeBreakType)
    {
    case 1:
        CoffeeBreak1();
        break;
    case2:
        CoffeeBreak2();
        break;
    case3:
        CoffeeBreak3();
        break;
    }


    // é©ï™é©êgÇÃÉ|ÉCÉìÉ^
    return this;
}

void Coffee::Draw() const {

    SetFontSize(50);
    DrawFormatString(20, 20, 0xffffff, "Coffee:%d", CoffeeBreakType, true);

    switch (CoffeeBreakType)
    {
    case 1:
        Draw1();
        break;
    case2:
        Draw2();
        break;
    case3:
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
        PacSpeed = -3;
        PacSize = 3;
        PDirection = PLAYER_NORMAL_RIGHT;
    }

    EnemyX = EnemyX - EnemySpeed;
    if (EnemyX < -100)
    {
        EnemySpeed = -3;
        nowway = ENEMY_NORMAL_RIGHT;
        ijike = true;
    }
    

}

void Coffee::Draw1() const
{
    //DrawBox(1300, 600, 1000, 300, 0xff00ff, true);
    DrawRotaGraph(PacX, PacY, PacSize, Nowdirect, Nowdraw, TRUE, FALSE);
    DrawRotaGraph(EnemyX, EnemyY, 0.5, 0, nowdraw, TRUE);
    DrawRotaGraph(EnemyX, EnemyY+100, 0.5, 0, kugi, TRUE);
}

void Coffee::CoffeeBreak2()
{
    PacAnimation();
    PacDirection();
}

void Coffee::Draw2() const
{
    //DrawRotaGraph(PacX, PacY, PacSize, Nowdirect, Nowdraw, TRUE, FALSE);
}

void Coffee::CoffeeBreak3()
{
    PacAnimation();
    PacDirection();
}

void Coffee::Draw3() const
{
    //DrawRotaGraph(PacX, PacY, PacSize, Nowdirect, Nowdraw, TRUE, FALSE);
}

void Coffee::PacAnimation()
{
    if (PacSpeed != 0) {
        Pacanim++;
        if (Pacanim >= 9)
        {
            Pacanim = 0;
        }

        Nowdraw = Pacimg[Pacanim / 3];
    }
    else {
        Nowdraw = Pacimg[0];
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
                nowdraw = image3[0];
            }
            else
            {
                nowdraw = image3[1];
            }
            break;
        case ENEMY_NORMAL_RIGHT:
            if (nowflg != true) {
                nowdraw = image2[0];
            }
            else
            {
                nowdraw = image2[1];
            }
            break;
        case ENEMY_NORMAL_DOWN:
            if (nowflg != true) {
                nowdraw = image4[0];
            }
            else
            {
                nowdraw = image4[1];
            }
            break;
        case ENEMY_NORMAL_LEFT:
            if (nowflg != true) {
                nowdraw = image1[0];
            }
            else
            {
                nowdraw = image1[1];
            }
            break;
        default:
            break;
        }
    }
    else if (ijike == true) {
        if (nowflg != true) {
            nowdraw = ijikeimage1[0];
        }
        else {
            nowdraw = ijikeimage1[1];
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