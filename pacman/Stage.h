#pragma once
#include "DxLib.h"

#define STAGE_WIDTH 464
#define STAGE_HEIGHT 512

class Stage{
public:
    int MapInit();//datからマップ呼び出し
    int MapSet();//マップ読み込み
    int LoadData();//画像
};

extern Stage stage;