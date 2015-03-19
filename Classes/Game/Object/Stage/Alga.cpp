#include "Alga.h"
#include "Game/Util/Collision/CollisionFuncManager.h"
#include "Game/Util/Collision/CollisionDelegate.h"
#include "SyStem/MyMath.h"

Alga::Alga(){
	Alga::init();
	_isDead = false;
	PhysicsBody* pb = PhysicsBody::createBox(Size(450,220));
	//物理挙動の設定
	pb->setMass(100.0f);
	pb->setDynamic(true);
	pb->setContactTestBitmask(true);
	pb->setCollisionBitmask(false);
	
	setPhysicsBody(pb);

	setName("Alga");

	retain();
}

Alga::~Alga(){
	release();
}

void Alga::onEnter(){
	Sprite::onEnter();
	//テクスチャ設定
	setTexture("stage/obj/Alga.png");
}

void Alga::setPosition(const float x, const float y){
	Sprite::setPosition(Vec2(x, y));
	clampPos = Vec2(x, y);
}

void Alga::update(float deltatime){
	//物理エンジンで位置が微妙にずれていくので固定
	//Sprite::setPosition(MyMath::clamp(getPosition(), clampPos, clampPos));
}

void Alga::onContact(Node* node){


}

bool Alga::isDead(){
	return _isDead;
}

Alga* Alga::clone(){

	return new Alga();
}

