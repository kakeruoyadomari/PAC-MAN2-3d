#include "DxLib.h"
#include"Stage.h"

// グローバル変数
int gPacman[10];			// パックマンのグラフィックハンドル
int gMapChip[10];			// マップチップのハンドル
int gScore;					// 得点

// 画像の読み込み
int Stage::LoadData()
{
	// 画像の読み込み
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

// マップの読み込み
int Stage::MapInit()
{
//	int FileHandle = FileRead_open("dat/stagedata0829.txt");		// ファイルのオープン
//	int FileSize = FileRead_size("dat/stagedata0829.txt");			// ファイルサイズを取得して
//	char* FileImage = new char[FileSize];					// その大きさだけ領域確保
//	FileRead_read(FileImage, FileSize, FileHandle);			// 一気読み
//	FileRead_close(FileHandle);								// ファイルを閉じて終了
//
//	const char* d = FileImage;
//	int sx = 0, sy = 0;
//	int o;
//
//	while (*d != '\0') { // NULL文字（終端）ではない間
//		switch (*d) {
//		case '0':	o = 0; break;
//		case '1':	o = 3; break;
//		case '=':	o = 4; break;
//		case '\n':
//			sy++;		// 一行下へ、左端へ
//			sx = 0;		// throw down
//		default:	o = 5; break;
//		}
//		d++;
//		if (o != 5) {
//			StagePixel[sy][sx] = o;	// マップ情報書き込み
//			sx++;
//		}
//	}
//
//	return 0;

	fopen_s(&fp, "dat/StageTestCSV1.txt", "r");

	//ファイルロード
	for (int i = 0; i < STAGE_HEIGHT; i++) {
		for (int j = 0; j < STAGE_WIDTH; j++) {
			fscanf(fp, "%d", &StagePixel[j][i]);
		}
	}

	//ファイルクローズ
	fclose(fp);

	fopen_s(&fp, "dat/StageTestCSV1.txt", "r");

	for (int i = 0; i < STAGE_HEIGHT; i++) {
		for (int j = 13; j >= 0; j--) {
			fscanf(fp, "%d", &StageReverse[j][i]);
		}
	}

	//ファイルクローズ
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

// 初期化
int Stage::Init()
{
//	ChangeWindowMode(TRUE);
//	if (DxLib_Init() == -1) return -1;
//
//	SetDrawScreen(DX_SCREEN_BACK);		// 裏画面に書き込みますよ宣言
//
//	if (LoadData() == -1) {
//		DxLib_End();
//		return -1;
//	}
	MapInit();

	// ゲームの設定
	gScore = 0;
	return 0;
}
// マップ配置（毎フレーム描画）
int Stage::MapSet()
{
	int sx, sy, st;
	int dot = 0;

	for (sy = 0; sy < STAGE_HEIGHT; sy++) {
		for (sx = 0; sx < STAGE_WIDTH * 2; sx++) {
			st = StageTS[sy][sx];
			//DrawGraph(sx * 4, sy * 3.1,gMapChip[st], TRUE);//マップの大きさ変更x横y縦
			if (StageTS[sx][sy] == 1) {
				DrawBox(sx * DOT_SIZE, sy * DOT_SIZE, sx * DOT_SIZE + DOT_SIZE, sy * DOT_SIZE + DOT_SIZE, 0xff00ff, TRUE);
			}
			//if (st == 1 || st == 2) dot++;
		}
	}
	return 0;
}

// 進行方向に壁がないかチェックする
int Stage::CheckWall(int cx, int cy, int mx, int my)
{
	int wall = 0;
	static int dbgx = 0, dbgy = 0;
	

	if (mx != 0) { //横移動処理
		if (StageTS[cy - 1][cx + mx * 2] == 1) wall++;
		if (StageTS[cy][cx + mx * 2] == 1) wall++;
		if (StageTS[cy + 1][cx + mx * 2] == 1) wall++;
		//dbgx = mx; dbgy = my;
	}
	else if (my != 0) {//縦移動処理
		if (StageTS[cy + my * 2][cx - 1] == 1) wall++;
		if (StageTS[cy + my * 2][cx] == 1) wall++;
		if (StageTS[cy + my * 2][cx + 1] == 1) wall++;
		//dbgx = mx; dbgy = my;
	}

	return wall;
}
// パックマンが移動する関数
int Stage::PakuMove()
{
	static int key;
	static int s = 0;			// パックマン表示用
	static int x = 18, y = 21;		// マップ座標
	static int dx = 0, dy = 0;	// 初期方向は与えない
	static float Angle = 0.0f;	// 初期　左向き
	static int mv = 0;			// パックマン移動中
	int mvx = 0, mvy = 0;

	key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (key & PAD_INPUT_START) return -1;		// PAD_INPUT_START  [ESC]Key

	if (mv == 0) {
		//if (mv == 0) {
			//		// 足元判定
			//		if (gMap[y][x] == 1) {
			//			// Sound「ぱくっ！！」
			//			gScore += 10;
			//			gMap[y][x] = 0;
			//		}
			//		if (gMap[y][x] == 2) {
			//			// パワー餌食べる
			//			gScore += 50;
			//			gMap[y][x] = 0;
			//		}
		// 足元判定
		if (StagePixel[y][x] == 0) {
			// Sound「ぱくっ！！」
			gScore += 10;
			StagePixel[y][x] = 1;//餌で移動してるところをみてう
		}

		// マス目にいるときだけキー入力判定
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
		else {	// キー入力がなかったときも当たり判定
			if (CheckWall(x, y, dx, dy)) {
				dx = 0; dy = 0; mv = 0;
			}
			else {
				mv = 16;
			}
		}
	}
	else {
		// パックマン移動中（マス目の中間にいるとき）
		mv -= 4;//パックマンの移動処理
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
	if ((dx + dy) != 0) s = (++s) % 7; // 動いているときだけアニメーション

	DrawRotaGraph((x - 1) * 16 + 24 + mvx, (y - 1) * 16 + 24 + mvy, 1, Angle, gPacman[s], TRUE);//パックマンの表示

	return 0;
}
// メインループ
void Stage::MainLoop()
{

	while (ProcessMessage() == 0) {
		ClsDrawScreen();

		if (MapSet())return;
		if (PakuMove()) return;

		DrawFormatString(1050, 0, RGB(255, 255, 255), "SCORE:");//スコア表示
		DrawFormatString(1080, 15, RGB(255, 255, 255), "%6d", gScore);

		ScreenFlip();
	}
	return;
}