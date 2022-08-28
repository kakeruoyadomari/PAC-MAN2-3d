#pragma once
#include "Object.h"
#define ACCELERATION 0.05
class Player : public Object
{
private:
    int playerimg[3];   //プレイヤー画像用変数
    int PlayerDirection;
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