#ifndef _FOLLOWPOSITIONMANAGER_H_
#define _FOLLOWPOSITIONMANAGER_H_

#include <list>
#include "cocos2d.h"

USING_NS_CC;

class FollowPositionManager
{
public:
	FollowPositionManager();
	~FollowPositionManager();

	void update(const Vec2& targetPosition);

	Vec2 getPos(int number);

private:
	Vec2 position[8];
};

#endif