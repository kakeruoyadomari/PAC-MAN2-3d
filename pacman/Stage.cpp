#include"Stage.h"

Stage stage;

int StagePixel[STAGE_WIDTH][STAGE_HEIGHT];
int gMapChip[5];

//画像
int Stage::LoadData()
{
	if (LoadDivGraph("images/mapchip2.png", 5, 5, 1, 8, 8, gMapChip) == -1)	
	MessageBox(NULL, "images/mapchip2.png", "ReadError", MB_OK);
	return -1;
}

//datから呼び出し
int Stage::MapInit()
{
	int FileHandle = FileRead_open("dat/stagedata0824.txt");		// ファイルのオープン
	int FileSize = FileRead_size("dat/stagedata0824.txt");			// ファイルサイズを取得して
	char* FileImage = new char[FileSize];					// その大きさだけ領域確保
	FileRead_read(FileImage, FileSize, FileHandle);			// 一気読み
	FileRead_close(FileHandle);								// ファイルを閉じて終了

	const char* d = FileImage;
	int sx = 0, sy = 0;
	int o;

	while (*d != '\0') { // NULL文字（終端）ではない間
		switch (*d) {
		case '0':	o = 0; break;
		case '1':	o = 3; break;
		case '=':	o = 4; break;
		case '\n':
			sy++;		// 一行下へ、左端へ
			sx = 0;		// throw down
		default:	o = 5; break;
		}
		d++;
		if (o != 5) {
			StagePixel[sy][sx] = o;	// マップ情報書き込み
			sx++;
		}
	}

	return 0;
}

//マップ出現
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