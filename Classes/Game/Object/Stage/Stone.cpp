#include "Stone.h"
#include "Game/Util/Collision/CollisionFuncManager.h"
#include "Game/Util/Collision/CollisionDelegate.h"
#include "SyStem/MyMath.h"

Stone::Stone(){
	Sprite::init();
	_isDead = false;
	PhysicsMaterial material;
	material.density = 0.f;
	material.restitution = 0.f;
	material.friction = 0.f;
	PhysicsBody* pb = PhysicsBody::createCircle(120, material);
	//物理挙動の設定
	pb->setMass(10000.0f);
	pb->setDynamic(true);
	pb->setContactTestBitmask(true);
	setPhysicsBody(pb);
	setName("Stone");

	retain();
}

Stone::Stone(const Stone&){

}

Stone::~Stone(){
	release();
}

void Stone::onEnter(){
	Sprite::onEnter();
	//テクスチャ設定
	setTexture("stage/obj/StoneNormal.png");
}

void Stone::setPosition(const float x, const float y){
	Sprite::setPosition(Vec2(x,y));
	clampPos = Vec2(x, y);
}

//void Stone::setPosition(const Vec2& pos){
//	Node::setPosition(MyMath::clamp(getPosition(), clampPos, clampPos));
//}

void Stone::update(float deltatime){
	//物理エンジンで位置が微妙にずれていくので固定
	//Sprite::setPosition(MyMath::clamp(getPosition(), clampPos, clampPos));
}

void Stone::onContact(Node* node){
	
	//removeFromParent();
	//_isDead = true;
	
}

bool Stone::isDead(){
	return _isDead;
}

Stone* Stone::clone(){

	return new Stone();
}