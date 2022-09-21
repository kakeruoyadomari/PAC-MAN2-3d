#pragma once
#include"DxLib.h"
#include "AbstractScene.h"

#define CONTROL_MAX_BOTTUN 16

// シーンマネージャークラス
// 各シーンの切り替えを管理する。
class SceneManager : public AbstractScene {
private:
    AbstractScene* mScene;  // 現在のシーン

    XINPUT_STATE nowkey;
    XINPUT_STATE oldkey;
    XINPUT_STATE genkey;

    int* stageCount;
    int* PlayerLife;

public:
    // コンストラクタ
    SceneManager(AbstractScene* scene)
        : mScene(scene) {}

    // デストラクタ
    ~SceneManager() {
        delete mScene;
    }

    //描画以外の更新を実装する
    AbstractScene* Update(XINPUT_STATE data) override;

    //描画に関することを実装する
    void Draw() const override;

    XINPUT_STATE ControllerUpdate();
};