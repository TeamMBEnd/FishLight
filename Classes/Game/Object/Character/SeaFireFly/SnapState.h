#ifndef _SNAPSTATE_H_
#define _SNAPSTATE_H_

#include "ISeaFireFlyState.h"
#include "cocos2d.h"

class SeaFireFly;

/***************************************

ウミホタルが飛ばされた時の状態

***************************************/
class SnapState : public ISeaFireFlyState
{
public:
	/*コンストラクタ*/
	SnapState(Point touchPos,Point endPos);
	/*デストラクタ*/
	~SnapState();

	/*******************************************
	  
	  更新

	velocity : 移動量
	*********************************************/
	void update(SeaFireFly* seaFireFly, SeaFireFly* targetObject, Vec2 targetVel, Vec2 centerPos);

	State getState();

private:
	Point mTouchPos;
	Point mEndPos;

};

#endif