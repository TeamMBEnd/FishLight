#ifndef _ENEMYESCAPE_H_
#define _ENEMYESCAPE_H_

#include "IEnemyMove.h"

/*---------------------
敵移動のインターフェース
---------------------*/
class EnemyEscape : public IEnemyMove {
public:
	/*---------------
	コンストラクタ
	---------------*/
	EnemyEscape();
	/*---------------
	デストラクタ
	---------------*/
	~EnemyEscape();

	void move(Sprite* sprite, Vec2 targetPosition, float playerDis);

	MoveState getState();

public:
};

#endif