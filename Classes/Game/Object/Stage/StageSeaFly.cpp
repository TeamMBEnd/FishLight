#include "StageSeaFly.h"
#include "Game/Util/Collision/CollisionFuncManager.h"
#include "Game/Util/Collision/CollisionDelegate.h"
#include "System/MyMath.h"
#include "Game/Draw/Draw2D.h"

StageSeaFly::StageSeaFly() {
	Sprite::init();
	_isDead = false;
	PhysicsBody* pb = PhysicsBody::createCircle(15);
	//物理挙動の設定
	pb->setMass(1.0f);
	pb->setDynamic(true);
	pb->setContactTestBitmask(true);
	setScale(0.6f);
	setPhysicsBody(pb);

	setName("StageSeaFly");

	retain();
}

StageSeaFly::~StageSeaFly(){
	release();
}

void StageSeaFly::onEnter(){
	Sprite::onEnter();
	//テクスチャ設定
	setTexture("stage/chara/SeaFireFly.png");
}

void StageSeaFly::setPosition(const float x, const float y){
	Sprite::setPosition(Vec2(x, y));	
}

void StageSeaFly::update(float deltatime){
	/*DRAW2D->DrawCircle(getPosition(), 40.f, Color4F(1, 1, 1, 1.f));
	DRAW2D->DrawCircle(getPosition(), 45.f, Color4F(1, 1, 1, 0.25f));
	DRAW2D->DrawCircle(getPosition(), 50.f, Color4F(1, 1, 1, 0.25f));*/
}

void StageSeaFly::onContact(Node* node){
	_isDead = true;
	removeFromParent();
}

bool StageSeaFly::isDead(){
	return _isDead;
}

StageSeaFly* StageSeaFly::clone(){

	return new StageSeaFly();
}