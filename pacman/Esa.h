#pragma once
#include "Object.h"
#include "Player.h"
class ESA :public Object
{
private:
    //do エサの残りの数を入れる変数とget追加
    bool Esaflg;
    int EsaImg;
public:
    ESA(int X, int Y);

    //int SetEsaX();
    void SetImage(int i) { EsaImg = i; }
    void ChangeFlg() { Esaflg = FALSE; }
    bool GetFlg() { return Esaflg; }

    void UpDate() override;
    void Animaition() override;
    void Draw() const override;

};

class EsaControll
{
private:
    Player* player;
    ESA* esa[244];
    int EsaImage[2];
    int EsaType;
    int EsaSE;
    int ResidueEsa;
    int SetX;
    int SetY;

public:
    EsaControll();

    ESA** Getesa() { return esa; }
    void SetEsa();
    void DrawEsa();

};