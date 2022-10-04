#include "DxLib.h"
#include"Stage.h"

Stage stage;

// グローバル変数
int Pacman[10];			// パックマンのグラフィックハンドル
int Pac[11];                //パックマン消滅アニメーションハンドル
int Score;					// 得点

// 画像の読み込み
int Stage::LoadData()
{
	// 画像の読み込み
	if (LoadDivGraph("images/pacman2.png", 10, 10, 1, 24, 24, Pacman) == -1) {
		MessageBox(NULL, "images/pacman2.png", "ReadError", MB_OK);
		return -1;
	}
	//パックマン消滅アニメーション
	if (LoadDivGraph("images/pacman11.png", 11, 11, 1, 27, 27, Pac) == -1) {
		MessageBox(NULL, "images/pacma11.png", "ReadError", MB_OK);
		return -1;
	}
	//Readyの文字
	if ((Ready = LoadGraph("images/Ready.png")) == -1) return -1;

	//GameOverの文字
	if ((GameOver = LoadGraph("images/GameOver.png")) == -1) return -1;
	return 0;
}

// マップの読み込み
int Stage::MapInit()
{

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
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) return -1;

	if (LoadData() == -1) {
		DxLib_End();
		return -1;
	}
     MapInit();

	// ゲームの設定
	Score = 0;

	//パックマン消滅アニメーション　ここから↓
	int i;
	// ロードしたグラフィックのアニメーション
	i = 0;
	// キーが押されるまでループ
	while (CheckHitKeyAll() == 0)
	{
		// メッセージ処理
		if (ProcessMessage() == -1) {
			break;        // エラーが起きたらループから抜ける
		}
		// 画面を消す
		ClearDrawScreen();

		// 更新
		// グラフィックの描画
		DrawGraph(500, 300, Pac[i], TRUE);

		// アニメーションパターンナンバーを変更
		i++;
		if (i == 11) i = 0;

		// 一定時間待つ
		WaitTimer(100);

		// 裏画面を表画面に反映
		ScreenFlip();
	}
	//ここまで↑

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
			if (StageTS[sx][sy] == 1) {
				DrawBox(sx * DOT_SIZE, sy * DOT_SIZE, sx * DOT_SIZE + DOT_SIZE, sy * DOT_SIZE + DOT_SIZE, 0xff00ff, TRUE);
			}
		}
	}
	return 0;
}

// 進行方向に壁がないかチェックする
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
// パックマンが移動する関数
int Stage::PakuMove()
{
	static int key;
	static int s = 0;			// パックマン表示用
	static int x = 23, y = 14;	// マップ座標(パックマンの初期座標)
	static int dx = 0, dy = 0;	// 初期方向は与えない
	static float Angle = 0.0f;	// 初期　左向き
	static int mv = 0;			// パックマン移動中
	int mvx = 0, mvy = 0;

	key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (key & PAD_INPUT_START) return -1;		// PAD_INPUT_START  [ESC]Key

	if (mv == 0) {
		// 足元判定
		if (StagePixel[y][x] == 1) {//普通の餌を食べたとき(スコア10up)
			Score += 10;
			StagePixel[y][x] = 0;
		}
		if (StagePixel[y][x] == 2) {//パワー餌食べた時(スコア50up)
			Score += 50;
			StagePixel[y][x] = 0;
		}

		// マス目にいるときだけキー入力判定
		mv = 16;
		if (key & PAD_INPUT_UP) {
			if (!CheckWall(x, y, 0, -1)) {
				dx = 0; dy = -1; Angle = PI / 2;//dx,dyは歩く量
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
		mv -= 4;
		if (mv <= 0) {
			x += dx;
			y += dy;
			mv = 0;
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

	DrawRotaGraph((x - 1) * 14 + 15 + mvx, (y - 1) * 20 + 15 + mvy, 1, Angle, Pacman[s], TRUE);//パックマンの表示
	return 0;
}
// メインループ
void Stage::MainLoop()
{

	while (ProcessMessage() == 0) {
		ClsDrawScreen();
		
		if (MapSet())return;
		if (PakuMove()) return;

		//Ready描画　ここから
		if (++g_WaitTime >= 0) {
			DrawGraph(270, 392, Ready, FALSE);//Rradyを8秒描画する
		}
		//Ready描画　ここまで

		//GameOverの描画　ここから
		if (++g_WaitTime >= 360) {
			DrawGraph(220, 392, GameOver, FALSE);
		}
		//GameOverの描画　ここまで

		//GameOverの描画5秒後に最初の画面に戻る　ここから
		if (++g_WaitTime >= 660) {
			if (Init())return;
			g_WaitTime = 0;
		}
		//GameOverの描画5秒後に最初の画面に戻る　ここまで


		DrawFormatString(1000, 0, RGB(0, 0, 255), "HI-SCORE");
		DrawFormatString(1019, 16, RGB(255, 255, 255), "10000");


		DrawFormatString(1006, 116, RGB(255, 255, 255), "%6d", Score);
		DrawFormatString(1000, 100, RGB(255, 255, 255), "1UP");//スコア表示

		ScreenFlip();
	}
	return;
}