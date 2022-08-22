#pragma once
#include "Object.h"
class Esa :public Object
{
private:
    int EsaImg;
    int PowerEsaImg;
public:
    Esa();

    void UpDate() override;
    void Animaition() override;
    void Draw() const override;

};

