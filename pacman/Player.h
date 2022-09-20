#pragma once
#include "Object.h"
#include"Player.h"
#define ACCELERATION 0.05
#define PLAYER_DRAW_ 11
#define PLAYER_NORMAL_SPEED 1
#define PLAYER_ESA_SPEED 0.3

class Player : public Object
{
private:
    int playerimg[3];   //プレイヤー画像用変数
    //int PlayerDirection;    //プレイヤーの向き
    int playeranim;         //画像アニメーション用
    float speed;
    int speed_player;
    int movepixel;
    int nowdraw;
    float nowdirect;
    int adovanced_direction;
    int moveX;
    int moveY;
    /*int playerrun;
    int playerrun2;*/
    bool drawflg;       //描画するかのフラグ
    bool ismove;        //現在移動できるかのフラグ
    XINPUT_STATE control;       //コントローラー
    int playerflg;
    int time;
    int playerzanki;
    bool GetEsaflg;
    //プレイヤーの向き
    enum Direction
    {
        PLAYER_NORMAL_UP=1,
        PLAYER_NORMAL_RIGHT,
        PLAYER_NORMAL_DOWN,
        PLAYER_NORMAL_LEFT,

        PLAYER_SPEED
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
    void GetEsaFlg() { GetEsaflg = !GetEsaflg; }
    void ChangeSpeed();
    void Init(XINPUT_STATE data);

};

//extern Player;