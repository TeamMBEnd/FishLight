#include "EnemyReaper.h"
#include "IEnemyMove.h"
#include "EnemyAttack.h"
#include "EnemyEscape.h"
#include "System/MyMath.h"
#include "Game/Sound/RappingAudio.h"
#include <math.h>

USING_NS_CC;

EnemyReaper::EnemyReaper() : mIsEscape(false),
mMoveCount(0), mFadeOutCount(0) {
	setName("EnemyReaper");
}

EnemyReaper::~EnemyReaper() {}

bool EnemyReaper::init() {
	if (!Sprite::init()) {
		return false;
	} return true;
	srand((unsigned)time(NULL));
}

Sprite* EnemyReaper::enemyCreate(cocos2d::Point position) {
	sprite = Sprite::create("stage/chara/EnemyReaper.png");

	//物質化
	PhysicsMaterial mat;
	mat.density = 1.0f; //質量？
	mat.restitution = 1.5f; //反発係数
	mat.friction = 0.1f; //摩擦係数

	PhysicsBody* enemyPb = PhysicsBody::createCircle(sprite->getContentSize().width / 2, mat);
	enemyPb->setTag(114514);
	enemyPb->setRotationEnable(false);
	enemyPb->setDynamic(true); //物理的挙動の有無
	enemyPb->setContactTestBitmask(true);

	sprite->setPhysicsBody(enemyPb);
	sprite->setPosition(Vec2(position.x, position.y));

	return sprite;
}

void EnemyReaper::update(float deltatime, Vec2 targetPos) {
	if (mIsEscape) {
		fadeOut(targetPos);
		return;
	}
	checkDistance(sprite, targetPos);
	checkAI(targetPos);
	Vec2 pos = sprite->getPosition();
	sprite->setPosition(MyMath::clamp(pos, Vec2(0, 0), Vec2(6400, 5376)));
}

void EnemyReaper::checkAI(Vec2 targetPos) {
	++mMoveCount;
	if (mPlayerDistance > 1500) return;
	if (mMoveCount > 60) {
		//ここを切り替える
		changeState(shared_ptr<IEnemyMove>(new EnemyAttack));
		nowState = moveState->getState();
		mMoveCount = 0;
		moveState->move(sprite, targetPos, mPlayerDistance);
	}
}

void EnemyReaper::fadeOut(Vec2 targetPos) {
	++mFadeOutCount;
	++mMoveCount;
	if (mPlayerDistance > 300) return;
	if (mMoveCount > 30) {
		mMoveCount = 0;
		changeState(shared_ptr<IEnemyMove>(new EnemyEscape));
		nowState = moveState->getState();
		moveState->move(sprite, targetPos, mPlayerDistance);
	}
	sprite->setOpacity(256 - mFadeOutCount * 2);
	if (mFadeOutCount > 128) {
		mIsDead = true;
	}
}

void EnemyReaper::changeState(shared_ptr<IEnemyMove> moveState) {
	this->moveState = moveState;
}

void EnemyReaper::onContact(Node* node){
	if (strstr(node->getName().c_str(), "RippleAttack")){
		auto deadSE = RappingAudio::getInstance()->getSE(ENEMYDEAD);
		deadSE->play();
		mIsEscape = true;
	}
}