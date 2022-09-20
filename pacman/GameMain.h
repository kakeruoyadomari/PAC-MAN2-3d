#pragma once
#include "AbstractScene.h"
#include"Object.h"
#include"Player.h"
#include"Esa.h"
#include"Stage.h"
#include"Enemy_Red.h"
#include"Enemy_Orange.h"
#include"Enemy_Pink.h"
#include"Enemy_Cyan.h"

#define D_ESA_MAX 244

class GameMain :
    public AbstractScene
{
private:
    Player* player;
    EsaControll* esacontroll;
    ESA** esa;
    Stage* stage;
    Enemy_Red*enemy_red;
    Enemy_Cyan* enemy_cyan;
    Enemy_Orange* enemy_orange;
    Enemy_Pink* enemy_pink;

    int* stageCount = 0;

    int ExistCount1 = 0;
    int ExistCount2 = 0;

    int AnimeTimer = 0;
    int startTimer = 0;


public:


    GameMain();


    virtual ~GameMain() {};

    virtual AbstractScene* Update(XINPUT_STATE data);

    virtual void Draw() const;

    void ResetMain();
};

