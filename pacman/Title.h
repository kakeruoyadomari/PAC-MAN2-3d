#pragma once
#include "AbstractScene.h"

class Title : public AbstractScene {
private:
	int WaitTime;
	int PosY;
	int GameState;
	int MenuNumber;
	int MenuY;
public:
	Title() {
     MenuY = 0;
	}
	
	// デストラクタ
	~Title() {
		
	};

	//描画以外の更新を実装する
	virtual AbstractScene* Update(XINPUT_STATE data) override;

	//描画に関することを実装する
	virtual void Draw() const override;


};