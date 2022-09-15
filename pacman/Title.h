#pragma once
#include "AbstractScene.h"

class Title : public AbstractScene {
private:
	int WaitTime;
	int PosY;
	int GameState;
	int MenuNumber;
	int MenuY;

	int TitleImage;
	int Menu;
	int Time;
public:
	Title() {
     MenuY = 0;
	 WaitTime = 0;

	 //タイトル画像
	 TitleImage = LoadGraph("images/Title.png");

	 //メニュー
	 Menu = LoadGraph("images/start.png");
	}
	
	// デストラクタ
	~Title() {
		
	};

	//描画以外の更新を実装する
	virtual AbstractScene* Update(XINPUT_STATE data) override;

	//描画に関することを実装する
	virtual void Draw() const override;


};