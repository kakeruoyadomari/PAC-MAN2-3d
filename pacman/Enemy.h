#pragma once
#include "Object.h"
class Enemy :
    public Object
{
    // 座標X,Yと半径はobjectクラスで定義済み
protected:
    bool animeFlg;
    int ijikeimage[4];
    int medamaimage[4];

public:
    Enemy();
};

