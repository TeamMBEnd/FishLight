#include "Goal.h"
#include "Game/Util/Collision/CollisionFuncManager.h"
#include "Game/Util/Collision/CollisionDelegate.h"
#include "SyStem/MyMath.h"
#include "Game/Draw/Effect/Light/SpotLight.h"
#include "Game/Draw/Effect/Light/LightManager.h"

Goal::Goal():clampPos(nullptr){
	Sprite::init();
	_isDead = false;

	PhysicsBody* pb = PhysicsBody::createCircle(25);
	pb->setMass(1000.0f);
	pb->setDynamic(true);
	pb->setContactTestBitmask(true);
	setPhysicsBody(pb);
	setName("Goal");
	
	/*-------
	 当たり判定
	 --------*/
	auto c = CollisionDelegate<Goal>::create(this, &Goal::onContact);
	CollisionFuncManager::getInstance()->addFunc(this->getName(), c);

	retain();
}

Goal::~Goal(){
	delete clampPos;
	release();
}

void Goal::onEnter(){
	Sprite::onEnter();
	setTexture("stage/obj/Goal.png");
}

void Goal::setPosition(const float x, const float y){
	Sprite::setPosition(x, y);
}

void Goal::update(float deltatime){
	if (!clampPos){
		clampPos = new Vec2(500, 500);
		LightManager::getInstance()->addDrawList(1.f, clampPos, 2.f, true);
		LightManager::getInstance()->addDrawList(1.f, clampPos, 2.f, true);
		LightManager::getInstance()->addDrawList(1.f, clampPos, 2.f, true);
		LightManager::getInstance()->addDrawList(1.f, clampPos, 2.f, true);
	}

	auto p = getParent();
	auto max = Vec2(1280, 780) - p->getPosition();
	auto min = Vec2(0, 0) - p->getPosition();

	*clampPos = Vec2(MyMath::clamp(getPosition(), min, max));

}

void Goal::onContact(Node* node){
	
	/*-------
	 当たり判定
	 --------*/
	if (strstr(node->getName().c_str(), "PlayerSprite")){
		_isDead = true;
	}
	
}

bool Goal::isDead(){

	return _isDead;
}

Goal* Goal::clone(){

	return new Goal();
}