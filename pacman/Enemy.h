#pragma once
#include "Object.h"
#include"Stage.h"
#include"Player.h"

class Enemy : public Object
{
    // 座標X,Yと半径はobjectクラスで定義済み
protected:
    bool animeFlg=false;      //アニメーションフラグ
    int animcount=0;      //アニメーションの秒数
    bool nowflg=false;      //現在のアニメーションの切り替わり
    bool nowflg2 = false;
    static bool allenemyijike;

    static Player* player;

    static Enemy* enemy_red;

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
    };

    struct EnemyDrct enemydic;

    //全てのエネミーで共通のもの
    int ijikeimage1[2]{0,0};      //いじけ状態黒
    int ijikeimage2[2]{0,0};      //いじけ状態白
    int medamaimage[4]{0,0,0,0};     //目玉状態
    static bool trackFlg;      //追いかけるフラグ
    static bool HitFlg;        //Playerとの当たり判定
    static int hometimer;       //巣の中の動きに使う時間
    static int ijikecount;      //いじけの制限時間
    static float speed;     //全体のスピード
    static float ijikespeed;        //全体のいじけスピード
    static float tunnelspeed;       //全体のトンネルスピード
    static int tracktime;       //全体の追いかける制限時間
    static int trackcount;      //全体の追いかけている時間
    static int trackchange;     //ラウンドごとの追いかけるタイミング記録
    static int trackchangecount;        //ラウンドごとの追いかけるタイミングカウント
    static int backspeed;


    //それぞれで中身が変わる変数
    int image1[2]{0,0};      //画像１の差分２枚
    int image2[2]{0,0};      //画像２の差分２枚
    int image3[2]{0,0};      //画像３の差分２枚
    int image4[2]{0,0};      //画像４の差分２枚
    bool HomeExistFlg = false;
    int nowway = 0;     //現在の向き
    int nowdraw = 0;      //現在の描画
    bool existhome = false;    
    bool existedanim = false;
    int targetxpoint = 0;
    int targetypoint = 0;
    bool enemyijike = false;        //個別のいじけ状態
    bool medama = false;   
    int ijiketimer = 0;      //いじけの残り時間
    bool backflg = false;

    void Rocation(int px, int py, int ex, int ey, int* dic, int* dicX, int* dicY);

    void RunAway(int px, int py, int ex, int ey, int* dic, int* dicX, int* dicY);

    virtual void TargetRocation(float, float, int) =0;

public:

    Enemy();

    virtual void GetExistHome(bool data) {  existhome = data; }

    void ExistAnime(Enemy * data);

    virtual void SetXDirection(int data) { enemydic.x_direction = data; }
    void SetYDirection(int data) { enemydic.y_direction = data; }
    void SetDirection(int data) { enemydic.direction = data; }

    void ChangeIjike() { enemyijike = true; }
    void ChangeAllIjike() { allenemyijike = true; }
    bool GetIjikeFlg() { return enemyijike; }
    bool GetExistFlg(){return existedanim;}

    void EnemyTrackCounter(bool, bool, bool, bool);

    void ResetPosition(int x, int y);

   virtual void SetStageCount(int* data) { stageCount = data; }

};

