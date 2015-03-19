#include "FollowPositionManager.h"

FollowPositionManager::FollowPositionManager()
{
	
}

FollowPositionManager::~FollowPositionManager()
{
	
}

void FollowPositionManager::update(const Vec2& targetPosition)
{
	position[0] = Vec2(targetPosition.x, targetPosition.y - 120);
	position[1] = Vec2(targetPosition.x, targetPosition.y + 120);
	position[2] = Vec2(targetPosition.x + 120, targetPosition.y);
	position[3] = Vec2(targetPosition.x - 120, targetPosition.y);
	position[4] = Vec2(targetPosition.x, targetPosition.y+80);
	position[5] = Vec2(targetPosition.x-80, targetPosition.y + 80);
	position[6] = Vec2(targetPosition.x - 80, targetPosition.y);
	position[7] = Vec2(targetPosition.x - 80, targetPosition.y-80);
	
}

Vec2 FollowPositionManager::getPos(int number)
{
	if (number > 7)return position[7];
	if (number < 0)return position[0];
	return position[number];
}