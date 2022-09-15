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
    //エンディング表示
    if (++WaitTime < 100) PosY = 300 - (WaitTime / 2) * 6;
    

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

   
    
    //タイトル画像表示
    DrawGraph(240, 0 + PosY, TitleImage, FALSE);

    //メニュー(yoko,takasa)
    DrawGraph(370, 390 + PosY, Menu, TRUE);

    DrawString(420, 80 + PosY, "1UP", 0xFF0000);
    DrawString(450, 100 + PosY, "00", 0xffffff);
    DrawString(610, 80 + PosY, "HI-SCORE", 0xFF0000);
    DrawString(630, 100 + PosY, "10000", 0xffffff);
    DrawString(830, 80 + PosY, "2UP", 0xFF0000);
    DrawString(860, 100 + PosY, "00", 0xffffff);
}

