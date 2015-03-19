#ifndef _NEARMOVE_H_
#define _NEARMOVE_H_

#include "ISeaFireFlyMove.h"
#include "cocos2d.h"

USING_NS_CC;

class NearMove:ISeaFireFlyMove
{
public:
	NearMove();
	~NearMove();

	Vec2 Move(Vec2 targetPosition,Vec2 targetVel);

private:
	float mAngle;
};

#endif