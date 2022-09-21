#include "DxLib.h"
#include "Title.h"
#include"GameMain.h"

AbstractScene* Title::Update(XINPUT_STATE data) {

    if (data.Buttons[XINPUT_BUTTON_START]) {
        return new GameMain();
    }
    if (data.Buttons[XINPUT_BUTTON_A]) {
        return new GameMain();
    }
    //�G���f�B���O�\��
    if (++Time < 100) PosY = 300 - (Time / 2) * 6;

    // �������g�̃|�C���^
    return this;
}

void Title::Draw() const {
    
    //�^�C�g���摜�\��
    DrawGraph(240, 0 + PosY, TitleImage, FALSE);

    //���j���[(yoko,takasa)
    DrawGraph(370, 390 + PosY, Menu, TRUE);

    DrawString(420, 80 + PosY, "1UP", 0xFF0000);
    DrawString(450, 100 + PosY, "00", 0xffffff);
    DrawString(610, 80 + PosY, "HI-SCORE", 0xFF0000);
    DrawString(630, 100 + PosY, "10000", 0xffffff);
    DrawString(830, 80 + PosY, "2UP", 0xFF0000);
    DrawString(860, 100 + PosY, "00", 0xffffff);
}

