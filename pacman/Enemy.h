#pragma once
#include "Object.h"
#include"Stage.h"


class Enemy : public Object
{
    // ���WX,Y�Ɣ��a��object�N���X�Œ�`�ς�
protected:
    //�S�ẴG�l�~�[�����ׂ��ϐ�
    bool animeFlg=false;      //�A�j���[�V�����t���O
    int animcount=0;      //�A�j���[�V�����̕b��
    static bool trackFlg;      //�ǂ�������t���O
    bool ijike=false;     //���������
    int nowway=0;     //���݂̌���
    int nowdraw=0;      //���݂̕`��
    bool nowflg=false;      //���݂̃A�j���[�V�����̐؂�ւ��
    bool HitFlg = false;        //Player�Ƃ̓����蔻��
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

    //�S�ẴG�l�~�[�ŋ��ʂ̂���
    int ijikeimage1[2]{0,0};      //��������ԍ�
    int ijikeimage2[2]{0,0};      //��������Ԕ�
    int medamaimage[4]{0,0,0,0};     //�ڋʏ��

    //���ꂼ��Œ��g���ς��ϐ�
    int speed;      //�X�s�[�h
    int image1[2]{0,0};      //�摜�P�̍����Q��
    int image2[2]{0,0};      //�摜�Q�̍����Q��   
    int image3[2]{0,0};      //�摜�R�̍����Q��
    int image4[2]{0,0};      //�摜�S�̍����Q��

    bool ToggleFlg(bool flg) {flg = !(flg);return flg;}

    bool CheckHitPlayer(int ex, int xy);

    void AStar(int ex,int ey,int px,int py);

    void Rocation(int px, int py, int ex, int ey, int* dic, int* dicX, int* dicY);

    int RocationScore(int px,int py,int ex, int ey, int dic);

public:
    Enemy();
};

