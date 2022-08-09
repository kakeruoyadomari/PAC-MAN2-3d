#include"DxLib.h"
#include"SceneManager.h"
#include"Title.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(1280, 720, 32);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);


	SceneManager scene(new Title());

	while (scene.Update(scene.ControllerUpdate()) != nullptr)
	{
		ClearDrawScreen();		//画面の初期化
		scene.Draw();
		ScreenFlip();				//裏画面の内容を表画面に反映

	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}