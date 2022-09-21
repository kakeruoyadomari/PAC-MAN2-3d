#include "SceneManager.h"


// メンバ変数の値を書き換えるのがアップデート関数
AbstractScene* SceneManager::Update(XINPUT_STATE data) {

	if (data.Buttons[XINPUT_BUTTON_BACK]) {
		return nullptr;
	}

    // 現在シーンのアップデートを実行
    AbstractScene* p = mScene->Update(data);

    // 次のシーンが現在シーンと違う場合切り替える
    if (p != mScene) {
        delete mScene;
        mScene = p;
    }

    return p;
}

// 描画処理のみを行う関数
void SceneManager::Draw() const {
    // 現在シーンの描画関数を実行
    mScene->Draw();
}

XINPUT_STATE SceneManager::ControllerUpdate()
{
	//入力キー取得
	oldkey = nowkey;
	GetJoypadXInputState(DX_INPUT_PAD1, &nowkey);

	for (int i = 0; i < CONTROL_MAX_BOTTUN; i++) {
		genkey.Buttons[i] = nowkey.Buttons[i] & ~oldkey.Buttons[i];
	}
	//スティックの値はそのまま持ってくる
	genkey.LeftTrigger = nowkey.LeftTrigger;
	genkey.RightTrigger = nowkey.RightTrigger;
	genkey.ThumbLX = nowkey.ThumbLX;
	genkey.ThumbLY = nowkey.ThumbLY;
	genkey.ThumbRX = nowkey.ThumbRX;
	genkey.ThumbRY = nowkey.ThumbRY;

    return genkey;
}
