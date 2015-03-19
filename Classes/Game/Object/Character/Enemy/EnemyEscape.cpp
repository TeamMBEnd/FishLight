#include "EnemyEscape.h"

EnemyEscape::EnemyEscape() {
	srand((unsigned)time(NULL));
}

EnemyEscape::~EnemyEscape() {

}

void EnemyEscape::move(Sprite* sprite, Vec2 targetPos, float playerDis) {
	float enemyRote;
	float PI = 3.14159265358979f;
	Vec2 movePoint;
	float moveVel;
	float DisX, DisY;
	float escapeDisX, escapeDisY;
	DisX = targetPos.x - sprite->getPositionX();
	DisY = targetPos.y - sprite->getPositionY();

	escapeDisX = DisX * -1;
	escapeDisY = DisY * -1;

	movePoint = Vec2(sprite->getPositionX() + escapeDisX,
		              sprite->getPositionY() + escapeDisY);
	//ˆÚ“®æ‚ÌŠp“x‚ÌŽæ“¾
	moveVel = playerDis * 1000;
	if (playerDis > 600) {
		moveVel = playerDis * 250;
	}
	ActionInterval* move = MoveTo::create(moveVel, movePoint);
	DisX = 1 - DisX;
	DisY = 1 - DisY;

	//³‹K‰»‚O`‚P‚ª“ü‚é
	enemyRote = (atan2(DisX, DisY)) * 180 / PI;
	ActionInterval* rote = RotateTo::create(1.f, enemyRote);

	sprite->runAction(EaseExponentialOut::create(move));
	sprite->runAction(EaseExponentialOut::create(rote));
}

MoveState EnemyEscape::getState() {
	return ATTACK;
}