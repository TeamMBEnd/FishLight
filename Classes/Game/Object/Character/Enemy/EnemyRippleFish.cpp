#include "EnemyRippleFish.h"
#include "EnemyMove.h"
#include "IEnemyMove.h"
#include "System/MyMath.h"
#include <math.h>
#include "Game/Draw/Effect/Light/LightManager.h"
#include "Game/Draw/Effect/Ripple/Support/RippleManager.h"

USING_NS_CC;

EnemyRippleFish::EnemyRippleFish() : mMoveCount(0), 
mEnemyRotate(0), mRippleCount(0), nowState(NORMAL) {
	setName("RippleFish");
}

EnemyRippleFish::~EnemyRippleFish() {
	rippleManager->release();
}

bool EnemyRippleFish::init() {
	if (!Sprite::init()) {
		return false;
	}
	rippleManager = RippleManager::create();
	srand((unsigned)time(NULL));
	return true;
}

Sprite* EnemyRippleFish::enemyCreate(cocos2d::Point position) {
	sprite = Sprite::create("stage/chara/GimmickFish2.png");

	//•¨Ž¿‰»
	PhysicsMaterial mat;
	mat.density = 1.0f; //Ž¿—ÊH
	mat.restitution = 1.5f; //”½”­ŒW”
	mat.friction = 0.1f; //–€ŽCŒW”

	PhysicsBody* enemyPb = PhysicsBody::createCircle(sprite->getContentSize().width / 2, mat);
	enemyPb->setRotationEnable(false);
	enemyPb->setDynamic(true); //•¨—“I‹““®‚Ì—L–³
	enemyPb->setContactTestBitmask(true);

	sprite->setPhysicsBody(enemyPb);
	sprite->setPosition(Vec2(position.x, position.y));

	return sprite;
}

void EnemyRippleFish::changeState(shared_ptr<IEnemyMove> moveState) {
	this->moveState = moveState;
}

void EnemyRippleFish::update(float deltatime, Vec2 targetPos) {
	checkDistance(sprite, targetPos);
	checkAI(sprite, targetPos);
	++mRippleCount;
	rippleManager->update(deltatime);
	if (mRippleCount > 360) {
		createRipple();
		mRippleCount = 0;
	}
	Vec2 pos = sprite->getPosition();
	sprite->setPosition(MyMath::clamp(pos, Vec2(0, 0), Vec2(6400, 5376)));
}

void EnemyRippleFish::checkAI(Sprite* sprite, Vec2 targetPos) {
	++mMoveCount;
	if (mMoveCount > 120) {
		mMoveCount = 0;
		changeState(shared_ptr<IEnemyMove>(new EnemyMove));
		nowState = moveState->getState();
		moveState->move(sprite, targetPos, mPlayerDistance);
	}
}

void EnemyRippleFish::onContact(Node* node){
}

void EnemyRippleFish::createRipple() {
	Vec2 size = Vec2(sprite->getContentSize().width / 2, sprite->getContentSize().height / 2);
	rippleManager->playRipple(sprite, RippleTag::TAG_GIMMICK, size);
}

MoveState EnemyRippleFish::getState() {
	return nowState;
}