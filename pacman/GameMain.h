#pragma once
#include "AbstractScene.h"
#include"Object.h"
#include"Player.h"


class GameMain :
    public AbstractScene
{
private:
    Object* obj;
    Player* player;

public:


    GameMain();

    // デストラクタ
    virtual ~GameMain() {};

    //描画以外の更新を実装する
    virtual AbstractScene* Update(XINPUT_STATE data);

    //描画に関することを実装する
    virtual void Draw() const;

};

