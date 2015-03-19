#include "Whirlpool.h"
#include "Game/Util/Collision/CollisionFuncManager.h"
#include "Game/Util/Collision/CollisionDelegate.h"
#include "SyStem/MyMath.h"

Whirlpool::Whirlpool(){
	Sprite::init();
	_isDead = false;
	PhysicsBody* pb = PhysicsBody::createCircle(70);
	//物理挙動の設定
	pb->setMass(100.0f);
	pb->setDynamic(true);
	pb->setContactTestBitmask(true);
	setScale(0.6f);
	setPhysicsBody(pb);
	pb->setCollisionBitmask(false);
	setName("Whirlpool");

	auto spen = RotateBy::create(1, 360);
	auto repeat = RepeatForever::create(spen);
	runAction(repeat);

	retain();
}

Whirlpool::Whirlpool(const Whirlpool&){
	Whirlpool();
}

Whirlpool::~Whirlpool(){
	release();
}

void Whirlpool::onEnter(){
	Sprite::onEnter();
	//テクスチャ設定
	setTexture("stage/obj/Whirlpool.png");
}

void Whirlpool::setPosition(const float x, const float y){
	Sprite::setPosition(Vec2(x, y));
	clampPos = Vec2(x, y);
}


void Whirlpool::update(float deltatime){
	//物理エンジンで位置が微妙にずれていくので固定
	//Sprite::setPosition(MyMath::clamp(getPosition(), clampPos, clampPos));
}

void Whirlpool::onContact(Node* node){

}

bool Whirlpool::isDead(){
	return _isDead;
}

Whirlpool* Whirlpool::clone(){

	return new Whirlpool();
}