#ifndef _ENEMYESCAPE_H_
#define _ENEMYESCAPE_H_

#include "IEnemyMove.h"

/*---------------------
�G�ړ��̃C���^�[�t�F�[�X
---------------------*/
class EnemyEscape : public IEnemyMove {
public:
	/*---------------
	�R���X�g���N�^
	---------------*/
	EnemyEscape();
	/*---------------
	�f�X�g���N�^
	---------------*/
	~EnemyEscape();

	void move(Sprite* sprite, Vec2 targetPosition, float playerDis);

	MoveState getState();

public:
};

#endif