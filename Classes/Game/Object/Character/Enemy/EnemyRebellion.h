#ifndef _ENEMYREBELLION_H_
#define _ENEMYREBELLION_H_

#include "cocos2d.h"
#include "Enemy.h"
#include "IEnemyMove.h"

USING_NS_CC;

class EnemyRebellion : public Enemy {
public:
	EnemyRebellion();
	~EnemyRebellion();

	virtual bool init();
	Sprite* enemyCreate(cocos2d::Point position);
	void update(float deltatime, Vec2 targetPos);
	void changeState(shared_ptr<IEnemyMove> moveState);
	void checkAction(Vec2 targetPos);
	virtual void onContact(Node* node);

	MoveState getState();

	CREATE_FUNC(EnemyRebellion);
private:
	shared_ptr<IEnemyMove> moveState;
	int mMoveCount;
	int mActionCount;
	int mRebellionCount;
	float mEnemyRote;
	bool mIsOppose;
	MoveState nowState;
};

#endif