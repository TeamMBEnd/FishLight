#include "EnemyAttack.h"

EnemyAttack::EnemyAttack() {
	srand((unsigned)time(NULL));
}

EnemyAttack::~EnemyAttack() {

}

void EnemyAttack::move(Sprite* enemy, Vec2 targetPos, float playerDis) {
	float enemyRote;
	float PI = 3.14159265358979f;
	Vec2 movePoint;
	float moveVel;
	float DisX, DisY;
	movePoint = Vec2(targetPos.x, targetPos.y);
	//ˆÚ“®æ‚ÌŠp“x‚ÌŽæ“¾
	moveVel = playerDis / 20;
	if (playerDis > 600) {
		moveVel = playerDis;
	}
	ActionInterval* move = MoveTo::create(moveVel, movePoint);
	DisX = targetPos.x - enemy->getPositionX();
	DisY = targetPos.y - enemy->getPositionY();

	//³‹K‰»‚O`‚P‚ª“ü‚é
	enemyRote = (atan2(DisX, DisY)) * 180 / PI;
	ActionInterval* rote = RotateTo::create(1.f, enemyRote);

	enemy->runAction(EaseExponentialOut::create(move));
	enemy->runAction(EaseExponentialOut::create(rote));
}

MoveState EnemyAttack::getState() {
	return ATTACK;
}