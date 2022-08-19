#include "DxLib.h"
#include<stdio.h>

#pragma warning(disable:4996)


#define STAGE_WIDTH 232         //画像の横のドット数
#define STAGE_HEIGHT 256        //画像の縦のドット数

FILE* fp;

int StageImage;
int StagePixel[STAGE_WIDTH][STAGE_HEIGHT];

bool flg = FALSE;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
    ChangeWindowMode(TRUE);

    SetGraphMode(1920, 1080, 32);


    SetBackgroundColor(255, 255, 255);


    // ＤＸライブラリの初期化
    if (DxLib_Init() < 0)
    {
        // エラーが発生したら直ちに終了
        return -1;
    }
   
    StageImage = LoadGraph("Image/stage.png");          //ここで画像の選択

    SetDrawScreen(DX_SCREEN_BACK);


    while (flg==FALSE) {
        ClearDrawScreen();		//画面の初期化

        DrawGraph(0, 0, StageImage, TRUE);

        ScreenFlip();				//裏画面の内容を表画面に反映


        for (int i = 0; i < STAGE_WIDTH; i++) {
            for (int j = 0; j < STAGE_HEIGHT; j++) {
                /*if (GetPixel(i, j) == -1) {
                    StagePixel[i][j] = 0;
                }
                else {
                    StagePixel[i][j] = 1;
                }*/     //0,1で表現

                StagePixel[i][j] = GetPixel(i, j);          //画像の色
            }
        }

        fopen_s(&fp, "dat/stagedata.txt", "w");         //読み込ませるテキストファイルの名前
        //ファイルロード
        for (int i = 0; i < STAGE_WIDTH; i++) {
            for (int j = 0; j < STAGE_HEIGHT; j++) {
               fprintf_s(fp , "%d," , StagePixel[i][j]);
            }
            fprintf(fp, "\n");
        }
        //ファイルクローズ
        fclose(fp);

        flg = TRUE;


    }
       

    // キー入力待ちをする
    

    // ＤＸライブラリの後始末
    DxLib_End();

    // ソフトの終了
    return 0;
}