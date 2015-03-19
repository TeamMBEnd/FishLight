#ifndef _FOLLOWSTATE_H_
#define _FOLLOWSTATE_H_

#include "ISeaFireFlyState.h"
#include "SeaFireFlyMove.h"

class FollowState : public ISeaFireFlyState
{
public:
	FollowState();
	~FollowState();

	void update(SeaFireFly* seaFireFly, SeaFireFly* targetObject, Vec2 targetVel, Vec2 centerPos);

	State getState();

private:
	bool mMoveflg;
	SeaFireFlyMove mMove;
};

#endif