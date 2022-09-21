#include"FPS.h"

bool FPS::Update() {
	if (mCount == 0) { //1フレーム目なら時刻を記憶
		mStartTime = GetNowCount();		//最初の時間
	}
	if (mCount == N) { //60フレーム目なら平均を計算する
		int t = GetNowCount();		//現在までの時間
		mFps = 1000.f / ((t - mStartTime) / (float)N);		//現在のFPSの計算
		mCount = 0;		//フレームのリセット
		mStartTime = t;		//0フレーム目の設定
	}
	mCount++;		//毎フレーム加算
	return true;
}

void  FPS::Draw() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%.1f", mFps);
}

void  FPS::Wait() {
	int tookTime = GetNowCount() - mStartTime;	//かかった時間	
	int waitTime = mCount * 1000 / FLAME - tookTime;	//待つべき時間
	if (waitTime > 0) {
		Sleep(waitTime);	//waitTimeが1以上なら待機
	}
}