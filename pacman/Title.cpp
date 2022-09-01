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
    ////エンディング表示
    //if (++WaitTime < 600) PosY = 300 - WaitTime / 2;
   
    ////タイムの加算処理＆終了
    //if (++WaitTime > 900) GameState = 99;
     // Ｚキーでメニュー選択
    if (data.Buttons[XINPUT_BUTTON_A]) {
        switch (MenuNumber) {

        case 0:

            return new GameMain(); // GameMainへ
            break;

        //case 1:

        //    return new END(); //Helpへ
        //    break;

        }

    }

    // 自分自身のポインタ
    return this;
}

void Title::Draw() const {

    //メニューカーソル（三角形）の表示
    DrawTriangle(560, 405 + MenuY, 580, 420 + MenuY, 560, 435 + MenuY, GetColor(255, 0, 0), true);
   
    SetFontSize(100);
    DrawFormatString(500, 100, 0xFFFF00, "PACMAN", true); 
   
    SetFontSize(50);
    DrawFormatString(600, 400, 0xffffff, "START", true);
    
    /*SetFontSize(50);
    DrawFormatString(600, 450, 0xffffff, "END", true);*/
    
}

