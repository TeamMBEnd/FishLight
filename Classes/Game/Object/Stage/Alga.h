#ifndef ALGA_H
#define ALGA_H

#include "StageObj.h"

//ステージギミック（石）
class Alga : public StageObj{

public:
	/*--------------------
	コンストラクタ
	---------------------*/
	Alga();
	Alga(const Alga&);
	~Alga();

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

	/**
	位置設定
	float x 描画位置 x
	float y 描画位置 y
	*/
	void setPosition(const float x, const float y) override;

	/*-----------------------------------
	描画前に一回呼ばれるだけ
	------------------------------------*/
	void onEnter() override;

	bool isDead() override;

	Alga* clone();

private:
	/*----------------------------------------
	位置固定情報をもつ変数
	-----------------------------------------*/
	Vec2 clampPos;
};
#endif