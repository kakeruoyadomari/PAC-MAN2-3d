#pragma once
#include "Object.h"
#define ACCELERATION 0.05
class Player : public Object
{
private:
    int playerimg[3];   //�v���C���[�摜�p�ϐ�
    int PlayerDirection;    //�v���C���[�̌���
    int playeranim;         //�摜�A�j���[�V�����p
    int speed;
    int movepixel;
    
    int playerzanki;

    bool flg;
    bool ismove;
    XINPUT_STATE control;
    
public:
    Player();
    void PlayerDisplay(void);
    void UpDate() override;
    void Animaition() override;
    void Draw() const override;
    int Image();
    void MovePlayer();
    void Init(XINPUT_STATE data);
    void Speedflg();
    
};
