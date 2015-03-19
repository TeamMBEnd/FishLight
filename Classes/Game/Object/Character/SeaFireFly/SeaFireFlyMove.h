#ifndef _SEAFIREFLYMOVE_H_
#define _SEAFIREFLYMOVE_H_

#include "cocos2d.h"
#include <list>
#include "SeaFireFly.h"

USING_NS_CC;

enum MOVESTATE
{
	IMMEDIATE,
	MIDDLE,
	DISTANT
};

class SeaFireFlyMove : public Node
{
public:
	SeaFireFlyMove();
	~SeaFireFlyMove();
	void move(Sprite* seaFirefly, SeaFireFly* targetObject, Vec2 targetVel, Vec2 centerPos);
	bool isEnd();
	MOVESTATE distanceCheck(float distance);
	void seaFireFlyBoid(Sprite* seaFirefly, SeaFireFly* targetObject,Vec2 centerPos);
	Vec2 immediateMove(Sprite* seaFirefly, SeaFireFly* targetObject);
	Vec2 middleMove(Sprite* seaFirefly, SeaFireFly* targetObject);
	Vec2 distantMove(Sprite* seaFirefly, Vec2 centerPosition);

private:
	bool mIsEnd;
};

#endif