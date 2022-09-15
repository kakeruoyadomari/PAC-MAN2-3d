#include "DxLib.h"
#include "coffee_break.h"
#include"GameMain.h"

Coffee::Coffee()
{
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


    // 自分自身のポインタ
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

    PacX = PacX - PacSpeed;
    if (PacX < -200)
    {
        PacSpeed = -3;
        PacSize = 3;
        PDirection = PLAYER_NORMAL_RIGHT;
    }
    

}

void Coffee::Draw1() const
{
    DrawRotaGraph(PacX, PacY, PacSize, Nowdirect, Nowdraw, TRUE, FALSE);
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