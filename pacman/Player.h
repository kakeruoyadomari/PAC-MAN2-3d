#pragma once
#include "Object.h"
class Player : public Object
{
    // ���WX,Y�Ɣ��a��object�N���X�Œ�`�ς�
public:
    void UpDate() override;
    void Animaition() override;
    void Draw() const override;

};

