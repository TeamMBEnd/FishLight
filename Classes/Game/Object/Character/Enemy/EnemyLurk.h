#ifndef _ENEMYLURK_H_
#define _ENEMYLURK_H_

#include "cocos2d.h"
#include "Enemy.h"
#include "IEnemyMove.h"

USING_NS_CC;
//待ち伏せ兄貴
class EnemyLurk : public Enemy {
public:
	EnemyLurk();
	~EnemyLurk();

	virtual bool init();
	Sprite* enemyCreate(cocos2d::Point position);
	void update(float deltatime, Vec2 targetPos);
	void changeState(shared_ptr<IEnemyMove> moveState);
	void checkAI(Sprite* sprite, Vec2 targetPos);
	virtual void onContact(Node* node);
	void deleteEffect();

	MoveState getState();

	CREATE_FUNC(EnemyLurk);
private:
	shared_ptr<IEnemyMove> moveState;
	int mMoveCount;
	bool mIsDelate;
	int mEffectCount;
	int mDeleteCount;
	MoveState nowState;
};

#endif