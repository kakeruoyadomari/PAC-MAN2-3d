#include "DxLib.h"
#include"Stage.h"
#include <fstream>

Stage stage;

// �O���[�o���ϐ�>_<
int gPacman[10];			// �p�b�N�}���̃O���t�B�b�N�n���h��
int gMapChip[10];			// �}�b�v�`�b�v�̃n���h��
int StagePixel[STAGE_WIDTH][STAGE_HEIGHT];
int gScore;					// ���_

// �摜�̓ǂݍ���
int Stage::LoadData()
{
	// �摜�̓ǂݍ���
	if (LoadDivGraph("images/pacman2.png", 10, 10, 1, 24, 24, gPacman) == -1) {
		MessageBox(NULL, "images/pacman2.png", "ReadError", MB_OK);
		return -1;
	}
	if (LoadDivGraph("images/mapchip2.png", 5, 5, 1, 8, 8, gMapChip) == -1) {
		MessageBox(NULL, "images/mapchip2.png", "ReadError", MB_OK);
		return -1;
	}

	return 0;
}

// �}�b�v�̓ǂݍ���
int Stage::MapInit()
{
	int FileHandle = FileRead_open("dat/stagedata0829.txt");		// �t�@�C���̃I�[�v��
	int FileSize = FileRead_size("dat/stagedata0829.txt");			// �t�@�C���T�C�Y���擾����
	char* FileImage = new char[FileSize];					// ���̑傫�������̈�m��
	FileRead_read(FileImage, FileSize, FileHandle);			// ��C�ǂ�
	FileRead_close(FileHandle);								// �t�@�C������ďI��

	const char* d = FileImage;
	int sx = 0, sy = 0;
	int o;

	while (*d != '\0') { // NULL�����i�I�[�j�ł͂Ȃ���
		switch (*d) {
		case '0':	o = 0; break;
		case '1':	o = 3; break;
		case '=':	o = 4; break;
		case '\n':
			sy++;		// ��s���ցA���[��
			sx = 0;		// throw down
		default:	o = 5; break;
		}
		d++;
		if (o != 5) {
			StagePixel[sy][sx] = o;	// �}�b�v��񏑂�����
			sx++;
		}
	}

	return 0;
}

// ������
int Stage::Init()
{
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) return -1;

	SetDrawScreen(DX_SCREEN_BACK);		// ����ʂɏ������݂܂���錾

	if (LoadData() == -1) {
		DxLib_End();
		return -1;
	}
	MapInit();

	// �Q�[���̐ݒ�
	gScore = 0;
	return 0;
}
// �}�b�v�z�u�i���t���[���`��j
int Stage::MapSet()
{
	int sx, sy, st;
	int dot = 0;

	for (sy = 0; sy < 464; sy++) {
		for (sx = 0; sx < 512; sx++) {
			st = StagePixel[sy][sx];
			DrawGraph(sx * 5, sy * 3, gMapChip[st], TRUE);//�}�b�v�̑傫���ύXx��y�c
			if (st == 1 || st == 2) dot++;
		}
	}
	return 0;
}

// �i�s�����ɕǂ��Ȃ����`�F�b�N����
int Stage::CheckWall(int cx, int cy, int mx, int my)
{
	int wall = 0;
	static int dbgx = 0, dbgy = 0;
	if (mx != 0) {
		if (StagePixel[cy - 1][cx + mx * 2] >= 3) wall++;
		if (StagePixel[cy][cx + mx * 2] >= 3) wall++;
		if (StagePixel[cy + 1][cx + mx * 2] >= 3) wall++;
		dbgx = mx; dbgy = my;
	}
	else if (my != 0) {
		if (StagePixel[cy + my * 2][cx - 1] >= 3) wall++;
		if (StagePixel[cy + my * 2][cx] >= 3) wall++;
		if (StagePixel[cy + my * 2][cx + 1] >= 3) wall++;
		dbgx = mx; dbgy = my;
	}

	return wall;
}
// �p�b�N�}�����ړ�����֐�
int Stage::PakuMove()
{
	static int key;
	static int s = 0;			// �p�b�N�}���\���p
	static int x = 18, y = 21;		// �}�b�v���W
	static int dx = 0, dy = 0;	// ���������͗^���Ȃ�
	static float Angle = 0.0f;	// �����@������
	static int mv = 0;			// �p�b�N�}���ړ���
	int mvx = 0, mvy = 0;

	key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (key & PAD_INPUT_START) return -1;		// PAD_INPUT_START  [ESC]Key

	if (mv == 0) {
		//if (mv == 0) {
			//		// ��������
			//		if (gMap[y][x] == 1) {
			//			// Sound�u�ς����I�I�v
			//			gScore += 10;
			//			gMap[y][x] = 0;
			//		}
			//		if (gMap[y][x] == 2) {
			//			// �p���[�a�H�ׂ�
			//			gScore += 50;
			//			gMap[y][x] = 0;
			//		}
		// ��������
		if (StagePixel[y][x] == 0) {
			// Sound�u�ς����I�I�v
			gScore += 10;
			StagePixel[y][x] = 1;//�a�ňړ����Ă�Ƃ�����݂Ă�
		}

		// �}�X�ڂɂ���Ƃ������L�[���͔���
		mv = 16;
		if (key & PAD_INPUT_UP) {
			if (!CheckWall(x, y, 0, -1)) {
				dx = 0; dy = -1; Angle = PI / 2;
			}
		}
		else if (key & PAD_INPUT_DOWN) {
			if (!CheckWall(x, y, 0, 1)) {
				dx = 0; dy = 1; Angle = -PI / 2;
			}
		}
		else if (key & PAD_INPUT_LEFT) {
			if (!CheckWall(x, y, -1, 0)) {
				dx = -1; dy = 0; Angle = 0;
			}
		}
		else if (key & PAD_INPUT_RIGHT) {
			if (!CheckWall(x, y, 1, 0)) {
				dx = 1; dy = 0; Angle = PI;
			}
		}
		else {	// �L�[���͂��Ȃ������Ƃ��������蔻��
			if (CheckWall(x, y, dx, dy)) {
				dx = 0; dy = 0; mv = 0;
			}
			else {
				mv = 16;
			}
		}
	}
	else {
		// �p�b�N�}���ړ����i�}�X�ڂ̒��Ԃɂ���Ƃ��j
		mv -= 4;
		if (mv <= 0) {
			x += dx;
			y += dy;
			mv = 0;//dx=0;dy=0;
			if (CheckWall(x, y, dx, dy)) {
				dx = 0; dy = 0;
				mv = 0;
			}
		}
		else {
			mvx = (16 - mv) * dx;
			mvy = (16 - mv) * dy;
		}
	}
	if ((dx + dy) != 0) s = (++s) % 7; // �����Ă���Ƃ������A�j���[�V����

	DrawRotaGraph((x - 1) * 16 + 24 + mvx, (y - 1) * 16 + 24 + mvy, 1, Angle, gPacman[s], TRUE);//�p�b�N�}���̕\��

	return 0;
}
// ���C�����[�v
void Stage::MainLoop()
{

	while (ProcessMessage() == 0) {
		ClsDrawScreen();

		if (MapSet())return;
		if (PakuMove()) return;

		DrawFormatString(800, 0, RGB(255, 255, 255), "SCORE:");//�X�R�A�\��
		DrawFormatString(830, 15, RGB(255, 255, 255), "%6d", gScore);

		ScreenFlip();
	}
	return;
}