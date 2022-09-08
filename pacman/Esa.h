#pragma once
#include "Object.h"
#include "Player.h"
class ESA :public Object
{
private:
    //do エサの残りの数を入れる変数とget追加
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
    Player* player;
    ESA* esa[245];
    int EsaImage[2];
    int FruitsImage[8];
    int FruitsType;
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