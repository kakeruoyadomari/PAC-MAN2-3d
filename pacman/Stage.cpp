#include "Stage.h"
#include "DxLib.h"
#include"Stage.h"

// �摜�̓ǂݍ���
int Stage::LoadData()
{
	Map = LoadGraph("images/stag.png");
	return 0;
}

// �}�b�v�̓ǂݍ���
int Stage::MapInit()
{
	fopen_s(&fp, "dat/StageTestCSV1.txt", "r");

	//�t�@�C�����[�h
	for (int i = 0; i < STAGE_HEIGHT; i++) {
		for (int j = 0; j < STAGE_WIDTH; j++) {
			fscanf(fp, "%d", &StagePixel[j][i]);
		}
	}

	//�t�@�C���N���[�Y
	fclose(fp);

	fopen_s(&fp, "dat/StageTestCSV1.txt", "r");

	for (int i = 0; i < STAGE_HEIGHT; i++) {
		for (int j = 13; j >= 0; j--) {
			fscanf(fp, "%d", &StageReverse[j][i]);
		}
	}

	//�t�@�C���N���[�Y
	fclose(fp);

	for (int i = 0; i < STAGE_WIDTH; i++) {
		for (int j = 0; j < STAGE_HEIGHT; j++) {
			StageTS[i][j] = StagePixel[i][j];
		}
	}

	for (int i = 0; i < STAGE_WIDTH; i++) {
		for (int j = 0; j < STAGE_HEIGHT; j++) {
			StageTS[i + STAGE_WIDTH][j] = StageReverse[i][j];
		}
	}

	return 0;
}

// ������
int Stage::Init()
{
	MapInit();

	return 0;
}
// �}�b�v�z�u�i���t���[���`��j
int Stage::MapSet()
{
	int sx, sy, st;
	int dot = 0;

	//for (sy = 0; sy < STAGE_HEIGHT; sy++) {
	//	for (sx = 0; sx < STAGE_WIDTH * 2; sx++) {
	//		st = StageTS[sy][sx];
	//		//DrawGraph(sx * 4, sy * 3.1,gMapChip[st], TRUE);//�}�b�v�̑傫���ύXx��y�c
	//		if (StageTS[sx][sy] == 1) {
	//			DrawBox(sx * DOT_SIZE+ STAGE_LEFT_SPACE, sy * DOT_SIZE, sx * DOT_SIZE + DOT_SIZE+ STAGE_LEFT_SPACE, sy * DOT_SIZE + DOT_SIZE, 0xff00ff, TRUE);
	//		}
	//	}
	//}

	if (animeflg == false) {
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND , 0);
		DrawGraph(STAGE_LEFT_SPACE, 0, Map, TRUE);

	}
	else {
		SetDrawBlendMode(DX_BLENDMODE_INVSRC, 255);//画像を反転させて描画する
		DrawGraph(STAGE_LEFT_SPACE, 0, Map, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_ADD, 250);//画像を加算ブレンドで描画する
		DrawGraph(STAGE_LEFT_SPACE, 0, Map, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	return 0;
}
void Stage::StageAnimetion()
{
	animetioncount+=1;

	if (animetioncount % 80 == 0) {
		animeflg = !(animeflg);
		animetioncount = 0;
	}
}
