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


    // �c�w���C�u�����̏�����
    if (DxLib_Init() < 0)
    {
        // �G���[�����������璼���ɏI��
        return -1;
    }

    // �}�E�X��\����Ԃɂ���
    SetMouseDispFlag(TRUE);

    fopen_s(&fp, "dat/stagedata.txt", "r");

    //�t�@�C�����[�h
    for (int i = 0; i < STAGE_WIDTH; i++) {
        for (int j = 0; j < STAGE_HEIGHT; j++) {
            fscanf(fp, "%d,", &StagePixel[i][j]);
        }
    }

    //�t�@�C���N���[�Y
    fclose(fp);

    SetDrawScreen(DX_SCREEN_BACK);


    while (CheckHitKey(KEY_INPUT_ESCAPE) != TRUE) {
        ClearDrawScreen();		//��ʂ̏�����


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

        // �}�E�X�̈ʒu���擾
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


        ScreenFlip();				//����ʂ̓��e��\��ʂɔ��f


    }


    // �L�[���͑҂�������


    // �c�w���C�u�����̌�n��
    DxLib_End();

    // �\�t�g�̏I��
    return 0;
}