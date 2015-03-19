#include "EnemyLurk.h"
#include "EnemyAttack.h"
#include "IEnemyMove.h"
#include "System/MyMath.h"
#include <math.h>
#include "Game/Draw/Effect/Particle/SimpleParticle.h"
#include "Game/Sound/RappingAudio.h"

USING_NS_CC;

EnemyLurk::EnemyLurk() : mMoveCount(0),
mIsDelate(false), mDeleteCount(0) ,nowState(NORMAL) {
	setName("EnemyLurk");
}

EnemyLurk::~EnemyLurk() {}

bool EnemyLurk::init() {
	if (!Sprite::init()) {
		return false;
	} return true;
	srand((unsigned)time(NULL));
}

Sprite* EnemyLurk::enemyCreate(cocos2d::Point position) {
	sprite = Sprite::create("stage/chara/EnemyLurk.png");

	//物質化
	PhysicsMaterial mat;
	mat.density = 1.0f; //質量？
	mat.restitution = 1.5f; //反発係数
	mat.friction = 0.1f; //摩擦係数

	PhysicsBody* enemyPb = PhysicsBody::createCircle(sprite->getContentSize().width / 2, mat);
	enemyPb->setRotationEnable(false);
	enemyPb->setDynamic(true); //物理的挙動の有無
	enemyPb->setContactTestBitmask(true);

	sprite->setPhysicsBody(enemyPb);
	sprite->setPosition(Vec2(position.x, position.y));

	return sprite;
}

void EnemyLurk::changeState(shared_ptr<IEnemyMove> moveState) {
	this->moveState = moveState;
}

void EnemyLurk::update(float deltatime, Vec2 targetPos) {
	if (mIsDelate) {
		deleteEffect();
	}
	if (mDeleteCount >= 256) {
		mIsDelate = false;
		mIsDead = true;
	}
	if (mIsDelate) return;
	checkDistance(sprite, targetPos);
	checkAI(sprite, targetPos);
	Vec2 pos = sprite->getPosition();
	sprite->setPosition(MyMath::clamp(pos, Vec2(0, 0), Vec2(6400, 5376)));
}

void EnemyLurk::checkAI(Sprite* sprite, Vec2 targetPos) {
	++mMoveCount;
	if (mPlayerDistance > 300) return;
	if (mMoveCount > 60) {
		mMoveCount = 0;
		changeState(shared_ptr<IEnemyMove>(new EnemyAttack));
		nowState = moveState->getState();
		moveState->move(sprite, targetPos, mPlayerDistance);
	}
}

void EnemyLurk::onContact(Node* node){
	if (mIsDelate) return;
	if (strstr(node->getName().c_str(), "RippleAttack")){
		auto deadSE = RappingAudio::getInstance()->getSE(ENEMYDEAD);
		deadSE->play();
		sprite->setName("Okamura");
		mIsDelate = true;
	}
}

void EnemyLurk::deleteEffect() {
	mEffectCount += 64;
	mDeleteCount += 64;
	sprite->setOpacity(256 - mEffectCount);
	auto particle = SimpleParticle::create("EnemyDelete", sprite->getPosition());
	auto parent = sprite->getParent();
	parent->getChildByName("Player")->addChild(particle);
}

MoveState EnemyLurk::getState() {
	return nowState;
}