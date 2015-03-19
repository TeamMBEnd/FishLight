#include "EnemyMove.h"

EnemyMove::EnemyMove() {
	srand((unsigned)time(NULL));
}

EnemyMove::~EnemyMove() {
}

void EnemyMove::move(Sprite* enemy, Vec2 targetPos, float playerDis) {

	float PI = 3.14159265358979f;
	Vec2 movePoint = Vec2(enemy->getPositionX() + (rand() % 100 - 50),
		enemy->getPositionY() + (rand() % 100 - 50));
	float DX, DY;
	//ˆÚ“®æ‚ÌŠp“x‚ÌŽæ“¾
	ActionInterval* move = MoveTo::create(1, movePoint);
	DX = movePoint.x - enemy->getPositionX();
	DY = movePoint.y - enemy->getPositionY();
	//³‹K‰»‚O`‚P‚ª“ü‚é
	auto normalizeVec = ccpNormalize({ DX, DY });
	enemyRote = (atan2(DX, DY)) * 180 / PI;
	ActionInterval* rote = RotateTo::create(0.4f, enemyRote);

	enemy->runAction(EaseExponentialOut::create(move));
	enemy->runAction(EaseExponentialOut::create(rote));
}

MoveState EnemyMove::getState() {
	return NORMAL;
}