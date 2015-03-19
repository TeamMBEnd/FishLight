#include "SmallStone.h"
#include "Game/Util/Collision/CollisionFuncManager.h"
#include "Game/Util/Collision/CollisionDelegate.h"
#include "SyStem/MyMath.h"

SmallStone::SmallStone(){
	Sprite::init();
	_isDead = false;
	PhysicsMaterial material;
	material.density = 0.f;
	material.restitution = 0.f;
	material.friction = 0.f;
	PhysicsBody* pb = PhysicsBody::createCircle(54, material);
	//物理挙動の設定
	pb->setMass(10000.0f);
	pb->setDynamic(true);
	pb->setContactTestBitmask(true);
	setPhysicsBody(pb);
	setName("SmallStone");

	retain();
}

SmallStone::SmallStone(const SmallStone&){

}

SmallStone::~SmallStone(){
	release();
}

void SmallStone::onEnter(){
	Sprite::onEnter();
	//テクスチャ設定
	setTexture("stage/obj/StoneSmall.png");
}

void SmallStone::setPosition(const float x, const float y){
	Sprite::setPosition(Vec2(x, y));
	clampPos = Vec2(x, y);
}

//void Stone::setPosition(const Vec2& pos){
//	Node::setPosition(MyMath::clamp(getPosition(), clampPos, clampPos));
//}

void SmallStone::update(float deltatime){
	//物理エンジンで位置が微妙にずれていくので固定
	//Sprite::setPosition(MyMath::clamp(getPosition(), clampPos, clampPos));
}

void SmallStone::onContact(Node* node){

	//removeFromParent();
	//_isDead = true;

}

bool SmallStone::isDead(){
	return _isDead;
}

SmallStone* SmallStone::clone(){

	return new SmallStone();
}