#ifndef _ENEMYMOVE_H_
#define _ENEMYMOVE_H_

#include "cocos2d.h"
#include "IEnemyMove.h"

USING_NS_CC;
/*---------------------
敵移動のインターフェース
---------------------*/
class EnemyMove : public IEnemyMove {
public:
	/*---------------
	コンストラクタ
	---------------*/
	EnemyMove();
	/*---------------
	デストラクタ
	---------------*/
	~EnemyMove();
	void move(Sprite* enemy, Vec2 targetPosition, float playerDis);

	MoveState getState();
public:
	float enemyRote;
private:
	bool isMove;
};

#endif