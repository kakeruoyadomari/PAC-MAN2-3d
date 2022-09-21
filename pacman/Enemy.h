#pragma once
#include "Object.h"
#include"Stage.h"
#include"Player.h"

class Enemy : public Object
{
    // ���WX,Y�Ɣ��a��object�N���X�Œ�`�ς�
protected:
    bool animeFlg=false;      //�A�j���[�V�����t���O
    int animcount=0;      //�A�j���[�V�����̕b��
    bool nowflg=false;      //���݂̃A�j���[�V�����̐؂�ւ��
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

    //�S�ẴG�l�~�[�ŋ��ʂ̂���
    int ijikeimage1[2]{0,0};      //��������ԍ�
    int ijikeimage2[2]{0,0};      //��������Ԕ�
    int medamaimage[4]{0,0,0,0};     //�ڋʏ��
    static bool trackFlg;      //�ǂ�������t���O
    static bool HitFlg;        //Player�Ƃ̓����蔻��
    static int hometimer;       //���̒��̓����Ɏg������
    static int ijikecount;      //�������̐�������
    static float speed;     //�S�̂̃X�s�[�h
    static float ijikespeed;        //�S�̂̂������X�s�[�h
    static float tunnelspeed;       //�S�̂̃g���l���X�s�[�h
    static int tracktime;       //�S�̂̒ǂ������鐧������
    static int trackcount;      //�S�̂̒ǂ������Ă��鎞��
    static int trackchange;     //���E���h���Ƃ̒ǂ�������^�C�~���O�L�^
    static int trackchangecount;        //���E���h���Ƃ̒ǂ�������^�C�~���O�J�E���g
    static int backspeed;


    //���ꂼ��Œ��g���ς��ϐ�
    int image1[2]{0,0};      //�摜�P�̍����Q��
    int image2[2]{0,0};      //�摜�Q�̍����Q��
    int image3[2]{0,0};      //�摜�R�̍����Q��
    int image4[2]{0,0};      //�摜�S�̍����Q��
    bool HomeExistFlg = false;
    int nowway = 0;     //���݂̌���
    int nowdraw = 0;      //���݂̕`��
    bool existhome = false;    
    bool existedanim = false;
    int targetxpoint = 0;
    int targetypoint = 0;
    bool enemyijike = false;        //�ʂ̂��������
    bool medama = false;   
    int ijiketimer = 0;      //�������̎c�莞��
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

