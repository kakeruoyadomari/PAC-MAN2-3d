#pragma once
#include "Object.h"
#include "Player.h"
class ESA :public Object
{
private:
    //do ƒGƒT‚Ìc‚è‚Ì”‚ğ“ü‚ê‚é•Ï”‚Æget’Ç‰Á
    bool Esaflg;    //flg iranai?
    int EsaImg;
    int EsaScore;

    int Type;
    int FruitsImg;
    int FruitsScore;
public:
    ESA(int X, int Y, int EsaType);
    ESA(int X, int Y, int EsaType, int FruitsType);
    ~ESA();
    static int ResidueEsa;

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
    ESA* esa[245];
    int EsaImage[2];
    int FruitsImage[8];
    int CreatePieces;
    int EsaType;
    int EsaSE;
    int SetX;
    int SetY;

public:
    EsaControll();
    void CreateFruits();

    ESA** Getesa() { return esa; }
    void SetEsa();
    void DrawEsa();
};