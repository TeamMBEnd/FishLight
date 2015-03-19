#ifndef _STAGESELECTSCENE_H_
#define _STAGESELECTSCENE_H_

#include <stdio.h>
#include "cocos2d.h"
#include <string>

USING_NS_CC;

using namespace cocos2d;
using namespace std;

class StageSelectScene : cocos2d::LayerGradient{
private:
	
	int mStageNumber;
	bool mStageSelect;
	bool mPrebiewOn;
	int mtest;
	bool compFlag;
	bool mStageNull;
	bool minitFlag;
 
	//ステージアイコンの表示
	void iconDraw();
	
	//背景の表示
	void backGroundDraw();
	
	//プレビュー枠の表示
	void previewDraw();
	
	//小ステージの表示
	void minStageDraw();
	
	//枠の表示
	void frameviem();
	
	//ステージPlistへの変換
	void conversionToStagePath();
	
	void callback( int num ) {  }


	Sprite* mFrameSprite;
	Sprite* PreviewImage[12];
	Sprite* star;
	cocos2d::RepeatForever* repeatForever;
	Sprite* Lightlogo;
	Sprite* oklogo;
	
public:
	//コンストラクタ
	StageSelectScene();
	//デストラクタ
	~StageSelectScene();
	
	//シーン作成
	static cocos2d::Scene* createScene();
	//初期化
	virtual bool init();
	//更新
	void update(float at);
	//タッチ開始時の判定
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	
	CREATE_FUNC(StageSelectScene);
};
#endif
