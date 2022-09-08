#pragma once
#include "Object.h"
#include"Player.h"
#define ACCELERATION 0.05
class Player : public Object
{
private:
    int playerimg[3];   //�v���C���[�摜�p�ϐ�
    //int PlayerDirection;    //�v���C���[�̌���
    int playeranim;         //�摜�A�j���[�V�����p
    int speed;
    int movepixel;
    int nowdraw;
    float nowdirect;
    int moveX;
    int moveY;
    /*int playerrun;
    int playerrun2;*/
    bool drawflg;       //�`�悷�邩�̃t���O
    bool ismove;        //���݈ړ��ł��邩�̃t���O
    XINPUT_STATE control;       //�R���g���[���[
    int playerflg;
    int time;

    //�v���C���[�̌���
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
    // ���WX,Y�Ɣ��a��object�N���X�Œ�`�ς�
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