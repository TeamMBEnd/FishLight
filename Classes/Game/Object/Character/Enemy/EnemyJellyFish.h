#ifndef _ENEMYJELLYFISH_H_
#define _ENEMYJELLYFISH_H_

#include "cocos2d.h"
#include "Enemy.h"
#include "IEnemyMove.h"

USING_NS_CC;
//‘Ò‚¿•š‚¹ŒZ‹M
class EnemyJellyFish : public Enemy {
public:
	EnemyJellyFish();
	~EnemyJellyFish();

	virtual bool init();
	Sprite* enemyCreate(cocos2d::Point position);
	void update(float deltatime, Vec2 targetPos);
	void changeState(shared_ptr<IEnemyMove> moveState);
	void checkAI(Sprite* sprite, Vec2 targetPos);
	virtual void onContact(Node* node);

	MoveState getState();

	CREATE_FUNC(EnemyJellyFish);
private:
	shared_ptr<IEnemyMove> moveState;
	int mMoveCount;
	float mEnemyRotate;
	bool mIsSpark;
	int mSparkCount;
	MoveState nowState;
};

#endif