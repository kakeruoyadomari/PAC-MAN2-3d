#include"Stage.h"

Stage stage;

int StagePixel[STAGE_WIDTH][STAGE_HEIGHT];
int gMapChip[5];

//�摜
int Stage::LoadData()
{
	if (LoadDivGraph("images/mapchip2.png", 5, 5, 1, 8, 8, gMapChip) == -1)	
	MessageBox(NULL, "images/mapchip2.png", "ReadError", MB_OK);
	return -1;
}

//dat����Ăяo��
int Stage::MapInit()
{
	int FileHandle = FileRead_open("dat/stagedata0824.txt");		// �t�@�C���̃I�[�v��
	int FileSize = FileRead_size("dat/stagedata0824.txt");			// �t�@�C���T�C�Y���擾����
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

//�}�b�v�o��
int Stage::MapSet()
{
	int sx, sy, st;
	int dot = 0;

	for (sy = 0; sy < 464; sy++) {
		for (sx = 0; sx < 512; sx++) {
			st = StagePixel[sy][sx];
			DrawGraph(sx * 3, sy * 3, gMapChip[st], TRUE);
			if (st == 1 || st == 2) dot++;
		}
	}
	return 0;
}