#pragma once
#include "Object.h"
class Enemy :
    public Object
{
    // ���WX,Y�Ɣ��a��object�N���X�Œ�`�ς�
protected:
    bool animeFlg;
    int ijikeimage[4];
    int medamaimage[4];

public:
    Enemy();
};

