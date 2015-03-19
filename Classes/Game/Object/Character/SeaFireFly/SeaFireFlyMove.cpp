#include "SeaFireFlyMove.h"
#include <functional>


SeaFireFlyMove::SeaFireFlyMove() :mIsEnd(false)
{
}

SeaFireFlyMove::~SeaFireFlyMove()
{

}


void SeaFireFlyMove::move(Sprite* seaFireFly, SeaFireFly* targetObject,Vec2 centerVel, Vec2 centerPos)
{
	Vec2 targetPos = targetObject->getPosition();
	Sprite* character = seaFireFly;

	Vec2 myPos = character->getPosition();

	float distance = 0;
	float dx = centerPos.x - character->getPosition().x;
	float dy = centerPos.y - character->getPosition().y;
	Vec2 change = Vec2(dx, dy);

	distance = myPos.distance(centerPos);

	if (40 > distance)
	{
		change.normalize();
		change *= -distance;
	}
	else if (distance > 80)
	{
		change.normalize();
		change *= distance;
	}
	else
	{
		change *= 0.0f;
	}

	if ( !seaFireFly ) return;
	//if (change==nullptr)return;
	auto phisycs = seaFireFly->getPhysicsBody();
		seaFireFly->getPhysicsBody()->setVelocity(change);
	

	if (seaFireFly->getName() == targetObject->getName())return;

	seaFireFlyBoid(seaFireFly,targetObject,centerPos);
}

void SeaFireFlyMove::seaFireFlyBoid(Sprite* seaFirefly, SeaFireFly* targetObject,Vec2 centerPos)
{
	Vec2 acc;
	acc += immediateMove(seaFirefly,targetObject);
	/*acc += middleMove(seaFirefly, targetObject);
	acc += distantMove(seaFirefly, centerPos);*/

	Vec2 velocity = seaFirefly->getPhysicsBody()->getVelocity();

	velocity += acc;

	seaFirefly->getPhysicsBody()->setVelocity(velocity);
}


MOVESTATE SeaFireFlyMove::distanceCheck(float distance)
{
	const float immediateDistance = 20;
	const float distantDistance = 80;

	if (immediateDistance < distance)
	{
		return IMMEDIATE;
	}
	else if (distantDistance > distance)
	{
		return MIDDLE;
	}
	else
	{
		return DISTANT;
	}
}


bool SeaFireFlyMove::isEnd()
{
	return mIsEnd;
}


Vec2 SeaFireFlyMove::immediateMove(Sprite* seaFirefly, SeaFireFly* targetObject)
{

	Vec2 targetPos = targetObject->getPosition();
	Sprite* character = seaFirefly;

	Vec2 myPos = character->getPosition();

	if (targetObject->getState() != FOLLOW)return Vec2();

	float distance = 0;
	float dx = targetPos.x - character->getPosition().x;
	float dy = targetPos.y - character->getPosition().y;
	Vec2 change = Vec2(dx, dy);

	distance = myPos.distance(targetPos);

	if (100 > distance)
	{
		change.normalize();
		change *= -distance;
	}
	else if (distance > 120)
	{
		change.normalize();
		change *= distance;
	}
	else
	{
		change *= 0.0f;
	}
	return (change);
}


Vec2 SeaFireFlyMove::middleMove(Sprite* seaFirefly, SeaFireFly* targetObject)
{
	Vec2 targetPos = targetObject->getPosition();
	Sprite* character = seaFirefly;

	Vec2 myPos = character->getPosition();

	if (targetPos == myPos)return Vec2();
	if (targetObject->getState() != FOLLOW)return Vec2();

	float distance = 0;
	float dx = targetPos.x - character->getPosition().x;
	float dy = targetPos.y - character->getPosition().y;
	Vec2 change = Vec2(dx, dy);
	change.normalize();
	change *= 5;

	return (change);
}


Vec2 SeaFireFlyMove::distantMove(Sprite* seaFirefly, Vec2 centerPosition)
{
	Vec2 velocity;
	Vec2 myPosition = seaFirefly->getPosition();

	velocity = centerPosition - myPosition;

	float distance = myPosition.distance(centerPosition);

	if (distance <= 60)return Vec2(0, 0);


	velocity.normalize();

	velocity *= 5;

	return (velocity);
}
