#include "EnemyRebellion.h"
#include "EnemyMove.h"
#include "EnemyAttack.h"
#include "IEnemyMove.h"
#include "Game/Draw/Effect/Light/SpotLight.h"
#include "System/MyMath.h"
#include <math.h>
#include "Game/Draw/Effect/Light/LightManager.h"

USING_NS_CC;

EnemyRebellion::EnemyRebellion() : mIsOppose(false), 
mMoveCount(0), mRebellionCount(120), mActionCount(0){
	setName("EnemyRebellion");
}

EnemyRebellion::~EnemyRebellion() {}

bool EnemyRebellion::init() {
	if (!Sprite::init()) {
		return false;
	} return true;
	srand((unsigned)time(NULL));
}

Sprite* EnemyRebellion::enemyCreate(cocos2d::Point position) {
	sprite = Sprite::create("stage/chara/EnemyRebellion.png");

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

void EnemyRebellion::update(float deltatime, Vec2 targetPos) {
if (mIsOppose == true) {
		++mActionCount;
		LightManager::getInstance()->addDrawList(5.f, &getPosition(), 3.f, false);
	}
	if (mActionCount == 300) {
		mIsOppose = false;
		mActionCount = 0;
	}
	checkDistance(sprite, targetPos);
	checkAction(targetPos);

	Vec2 pos = this->getPosition();
	this->setPosition(MyMath::clamp(pos, Vec2(0, 0), Vec2(6400, 5376)));
	
}

void EnemyRebellion::checkAction(Vec2 targetPos) {
	++mMoveCount;
	if (mMoveCount > mRebellionCount) {
		mMoveCount = 0;
		if (mIsOppose == true) {
			changeState(shared_ptr<IEnemyMove>(new EnemyAttack));
			nowState = moveState->getState();
			moveState->move(sprite, targetPos, mPlayerDistance);
			return;
		}
		changeState(shared_ptr<IEnemyMove>(new EnemyMove));
		nowState = moveState->getState();
		moveState->move(sprite, targetPos, mPlayerDistance);
	}
}

void EnemyRebellion::changeState(shared_ptr<IEnemyMove> moveState) {
	this->moveState = moveState;
}

void EnemyRebellion::onContact(Node* node){
	if (node->getName() == "RippleAttack"){
		mIsOppose = true;
		mRebellionCount = 60;
		sprite->setColor(Color3B::RED);
		sprite->setOpacity(128);
	}

	if (node->getName() == "PlayerSprite"){
		mIsOppose = false;
		mRebellionCount = 120;
		sprite->setColor(Color3B::Color3B(0,0,0));
		sprite->setOpacity(128);
	}
}