#pragma once
#include "Object.h"
class Enemy :
    public Object
{
private:
    int x = 0;
    int y = 0;
    int h = 0;
    int w = 0;
    int radius;

    bool animeFlg = FALSE;

public:
    void UpData() override;
    void Animaition() override;
    void Draw() const override;

};

