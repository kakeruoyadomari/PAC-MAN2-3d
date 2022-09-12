#pragma once
#include "Object.h"
#define ACCELERATION 0.05
class Player : public Object
{
private:
    int playerimg[3];   //プレイヤー画像用変数
    int PlayerDirection;    //プレイヤーの向き
    int playeranim;         //画像アニメーション用
    int speed;
    int movepixel;
    
    int playerzanki;

    bool flg;
    bool ismove;
    XINPUT_STATE control;
    
public:
    Player();
    void PlayerDisplay(void);
    void UpDate() override;
    void Animaition() override;
    void Draw() const override;
    int Image();
    void MovePlayer();
    void Init(XINPUT_STATE data);
    void Speedflg();
    
};
