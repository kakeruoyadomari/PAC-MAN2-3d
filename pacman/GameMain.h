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

    // �f�X�g���N�^
    virtual ~GameMain() {};

    //�`��ȊO�̍X�V����������
    virtual AbstractScene* Update(XINPUT_STATE data);

    //�`��Ɋւ��邱�Ƃ���������
    virtual void Draw() const;

};

