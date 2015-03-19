#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

USING_NS_CC;
/**
	@エネミーのインターフェースだYO
*/
class Enemy : public cocos2d::Sprite {
public:
	/**
		@コンストラクタ
	*/
	Enemy();

	/**
		@デストラクタ
	*/
	~Enemy() override;

	/**
		@初期化
	*/
	virtual bool init();

	/**
		@エネミーのスプライト設定
	*/
	virtual Sprite* enemyCreate(cocos2d::Point position);

	/**
		@更新

		@param	deltaTime　デルタ時間
	*/
	virtual void update(float deltaTime, Vec2 targetPos);
	virtual void onContact(Node* node);
	void releaseObj();
	bool dead();
	void checkDistance(Sprite* sprite, Vec2 targetPos);

	CREATE_FUNC(Enemy);
protected:
	bool mIsDead;
	int mDiffDistanceX;
	int mDiffDistanceY;
	int mPlayerDistance;
	Sprite* sprite;
};

#endif