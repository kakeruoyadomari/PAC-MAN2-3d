#pragma once
#include "Object.h"
class Player :
    public Object
{
private:
    int x = 0;
    int y = 0;
    int h = 0;
    int w = 0;
    int radius;

public:
    void UpDate() override;
    void Animaition() override;
    void Draw() const override;

};

