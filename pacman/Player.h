#pragma once
#include "Object.h"
#include"Player.h"
#define ACCELERATION 0.05
#define PLAYER_DRAW_ 11

class Player : public Object
{
private:
    int playerimg[3];   //�v���C���[�摜�p�ϐ�
    int playeranim;         //�摜�A�j���[�V�����p
    float speed;
    int nowdraw;
    float nowdirect;
    int adovanced_direction;

    bool drawflg;       //�`�悷�邩�̃t���O
    bool ismove;        //���݈ړ��ł��邩�̃t���O
    XINPUT_STATE control;       //�R���g���[���[

    //�v���C���[�̌���
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
    // ���WX,Y�Ɣ��a��object�N���X�Œ�`�ς�
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