#pragma once
#include "Object.h"
class Player :
    public Object
{
private:
    int x=0;

public:
    void UpData() override;
    void Draw() const override;

};

