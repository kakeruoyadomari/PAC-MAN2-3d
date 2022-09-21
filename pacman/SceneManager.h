#pragma once
#include"DxLib.h"
#include "AbstractScene.h"

#define CONTROL_MAX_BOTTUN 16

// �V�[���}�l�[�W���[�N���X
// �e�V�[���̐؂�ւ����Ǘ�����B
class SceneManager : public AbstractScene {
private:
    AbstractScene* mScene;  // ���݂̃V�[��

    XINPUT_STATE nowkey;
    XINPUT_STATE oldkey;
    XINPUT_STATE genkey;

    int* stageCount;
    int* PlayerLife;

public:
    // �R���X�g���N�^
    SceneManager(AbstractScene* scene)
        : mScene(scene) {}

    // �f�X�g���N�^
    ~SceneManager() {
        delete mScene;
    }

    //�`��ȊO�̍X�V����������
    AbstractScene* Update(XINPUT_STATE data) override;

    //�`��Ɋւ��邱�Ƃ���������
    void Draw() const override;

    XINPUT_STATE ControllerUpdate();
};