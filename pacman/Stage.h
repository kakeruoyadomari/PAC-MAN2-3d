#pragma once
#include "DxLib.h"

#define STAGE_WIDTH 464
#define STAGE_HEIGHT 512

class Stage{
public:
    int MapInit();//dat����}�b�v�Ăяo��
    int MapSet();//�}�b�v�ǂݍ���
    int LoadData();//�摜
};

extern Stage stage;