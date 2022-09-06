#pragma once
#include "DxLib.h"

#define STAGE_WIDTH 40   //��
#define STAGE_HEIGHT 42 //����

#define PI	3.1415926535897932384626433832795f

class Stage{
public:
    int MapInit();//dat����}�b�v�Ăяo��
    int MapSet();//�}�b�v�ǂݍ���
    int LoadData();//�摜
    int Init();//������
    int CheckWall(int cx, int cy, int mx, int my);
    int PakuMove();
    void MainLoop();
};

extern Stage stage;