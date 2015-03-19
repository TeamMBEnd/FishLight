#ifndef _ENEMYATTACK_H_
#define _ENEMYATTACK_H_

#include "IEnemyMove.h"

/*---------------------
敵移動のインターフェース
---------------------*/
class EnemyAttack : public IEnemyMove {
public:
	/*---------------
	コンストラクタ
	---------------*/
	EnemyAttack();
	/*---------------
	デストラクタ
	---------------*/
	~EnemyAttack();

	void move(Sprite* enemy, Vec2 targetPosition, float playerDis);

	MoveState getState();

public:
};

#endif