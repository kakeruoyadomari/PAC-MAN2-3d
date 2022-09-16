#pragma once
#include "AbstractScene.h"
#include"Object.h"
#include"Player.h"
#include"Esa.h"
#include"Stage.h"
#include"Enemy_Red.h"

#define D_ESA_MAX 244

class GameMain :
    public AbstractScene
{
private:
    Object* obj;
    Player* player;
    EsaControll* esacontroll;
    ESA** esa;
    Stage* stage;
    Enemy_Red* enemy_red;

    int* stageCount = 0;


public:


    GameMain();

    // �f�X�g���N�^
    virtual ~GameMain() {};

    //�`��ȊO�̍X�V����������
    virtual AbstractScene* Update(XINPUT_STATE data);

    //�`��Ɋւ��邱�Ƃ���������
    virtual void Draw() const;

};

