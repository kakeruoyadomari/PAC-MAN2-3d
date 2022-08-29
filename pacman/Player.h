#pragma once
#include "Object.h"
#define ACCELERATION 0.05
class Player : public Object
{
private:
    int Pad;
    int Move;
    int playerimg[3];   //�v���C���[�摜�p�ϐ�
    int PlayerDirection;    //�v���C���[�̌���
    int playeranim;         //�摜�A�j���[�V�����p
    /*int playerrun;
    int playerrun2;*/
    float speed;     //�ړ����x
    bool flg;
    bool ismove;
    XINPUT_STATE control;
    int playerflg;
    int g_Nowkey;
    int time;
  /*  float x;
    float y;*/
    // ���WX,Y�Ɣ��a��object�N���X�Œ�`�ς�
public:
    Player();
    void PlayerDisplay(void);
    void UpDate() override;
    void Animaition() override;
    void Draw() const override;
    int Image();
    void NotOverhang();
    void MovePlayer();
    void StopMotion(void);
    void Init(XINPUT_STATE data);
    void PlayerControl();
    
};

//extern Player;