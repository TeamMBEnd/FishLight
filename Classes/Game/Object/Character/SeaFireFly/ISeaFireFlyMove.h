#ifndef _ISEAFIREFLYMOVE_H_
#define _ISEAFIREFLYMOVE_H_

#include "cocos2d.h"

USING_NS_CC;

class ISeaFireFlyMove
{
public:
	~ISeaFireFlyMove(){}

	virtual Vec2 Move(Vec2 targetPosition, Vec2 targetVel) = 0;

private:

};

#endif