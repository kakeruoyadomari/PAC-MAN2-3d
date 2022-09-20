#include "SceneManager.h"


// �����o�ϐ��̒l������������̂��A�b�v�f�[�g�֐�
AbstractScene* SceneManager::Update(XINPUT_STATE data) {

	if (data.Buttons[XINPUT_BUTTON_BACK]) {
		return nullptr;
	}

    // ���݃V�[���̃A�b�v�f�[�g�����s
    AbstractScene* p = mScene->Update(data);

    // ���̃V�[�������݃V�[���ƈႤ�ꍇ�؂�ւ���
    if (p != mScene) {
        delete mScene;
        mScene = p;
    }

    return p;
}

// �`�揈���݂̂��s���֐�
void SceneManager::Draw() const {
    // ���݃V�[���̕`��֐������s
    mScene->Draw();
}

XINPUT_STATE SceneManager::ControllerUpdate()
{
	//���̓L�[�擾
	oldkey = nowkey;
	GetJoypadXInputState(DX_INPUT_PAD1, &nowkey);

	for (int i = 0; i < CONTROL_MAX_BOTTUN; i++) {
		genkey.Buttons[i] = nowkey.Buttons[i] & ~oldkey.Buttons[i];
	}
	//�X�e�B�b�N�̒l�͂��̂܂܎����Ă���
	genkey.LeftTrigger = nowkey.LeftTrigger;
	genkey.RightTrigger = nowkey.RightTrigger;
	genkey.ThumbLX = nowkey.ThumbLX;
	genkey.ThumbLY = nowkey.ThumbLY;
	genkey.ThumbRX = nowkey.ThumbRX;
	genkey.ThumbRY = nowkey.ThumbRY;

    return genkey;
}
