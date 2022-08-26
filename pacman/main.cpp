#include"DxLib.h"
#include"SceneManager.h"
#include"Title.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(1280, 720, 16);


	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_DESKTOP);
	//SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_MAXIMUM);  

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);


	SceneManager scene(new Title());

	while (scene.Update(scene.ControllerUpdate()) != nullptr)
	{
		ClearDrawScreen();		//��ʂ̏�����
		scene.Draw();
		ScreenFlip();				//����ʂ̓��e��\��ʂɔ��f
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}