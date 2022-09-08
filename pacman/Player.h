#pragma once
#include "Object.h"
#include"Player.h"
#define ACCELERATION 0.05
class Player : public Object
{
private:
    int playerimg[3];   //プレイヤー画像用変数
    //int PlayerDirection;    //プレイヤーの向き
    int playeranim;         //画像アニメーション用
    int speed;
    int movepixel;
    int nowdraw;
    float nowdirect;
    int moveX;
    int moveY;
    /*int playerrun;
    int playerrun2;*/
    bool drawflg;       //描画するかのフラグ
    bool ismove;        //現在移動できるかのフラグ
    XINPUT_STATE control;       //コントローラー
    int playerflg;
    int time;

    //プレイヤーの向き
    enum Direction
    {
        PLAYER_NORMAL_UP,
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
    Player(Stage*data);
    void PlayerDisplay(void);
    void UpDate() override;
    void Animaition() override;
    void Draw() const override;
    int Image();
    void MovePlayer();
    void Init(XINPUT_STATE data);

    bool CheckHitWall(int, int, int);
};

//extern Player;