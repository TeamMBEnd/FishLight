#include "FollowState.h"
#include "SeaFireFly.h"

FollowState::FollowState()
{
	
}

FollowState::~FollowState()
{
}

void FollowState::update(SeaFireFly* seaFireFly, SeaFireFly* targetObject, Vec2 targetVel, Vec2 centerPos)
{
	mMove.move(seaFireFly, targetObject, targetVel,centerPos);
}


State FollowState::getState()
{
	return FOLLOW;
}
