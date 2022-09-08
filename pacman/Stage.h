#pragma once
#pragma warning(disable:4996)
#include "DxLib.h"

#define STAGE_WIDTH 14
#define STAGE_HEIGHT 31
#define DOT_SIZE 22

#define PI	3.1415926535897932384626433832795f

class Stage{
private:
    int StagePixel[STAGE_WIDTH][STAGE_HEIGHT];
    int StageReverse[STAGE_WIDTH][STAGE_HEIGHT];

    int StageTS[STAGE_WIDTH * 2][STAGE_HEIGHT];

    int stageselectx;
    int stageselecty;

    FILE* fp;
public:
    int MapInit();//dat����}�b�v�Ăяo��
    int MapSet();//�}�b�v�ǂݍ���
    int LoadData();//�摜
    int Init();//������
    int CheckWall(int cx, int cy, int mx, int my);
    int PakuMove();
    void MainLoop();
    int GetStageData(int i, int j) { return StageTS[i][j]; }
};

extern Stage stage;