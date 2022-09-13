#pragma once
#include "Object.h"
#include"Stage.h"


class Enemy : public Object
{
    // 座標X,Yと半径はobjectクラスで定義済み
protected:
    //全てのエネミーが持つべき変数
    bool animeFlg=false;      //アニメーションフラグ
    int animcount=0;      //アニメーションの秒数
    static bool trackFlg;      //追いかけるフラグ
    bool ijike=false;     //いじけ状態
    int nowway=0;     //現在の向き
    int nowdraw=0;      //現在の描画
    bool nowflg=false;      //現在のアニメーションの切り替わり
    bool HitFlg = false;        //Playerとの当たり判定
    int TrackTime = 0;

    Object* player;

    enum Direction
    {
        ENEMY_NORMAL_UP=1,
        ENEMY_NORMAL_RIGHT,
        ENEMY_NORMAL_DOWN,
        ENEMY_NORMAL_LEFT,
        ENEMY_IJIKE_BLACK,
        ENEMY_IJIKE_WHITE,
        ENEMY_MEDAMA_UP,
        ENEMY_MEDAMA_RIGHT,
        ENEMY_MEDAMA_DOWN,
        ENEMY_MEDAMA_LEFT
    };

    struct EnemyDrct
    {
        int x_direction;
        int y_direction;
        int direction;
        int old_direction;
    };

    struct EnemyDrct enemydic;

    //全てのエネミーで共通のもの
    int ijikeimage1[2]{0,0};      //いじけ状態黒
    int ijikeimage2[2]{0,0};      //いじけ状態白
    int medamaimage[4]{0,0,0,0};     //目玉状態

    //それぞれで中身が変わる変数
    int speed;      //スピード
    int image1[2]{0,0};      //画像１の差分２枚
    int image2[2]{0,0};      //画像２の差分２枚   
    int image3[2]{0,0};      //画像３の差分２枚
    int image4[2]{0,0};      //画像４の差分２枚

    bool ToggleFlg(bool flg) {flg = !(flg);return flg;}

    bool CheckHitPlayer(int ex, int xy);

    void AStar(int ex,int ey,int px,int py);

    void Rocation(int px, int py, int ex, int ey, int* dic, int* dicX, int* dicY);

    int RocationScore(int px,int py,int ex, int ey, int dic);

public:
    Enemy();
};

