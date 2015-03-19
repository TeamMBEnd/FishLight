#ifndef _SEAFIREFLY_H_
#define _SEAFIREFLY_H_

#include "ISeaFireFlyState.h"
#include <memory>
#include <list>
#include <string>
#include "System/Timer.h"

/**************************************

ウミホタルの種類列挙

**************************************/
enum SEAFIREFLY
{
	NORMAL,
	AGGRESSIVE
};

class RippleManager;

USING_NS_CC;

/***************************************

ウミホタル

****************************************/
class SeaFireFly : public Sprite
{
public:
	/***********************************

	コンストラクタ	

	************************************/
	SeaFireFly();

	/***********************************

	デストラクタ

	************************************/
	~SeaFireFly();

	/***********************************

	初期化

	************************************/
	virtual bool init();

	/***********************************

	更新

	************************************/
	virtual void update(Vec2 targetPos, Vec2 targetVel, Vec2 centerPos, float dt, int group);

	/***********************************

	表示前処理

	************************************/
	void onEnter() override;


	/*******************************************************

	ウミホタルの生成

	@position : 座標
	@name : 名前

	********************************************************/
	SeaFireFly* create(Vect position, const std::string& name);


	CREATE_FUNC(SeaFireFly);

	/*********************************************************
	
	状態の偏移

	@charaState : ISeaFireFlyのshared_ptr

	**********************************************************/
	void changeState(std::shared_ptr<ISeaFireFlyState> charaState);


	/*-----------------------------------
	タッチ判定　（追加、巨峰）
	-------------------------------------*/
	void touchBegan(Point touchPos,Vec2 layerPos);

	/*-----------------------------------
	衝突　（追加、巨峰）
	-------------------------------------*/
	void onContact(Node* node);

	void touchEnd(Point endPos);

	/**********************************************************
	
	死亡しているか

	**********************************************************/
	virtual bool isDead();

	void move( SeaFireFly* targetObject, Vec2 targetVel, Vec2 centerPos);

	virtual void createRipple();

	State getState();

	bool deleteEffect();

	/************************************************************
	
	自分は何者なのか返す

	*************************************************************/
	virtual SEAFIREFLY getKind()const;

protected:
	std::shared_ptr<ISeaFireFlyState> mCharaState;
	RippleManager* mRippleManager;
	Point mTouchPoint;
	bool mIsContact;
	bool mIsDead;
	State mNowState;
	MyTimer mTimer;
	float mAngle;
	int mEffectCount;
	int mDeleteCount;
	bool mIsDelete;
};

#endif