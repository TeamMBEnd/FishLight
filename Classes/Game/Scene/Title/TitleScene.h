#ifndef _TITLESCENE_H_
#define _TITLESCENE_H_

#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

class TitleScene : public cocos2d::LayerGradient {
private:
	//タイトル背景表示
	void backGraundDraw();
	//タイトルロゴ表示
	void logoDraw();
	//タッチスタート表示
	void touchStartDraw();
	//タイトル内カウント関数
	void titleCount();
	//泡生成
	void bableAdd();
	//音生成
	void bgmPlay();
	
	//各ボタン生成
	void TitleContinuanceButton();
	void TitleFirstButton();
	void TitleStageSelect();
	
	//シーンセレクト
	void sceneSerect();
	
	/*-------------------
	 ローカル用変数
	 -------------------*/
	//背景用スプライト
	Sprite* titleBG;
	Sprite* titlelogo;
	Sprite* touchlogo;
	cocos2d::RepeatForever* repeatForever;
	int nextFlag;
	int sceneCount;
	//アニメーション遷移用変数
	int transitionCount;
	
	//ロゴ遅延用変数
	int titleDelay;
	
	
public:
	//コンストラクタ、デストラクタ
	TitleScene();
	~TitleScene();

	//シーン作成
	static cocos2d::Scene* createScene();
	//初期化
	virtual bool init();
	//更新
	void update(float at);

	//タッチ開始時の判定
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	
	CREATE_FUNC(TitleScene);
};
#endif
