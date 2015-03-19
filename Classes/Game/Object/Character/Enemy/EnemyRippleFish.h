#ifndef _ENEMYRIPPLEFISH_H_
#define _ENEMYRIPPLEFISH_H_

#include "cocos2d.h"
#include "Enemy.h"
#include "IEnemyMove.h"

class RippleManager;

USING_NS_CC;

class EnemyRippleFish : public Enemy {
public:
	EnemyRippleFish();
	~EnemyRippleFish();

	virtual bool init();
	Sprite* enemyCreate(cocos2d::Point position);
	void update(float deltatime, Vec2 targetPos);
	void changeState(shared_ptr<IEnemyMove> moveState);
	void checkAI(Sprite* sprite, Vec2 targetPos);
	virtual void onContact(Node* node);
	virtual void createRipple();

	MoveState getState();

	CREATE_FUNC(EnemyRippleFish);
private:
	shared_ptr<IEnemyMove> moveState;
	RippleManager* rippleManager;
	int mMoveCount;
	float mEnemyRotate;
	int mRippleCount;
	MoveState nowState;
};

#endif