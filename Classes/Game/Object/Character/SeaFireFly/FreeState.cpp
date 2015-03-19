#include "FreeState.h"
#include "SeaFireFly.h"

FreeState::FreeState()
{
}

FreeState::~FreeState()
{
}

void FreeState::update(SeaFireFly* seaFireFly, SeaFireFly* targetObject, Vec2 targetVel, Vec2 centerPos)
{
	if (seaFireFly->getPhysicsBody() != nullptr)
	seaFireFly->getPhysicsBody()->setVelocity(seaFireFly->getPhysicsBody()->getVelocity()*0.98);
}

State FreeState::getState()
{
	return FREE;
}