#include "DxLib.h"
#include "Title.h"
#include"GameMain.h"
#include "coffee_break.h"

AbstractScene* Title::Update(XINPUT_STATE data) {

    if (data.Buttons[XINPUT_BUTTON_START]||CheckHitKey(KEY_INPUT_SPACE)) {
        return new GameMain();
    }
    if (data.Buttons[XINPUT_BUTTON_A] || CheckHitKey(KEY_INPUT_Z)) {
        return new Coffee();
    }

    // 自分自身のポインタ
    return this;
}

void Title::Draw() const {

    SetFontSize(50);
    DrawFormatString(20, 20, 0xffffff, "PACMAN", true);
}
