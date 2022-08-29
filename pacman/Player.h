#pragma once
#include "Object.h"
#define ACCELERATION 0.05
class Player : public Object
{
private:
    int Pad;
    int Move;
    int playerimg[3];   //プレイヤー画像用変数
    int PlayerDirection;    //プレイヤーの向き
    int playeranim;         //画像アニメーション用
    /*int playerrun;
    int playerrun2;*/
    float speed;     //移動速度
    bool flg;
    bool ismove;
    XINPUT_STATE control;
    int playerflg;
    int g_Nowkey;
    int time;
  /*  float x;
    float y;*/
    // 座標X,Yと半径はobjectクラスで定義済み
public:
    Player();
    void PlayerDisplay(void);
    void UpDate() override;
    void Animaition() override;
    void Draw() const override;
    int Image();
    void NotOverhang();
    void MovePlayer();
    void StopMotion(void);
    void Init(XINPUT_STATE data);
    void PlayerControl();
    
};

//extern Player;