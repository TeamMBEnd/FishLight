#include "Enemy.h"
#include "Game/Util/Collision/CollisionFuncManager.h"
#include "Game/Draw/Effect/Particle/SimpleParticle.h"
#include "Game/Sound/RappingAudio.h"

USING_NS_CC;

using namespace std;
using namespace cocos2d;

#define VISIBLESIZE Director::getInstance()->getVisibleSize()
#define ORIGINSIZE Director::getInstance()->getVisibleOrigin()

Enemy::Enemy() : mIsDead(false), mDiffDistanceX(0), 
mDiffDistanceY(0), mPlayerDistance(0){
	setName("Enemy");
}

Enemy::~Enemy() {
	sprite->stopAllActions();
	sprite->removeAllChildren();
	sprite->removeFromParent();
}

bool Enemy::init() {
	if (!Sprite::init()) {
		return false;
	} return true;
}

Sprite* Enemy::enemyCreate(cocos2d::Point position) {
	return sprite;
}

void Enemy::update(float deltaTime, Vec2 targetPos) {
}

void Enemy::onContact(Node* node){

}

bool Enemy::dead(){

	return mIsDead;
}

void Enemy::releaseObj(){
	
	mIsDead = true;
}

void Enemy::checkDistance(Sprite* sprite, Vec2 targetPos) {
	mDiffDistanceX = sprite->getPositionX() - targetPos.x;
	mDiffDistanceY = sprite->getPositionY() - targetPos.y;
	mDiffDistanceX = abs(mDiffDistanceX);
	mDiffDistanceY = abs(mDiffDistanceY);
	mPlayerDistance = mDiffDistanceX + mDiffDistanceY;
}