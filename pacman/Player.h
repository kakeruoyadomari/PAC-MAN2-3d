#pragma once
#include "Object.h"
class Player : public Object
{
    // 座標X,Yと半径はobjectクラスで定義済み
public:
    void UpDate() override;
    void Animaition() override;
    void Draw() const override;

};

