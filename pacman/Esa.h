#pragma once
#include "Object.h"
#include "Player.h"
#include "Stage.h"

#define ESA_MAX 244


class ESA :public Object
{
private:
    //do ƒGƒT‚Ìc‚è‚Ì”‚ğ“ü‚ê‚é•Ï”‚Æget’Ç‰Á
    bool Esaflg;    //flg iranai?
    int EsaImg;
    int EsaScore;

    int Type;
    int FruitsType;
    int FruitsImg;
    int FruitsScore;
public:
    ESA(int X, int Y, int EsaType);
    ESA(int X, int Y, int EsaType, int FruitsType);
    ~ESA();
    static int ResidueEsa;

    //int SetEsaX();
    void SetImage(int i) { EsaImg = i; }
    void ChangeFlg() { Esaflg = !(Esaflg); }
    bool GetFlg() { return Esaflg; }
    int GetType() { return Type; }

    void UpDate() override;
    void Animaition() override;
    void Draw() const override;

};

class EsaControll
{
private:
    ESA* esa[245];
    Stage* stage;
    int EsaImage[2];
    int FruitsImage[8];
    int FruitsType;
    int CreatePieces;
    int EsaType;
    int EsaSE;
    int FruitsX;
    int FruitsY;

    static int esacount;

    int sx;
    int sy;

public:
    EsaControll(Stage* data);
    void CreateFruits();

    void ResetCount() { esacount = 0; }

    ESA** Getesa() { return esa; }
    void SetEsa(int x, int y, Stage* stage);
    void DrawEsa();

};