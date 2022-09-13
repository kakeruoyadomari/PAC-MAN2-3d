#include "DxLib.h"
#include "coffee_break.h"
#include"GameMain.h"

Coffee::Coffee()
{
    player = new Player();
}

AbstractScene* Coffee::Update(XINPUT_STATE data) {

    if (data.Buttons[XINPUT_BUTTON_START] || CheckHitKey(KEY_INPUT_SPACE)) {
        return new GameMain();
    }

    Break1();

    // 自分自身のポインタ
    return this;
}

void Coffee::Draw() const {

    SetFontSize(50);
    DrawFormatString(20, 20, 0xffffff, "Coffee", true);
}

void Coffee::Break1()
{
    player->UpDate();
}

void Coffee::Break2()
{

}

void Coffee::Break3()
{

}
