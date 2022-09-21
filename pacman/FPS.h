#pragma once
#include<math.h>
#include"DxLib.h"


class FPS {
	int mStartTime;         //測定開始時刻
	int mCount;             //カウンタ
	float mFps;             //fps
	static const int N = 60;//平均を取るサンプル数
	static const int FLAME = 60;	//設定したFPS

public:
	FPS() {
		mStartTime = 0;
		mCount = 0;
		mFps = 0;
	}

	bool Update();

	void Draw();

	void Wait();
};