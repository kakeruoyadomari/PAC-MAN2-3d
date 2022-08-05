#pragma once
#include "AbstractScene.h"

class Title : public AbstractScene {
private:


public:
	Title() {


	}


	// デストラクタ
	~Title() {

	};

	//描画以外の更新を実装する
	virtual AbstractScene* Update(XINPUT_STATE data) override;

	//描画に関することを実装する
	virtual void Draw() const override;


};