#ifndef STAGESEAFLY_H
#define STAGESEAFLY_H

#include "StageObj.h"

//ステージギミック（海ほたる）
class StageSeaFly : public StageObj{

public:
	/*--------------------
	コンストラクタ
	---------------------*/
	StageSeaFly();

	StageSeaFly(const StageSeaFly&);

	/**-------------------
	デストラクタ
	---------------------*/
	~StageSeaFly();

	/**---------------
	更新
	float deltatime フレーム
	------------------*/
	void update(float deltatime) override;

	/**---------------
	衝突処理
	Node* node 衝突相手
	------------------*/
	void onContact(Node* node) override;

	/**---------------------------
	位置設定
	float x 描画位置 x
	float y 描画位置 y
	-----------------------------*/
	void setPosition(const float x, const float y) override;

	/*-----------------------------------
	描画前に一回呼ばれるだけ
	------------------------------------*/
	void onEnter() override;

	bool isDead() override;

	StageSeaFly* clone();

private:


};
#endif