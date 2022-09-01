#include "DxLib.h"
#include "Title.h"
#include"GameMain.h"

AbstractScene* Title::Update(XINPUT_STATE data) {

    if (data.Buttons[XINPUT_BUTTON_START]) {
        return new GameMain();
    }

    // 自分自身のポインタ
    return this;
}

void Title::Draw() const {

    SetFontSize(50);
    DrawFormatString(20, 20, 0xffffff, "PACMAN", true);
}
