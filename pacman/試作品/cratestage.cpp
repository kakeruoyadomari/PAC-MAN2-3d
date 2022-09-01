#include "DxLib.h"


#define STAGE_WIDTH 464
#define STAGE_HEIGHT 512

#define DOT_SIZE 2

int StagePixel[STAGE_WIDTH][STAGE_HEIGHT];
int MouseX;
int MouseY;

FILE* fp;
#pragma warning(disable:4996)


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    SetGraphMode(1920, 1080, 32);
    SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_DESKTOP);


    SetBackgroundColor(255, 255, 255);


    // ＤＸライブラリの初期化
    if (DxLib_Init() < 0)
    {
        // エラーが発生したら直ちに終了
        return -1;
    }

    // マウスを表示状態にする
    SetMouseDispFlag(TRUE);

    fopen_s(&fp, "dat/stagedata.txt", "r");

    //ファイルロード
    for (int i = 0; i < STAGE_WIDTH; i++) {
        for (int j = 0; j < STAGE_HEIGHT; j++) {
            fscanf(fp, "%d,", &StagePixel[i][j]);
        }
    }

    //ファイルクローズ
    fclose(fp);

    SetDrawScreen(DX_SCREEN_BACK);


    while (CheckHitKey(KEY_INPUT_ESCAPE) != TRUE) {
        ClearDrawScreen();		//画面の初期化


        for (int i = 0; i < STAGE_WIDTH; i++) {
            for (int j = 0; j < STAGE_HEIGHT; j++) {
                if (StagePixel[i][j] == 1) {
                    DrawBox(i * DOT_SIZE, j * DOT_SIZE, i * DOT_SIZE + DOT_SIZE, j * DOT_SIZE + DOT_SIZE, 0xff00ff, TRUE);
                    //DrawPixel(i, j, 0x00ff00);
                }
                else {

                }
            }
        }

        // マウスの位置を取得
        GetMousePoint(&MouseX, &MouseY);


        //DrawFormatString(1000, 580, 0xff00ff, "%d,%d", MouseX / 4, MouseY / 4);
        DrawFormatString(1000, 580, 0xff00ff, "%d,%d", MouseX, MouseY);

        if (GetPixel(MouseX, MouseY) == 0) {

        }
        else {
            DrawString(1000, 560, "Hit", 0x00ff00);
        }

        DrawFormatString(1000, 512, 0xff00ff, "%d,%d", MouseX, MouseY);
        DrawCircle(MouseX, MouseY, 22, 0xf0f0ff);


        ScreenFlip();				//裏画面の内容を表画面に反映


    }


    // キー入力待ちをする


    // ＤＸライブラリの後始末
    DxLib_End();

    // ソフトの終了
    return 0;
}