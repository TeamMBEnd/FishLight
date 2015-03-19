#ifndef _I_ENEMY_MOVE_H_
#define _I_ENEMY_MOVE_H_

#include "cocos2d.h"
#include "EnemyState.h"

USING_NS_CC;

class Enemy;

class IEnemyMove {
public:
	virtual ~IEnemyMove(){}
	virtual void move(Sprite* enemy, Vec2 targetposition, float playerDis) = 0;
	virtual MoveState getState() = 0;
private:

};
#endif