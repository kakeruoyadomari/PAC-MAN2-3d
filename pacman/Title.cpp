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
    ////�G���f�B���O�\��
    //if (++WaitTime < 600) PosY = 300 - WaitTime / 2;
   
    ////�^�C���̉��Z�������I��
    //if (++WaitTime > 900) GameState = 99;
     // �y�L�[�Ń��j���[�I��
    if (data.Buttons[XINPUT_BUTTON_A]) {
        switch (MenuNumber) {

        case 0:

            return new GameMain(); // GameMain��
            break;

        //case 1:

        //    return new END(); //Help��
        //    break;

        }

    }

    // �������g�̃|�C���^
    return this;
}

void Title::Draw() const {

    //���j���[�J�[�\���i�O�p�`�j�̕\��
    DrawTriangle(560, 405 + MenuY, 580, 420 + MenuY, 560, 435 + MenuY, GetColor(255, 0, 0), true);
   
    SetFontSize(100);
    DrawFormatString(500, 100, 0xFFFF00, "PACMAN", true); 
   
    SetFontSize(50);
    DrawFormatString(600, 400, 0xffffff, "START", true);
    
    /*SetFontSize(50);
    DrawFormatString(600, 450, 0xffffff, "END", true);*/
    
}

