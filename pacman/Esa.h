#pragma once
#include "Object.h"
class ESA :public Object
{
private:
    //do ƒGƒT‚Ìc‚è‚Ì”‚ğ“ü‚ê‚é•Ï”‚Æget’Ç‰Á
    bool Esaflg;
    int EsaImg;
public:
    ESA(int X, int Y);

    //int SetEsaX();
    void SetImage(int i) { EsaImg = i; }
    bool GetFlg() { return Esaflg; }

    void UpDate() override;
    void Animaition() override;
    void Draw() const override;

};

class EsaControll
{
private:
    ESA* esa[244];
    int EsaImage[2];
    int EsaType;
    int EsaSE;
    int ResidueEsa;
    int SetX;
    int SetY;

public:
    EsaControll();

    void SetEsa();
    void DrawEsa();
};