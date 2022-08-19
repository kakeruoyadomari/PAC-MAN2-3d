#include "DxLib.h"
#include<stdio.h>

#pragma warning(disable:4996)


#define STAGE_WIDTH 232         //�摜�̉��̃h�b�g��
#define STAGE_HEIGHT 256        //�摜�̏c�̃h�b�g��

FILE* fp;

int StageImage;
int StagePixel[STAGE_WIDTH][STAGE_HEIGHT];

bool flg = FALSE;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
    ChangeWindowMode(TRUE);

    SetGraphMode(1920, 1080, 32);


    SetBackgroundColor(255, 255, 255);


    // �c�w���C�u�����̏�����
    if (DxLib_Init() < 0)
    {
        // �G���[�����������璼���ɏI��
        return -1;
    }
   
    StageImage = LoadGraph("Image/stage.png");          //�����ŉ摜�̑I��

    SetDrawScreen(DX_SCREEN_BACK);


    while (flg==FALSE) {
        ClearDrawScreen();		//��ʂ̏�����

        DrawGraph(0, 0, StageImage, TRUE);

        ScreenFlip();				//����ʂ̓��e��\��ʂɔ��f


        for (int i = 0; i < STAGE_WIDTH; i++) {
            for (int j = 0; j < STAGE_HEIGHT; j++) {
                /*if (GetPixel(i, j) == -1) {
                    StagePixel[i][j] = 0;
                }
                else {
                    StagePixel[i][j] = 1;
                }*/     //0,1�ŕ\��

                StagePixel[i][j] = GetPixel(i, j);          //�摜�̐F
            }
        }

        fopen_s(&fp, "dat/stagedata.txt", "w");         //�ǂݍ��܂���e�L�X�g�t�@�C���̖��O
        //�t�@�C�����[�h
        for (int i = 0; i < STAGE_WIDTH; i++) {
            for (int j = 0; j < STAGE_HEIGHT; j++) {
               fprintf_s(fp , "%d," , StagePixel[i][j]);
            }
            fprintf(fp, "\n");
        }
        //�t�@�C���N���[�Y
        fclose(fp);

        flg = TRUE;


    }
       

    // �L�[���͑҂�������
    

    // �c�w���C�u�����̌�n��
    DxLib_End();

    // �\�t�g�̏I��
    return 0;
}