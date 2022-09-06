#pragma once
#include "DxLib.h"

#define STAGE_WIDTH 40   //幅
#define STAGE_HEIGHT 42 //高さ

#define PI	3.1415926535897932384626433832795f

class Stage{
public:
    int MapInit();//datからマップ呼び出し
    int MapSet();//マップ読み込み
    int LoadData();//画像
    int Init();//初期化
    int CheckWall(int cx, int cy, int mx, int my);
    int PakuMove();
    void MainLoop();
};

extern Stage stage;