#include "EnemyJellyFish.h"
#include "EnemyMove.h"
#include "IEnemyMove.h"
#include "System/MyMath.h"
#include <math.h>
#include "Game/Draw/Effect/Light/LightManager.h"

USING_NS_CC;

EnemyJellyFish::EnemyJellyFish() : mMoveCount(0), mEnemyRotate(0), 
mIsSpark(false), mSparkCount(0), nowState(NORMAL) {
	setName("JellyFish");
}

EnemyJellyFish::~EnemyJellyFish() {}

bool EnemyJellyFish::init() {
	if (!Sprite::init()) {
		return false;
	} return true;
	srand((unsigned)time(NULL));
}

Sprite* EnemyJellyFish::enemyCreate(cocos2d::Point position) {
	sprite = Sprite::create("stage/chara/JellyFish.png");

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

void EnemyJellyFish::changeState(shared_ptr<IEnemyMove> moveState) {
	this->moveState = moveState;
}

void EnemyJellyFish::update(float deltatime, Vec2 targetPos) {
	checkDistance(sprite, targetPos);
	checkAI(sprite, targetPos);
	Vec2 pos = sprite->getPosition();
	sprite->setPosition(MyMath::clamp(pos, Vec2(0, 0), Vec2(6400, 5376)));
	if (mIsSpark == true) {
		++mSparkCount;
		LightManager::getInstance()->addDrawList(5.f, &sprite->getPosition(), 3.f, false);
	}
	if (mSparkCount > 120) {
		mIsSpark = false;
		mSparkCount = 0;
	}
}

void EnemyJellyFish::checkAI(Sprite* sprite, Vec2 targetPos) {
	++mMoveCount;
	if (mMoveCount > 120) {
		mMoveCount = 0;
		changeState(shared_ptr<IEnemyMove>(new EnemyMove));
		nowState = moveState->getState();
		moveState->move(sprite, targetPos, mPlayerDistance);
	}
}

void EnemyJellyFish::onContact(Node* node){
	if (strstr(node->getName().c_str(), "Player")){
		mIsSpark = true;
	}
}
MoveState EnemyJellyFish::getState() {
	return nowState;
}