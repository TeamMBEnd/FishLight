#include "SnapState.h"
#include "SeaFireFly.h"
#include "FreeState.h"
#include <memory>

SnapState::SnapState(Point touchPos,Point endPos) :mTouchPos(touchPos),mEndPos(endPos)
{

}

SnapState::~SnapState()
{

}

void SnapState::update(SeaFireFly* seaFireFly, SeaFireFly* targetObject, Vec2 targetVel, Vec2 centerPos)
{
	Vect force = -Vect(mTouchPos.x - mEndPos.x, mTouchPos.y - mEndPos.y);
	auto normalizeVec = ccpNormalize({ force.x, force.y });
	seaFireFly->setRotation(atan2(normalizeVec.x, normalizeVec.y) * 180 / 3.14);
	seaFireFly->getPhysicsBody()->applyImpulse(force);
	
	seaFireFly->changeState(std::shared_ptr<ISeaFireFlyState>(new FreeState()));
}

State SnapState::getState()
{
	return SNAP;
}