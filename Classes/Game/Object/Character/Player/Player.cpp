#include "Player.h"
#include "Game/Draw/Effect/Ripple/Support/RippleManager.h"
#include "Game/Draw/Draw2D.h"
#include "Game/Object/Character/SeaFireFly/SeaFireFlyManager.h"
#include "Game/Util/Collision/CollisionFuncManager.h"
#include "Game/Util/Collision/CollisionDelegate.h"
#include "Game/Draw/Effect/Light/SpotLight.h"
#include "Game/Draw/Effect/Light/LightManager.h"
#include "Game/Draw/Effect/Particle/SimpleParticle.h"
#include "Game/Draw/Effect/Ripple/Support/RippleCounter.h"
#include "Game/Sound/RappingAudio.h"

Player::Player() :state(normal), timer(0), rippleManager(nullptr), sprite(nullptr)
{
	retain();
	setName("Player");
	setAnchorPoint(Vec2(0,0));
	sprite = PlayerSprite::create();
	sprite->retain();
	sprite->setName("PlayerSprite");
	//波紋管理者の追加
	rippleManager = RippleManager::create();

	auto c = CollisionDelegate<Player>::create(this, &Player::onContact);
	CollisionFuncManager::getInstance()->addFunc(sprite->getName(), c);

	//ライト描画
	LightManager::getInstance()->addDrawList(2.f, &sprite->getPosition(), 2.f, true);
	LightManager::getInstance()->addDrawList(2.f, &sprite->getPosition(), 2.f, true);
	LightManager::getInstance()->addDrawList(2.f, &sprite->getPosition(), 2.f, true);
	//test
}

Player::~Player(){
	rippleManager->release();
}

Sprite* Player::createPlayer(){

	return sprite->createPlayer();
}

bool Player::init()
{

	return true;
}

/*更新*/
void Player::update(Layer* layer, float at)
{

	sprite->update(layer,state,at);
	rippleManager->update(at);
	if (timer > 0){
		action(at);
	}
	//setPosition(sprite->getPosition());
}

void Player::action(float at){
	
	timer -= at;

	if (timer < 0){
		state = normal;
	}
}

bool Player::touchBegan(Point touchPos, Vec2 layerPos)
{
	bool isTouch = false;
	if (state == whirlpool || state == damage || state == Palsy) return isTouch;

	if (sprite->touchBegan(touchPos, layerPos)){
		createRipple();
		isTouch = true;
	}
	sprite->setPhysicsState(true, true);
	
	return isTouch;
}

void Player::touchEnd(Point endPos)
{
	auto particle = SimpleParticle::create("MoveTrail", sprite->getPosition());
	addChild(particle);
	sprite->touchEnd(endPos);
}

void Player::createRipple(){
	if (!rippleManager->isEmpty())return;
	sprite->setPhysicsState(true, true);
	//sprite->getPhysicsBody()->setCollisionBitmask(false);
	timer = 5;
	////波紋の位置の調整(親スプライトの左下座標が子スプライトの0,0になるため)
	//Vec2 ripplePos = Vec2(sprite->getContentSize().width / 2, sprite->getContentSize().height / 2);
	// 波紋の生成
	rippleManager->playRipple(this, RippleTag::TAG_PLAYER, sprite->getPosition());
	RippleCounter::init();
	auto se = RappingAudio::getInstance()->getSE((SETag)RippleCounter::g_RippleCount);
	se->play();
	//ライト生成
	
	//LightManager::getInstance()->addDrawList(10.f, &sprite->getPosition(), 2.0f, false);
}

void Player::onContact(Node* node){
	if (strstr(node->getName().c_str(), "Enemy")){
		timer = 10;
		state = damage;
		sprite->setPhysicsState(true, false);
		sprite->getPhysicsBody()->setCollisionBitmask(true);
		auto particle = SimpleParticle::create("PlayerDelete", sprite->getPosition());
		addChild(particle);
	}

	if (strstr(node->getName().c_str(), "SeaFireFly")){
	}

	if (strstr(node->getName().c_str(), "Alga")){
		timer = 5;
		state = halfmove;
	}

	if (strstr(node->getName().c_str(), "JellyFish")){
		timer = 5;
		state = Palsy;
		auto particle = SimpleParticle::create("Palsy", sprite->getPosition());
		addChild(particle);
	}

	if (strstr(node->getName().c_str(), "Whirlpool")){
		timer = 10;
		state = whirlpool;
		sprite->setPhysicsState(true, false);
		sprite->getPhysicsBody()->setCollisionBitmask(true);
	}
}