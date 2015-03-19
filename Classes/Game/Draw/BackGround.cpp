/*----------------------------------
 Created by settyan on 2014/12/15.
 背景生成クラス
 ----------------------------------*/

#include "BackGround.h"
#include "cocos2d.h"
//#include "MyMath.h"
//using namespace MyMath;

USING_NS_CC;

/*-------------------------
 コンストラクタ
 --------------------------*/
BackGround::BackGround(){
}

/*-------------------------
 初期化
 --------------------------*/
void BackGround::Initialize(cocos2d::Layer* layer){
	//背景生成
	create(layer);
}

/*-------------------------
 背景生成
 --------------------------*/
void BackGround::create(cocos2d::Layer* layer){
	
	/*-------------------------
	 スプライト配列の用意
	 --------------------------*/
	Sprite* pBgMapArray[4];
	
	/*-------------------------
	 縦横配列の用意
	 --------------------------*/
	int heightArray[4] = {0,768*4,0		,768*4 };
	int weightArray[4] = {0,0    ,1280*4,1280*4};
	
	/*-------------------------
	 背景生成
	 --------------------------*/
	for (int i = 0; i < 4; ++i) {
		pBgMapArray[i] =Sprite::create("stage/BackGround.png");
		pBgMapArray[i]->setAnchorPoint(Point(0,0));
		pBgMapArray[i]->setPosition(Point(weightArray[i],heightArray[i]));
		pBgMapArray[i]->setScale(4,4);
		layer->addChild(pBgMapArray[i],0,0);
	}
}

//
////更新
//void BackGraund::Update(cocos2d::Layer* layer){
//
//	//clamp値の確保
//	clampValue = MyMath::clamp(layer->getPosition(), Point(-1000,-600), Point(0,0));
//	//clamp実行
//	layer->setPosition(clampValue);
//}