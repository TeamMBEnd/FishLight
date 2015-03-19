#ifndef _ISEAFIREFLYSTATE_H_
#define _ISEAFIREFLYSTATE_H_

#include "cocos2d.h"
#include "SeaFireFlyState.h"
#include <list>

USING_NS_CC;

class SeaFireFly;

class ISeaFireFlyState
{
public:
	virtual ~ISeaFireFlyState(){}
	
	virtual void update(SeaFireFly* seaFireFly, SeaFireFly* targetObject, Vec2 targetVel, Vec2 centerPos) = 0;

	virtual State getState() = 0;

private:

};

#endif