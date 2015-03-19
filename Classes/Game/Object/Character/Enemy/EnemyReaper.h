#ifndef _ENEMYREAPER_H_
#define _ENEMYREAPER_H_

#include "cocos2d.h"
#include "Enemy.h"
#include "IEnemyMove.h"

USING_NS_CC;

class EnemyReaper : public Enemy {
public:
	EnemyReaper();
	~EnemyReaper();

	virtual bool init();
	Sprite* enemyCreate(cocos2d::Point position);
	void update(float deltatime, Vec2 targetPos);
	void changeState(shared_ptr<IEnemyMove> moveState);
	void checkAI(Vec2 targetPos);
	void fadeOut(Vec2 targetPos);
	virtual void onContact(Node* node);

	MoveState getState();

	CREATE_FUNC(EnemyReaper);
private:
	shared_ptr<IEnemyMove> moveState;
	int mMoveCount;
	int mFadeOutCount;
	bool mIsEscape;
	MoveState nowState;
};

#endif