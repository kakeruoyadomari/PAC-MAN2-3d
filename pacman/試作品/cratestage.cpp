//#include "DxLib.h"
//
//
//#define STAGE_WIDTH 232
//#define STAGE_HEIGHT 256
//
//int StagePixel[STAGE_WIDTH][STAGE_HEIGHT];
//
//FILE* fp;
//#pragma warning(disable:4996)
//
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//    SetGraphMode(1920, 1080, 32);
//    ChangeWindowMode(TRUE);
//
//
//    SetBackgroundColor(255, 255, 255);
//
//
//    // �c�w���C�u�����̏�����
//    if (DxLib_Init() < 0)
//    {
//        // �G���[�����������璼���ɏI��
//        return -1;
//    }
//
//    fopen_s(&fp, "dat/stagedata.txt", "r");
//
//    //�t�@�C�����[�h
//    for (int i = 0; i < STAGE_WIDTH; i++) {
//        for (int j = 0; j < STAGE_HEIGHT; j++) {
//            fscanf(fp, "%d,", &StagePixel[i][j]);
//        }
//    }
//
//    //�t�@�C���N���[�Y
//    fclose(fp);
//
//    SetDrawScreen(DX_SCREEN_BACK);
//
//
//    while (GetJoypadInputState(KEY_INPUT_ESCAPE)!=TRUE) {
//        ClearDrawScreen();		//��ʂ̏�����
//
//
//        for (int i = 0; i < STAGE_WIDTH; i++) {
//            for (int j = 0; j < STAGE_HEIGHT; j++) {
//                if (StagePixel[i][j] ==1) {
//                    //DrawBox(i * 4, j * 4, i * 4 + 4, j * 4 + 4, 0xff00ff, TRUE);
//                    DrawPixel(i, j, 0x00ff00);
//                }
//                else {
//
//                }
//            }
//        }
//        
//        ScreenFlip();				//����ʂ̓��e��\��ʂɔ��f
//
//
//    }
//       
//
//    // �L�[���͑҂�������
//    
//
//    // �c�w���C�u�����̌�n��
//    DxLib_End();
//
//    // �\�t�g�̏I��
//    return 0;
//}