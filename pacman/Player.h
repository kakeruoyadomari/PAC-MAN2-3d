#pragma once
#include "Object.h"
#include"Player.h"
#define ACCELERATION 0.05
#define PLAYER_DRAW_ 11

class Player : public Object
{
private:
    int playerimg[3];   //プレイヤー画像用変数
    int playeranim;         //画像アニメーション用
    float speed;
    int nowdraw;
    float nowdirect;
    int adovanced_direction;

    bool drawflg;       //描画するかのフラグ
    bool ismove;        //現在移動できるかのフラグ
    XINPUT_STATE control;       //コントローラー

    //プレイヤーの向き
    enum Direction
    {
        PLAYER_NORMAL_UP=1,
        PLAYER_NORMAL_RIGHT,
        PLAYER_NORMAL_DOWN,
        PLAYER_NORMAL_LEFT
    };


    struct PlyrDrct
    {
        int x_direction;
        int y_direction;
        int direction;
    };

    struct PlyrDrct plyrdrct;
  /*  float x;
    float y;*/
    // 座標X,Yと半径はobjectクラスで定義済み
public:
    Player();
    Player(Stage*data);
    void PlayerDisplay(void);
    void UpDate() override;
    void Animaition() override;
    void Draw() const override;
    void MovePlayer();
    void Init(XINPUT_STATE data);
    void ResetImage() { nowdraw = playerimg[0]; }
    int GetDirection() { return plyrdrct.direction; }

};

//extern Player;