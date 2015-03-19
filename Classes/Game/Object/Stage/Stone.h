#ifndef STONE_H
#define STONE_H

#include "StageObj.h"

//ステージギミック（石）
class Stone : public StageObj{

public:
	/*--------------------
	コンストラクタ
	---------------------*/
	Stone();
	Stone(const Stone&);
	~Stone();

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

	Stone* clone() override;

private:
	/*----------------------------------------
	位置固定情報をもつ変数
	-----------------------------------------*/
	Vec2 clampPos;
};
#endif