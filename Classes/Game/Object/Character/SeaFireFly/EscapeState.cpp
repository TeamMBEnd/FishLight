#include "EscapeState.h"

EscapeState::EscapeState() :alpha(255.0f)
{

}

EscapeState::~EscapeState()
{

}

void EscapeState::update(SeaFireFly* seaFireFly, SeaFireFly* targetObject, Vec2 targetVel, Vec2 centerPos)
{
	
	Vec2 targetPos = centerPos;
	Sprite* character = seaFireFly;
	

	Vec2 myPos = character->getPosition();

	float distance = 0;
	float dx = targetPos.x - character->getPosition().x;
	float dy = targetPos.y - character->getPosition().y;
	Vec2 change = Vec2(dx, dy);

	distance = myPos.distance(targetPos);
	change.normalize();
	change *= -80;
	character->getPhysicsBody()->setVelocity(change);
}

State EscapeState::getState()
{
	return ESCAPE;
}