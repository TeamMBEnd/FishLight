#ifndef _ENEMYATTACK_H_
#define _ENEMYATTACK_H_

#include "IEnemyMove.h"

/*---------------------
�G�ړ��̃C���^�[�t�F�[�X
---------------------*/
class EnemyAttack : public IEnemyMove {
public:
	/*---------------
	�R���X�g���N�^
	---------------*/
	EnemyAttack();
	/*---------------
	�f�X�g���N�^
	---------------*/
	~EnemyAttack();

	void move(Sprite* enemy, Vec2 targetPosition, float playerDis);

	MoveState getState();

public:
};

#endif