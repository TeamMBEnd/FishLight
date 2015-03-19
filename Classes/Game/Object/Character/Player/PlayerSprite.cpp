#include "System/MyMath.h"
#include "PlayerSprite.h"
#include "System/Camera.h"
#include "Game/Draw/Effect/Ripple/Support/RippleManager.h"
#include "Game/Sound/RappingAudio.h"
#include <random>


#define PI 3.14

PlayerSprite::PlayerSprite() :touchPoint(Point(0, 0)), isTouch(false), mIsSound(false)
{
	updateFunc[0] = &PlayerSprite::move;
	updateFunc[1] = &PlayerSprite::halfMove;
	updateFunc[2] = &PlayerSprite::jump;
	updateFunc[3] = &PlayerSprite::damage;
	updateFunc[4] = &PlayerSprite::palsy;

	this->retain();
}

PlayerSprite::~PlayerSprite()
{
	this->release();
}

bool PlayerSprite::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	//画面サイズの取得
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//名前を登録
	this->setName("シーマン");

	//プレイヤーに対する物理エンジンを設定
	PhysicsBody* playerPb = PhysicsBody::createCircle(30);
	CCLOG("%i", this->getContentSize().width / 2);
	playerPb->setTag(2);

	//キャラの重さを設定
	playerPb->setMass(1.0f);

	//プレイヤーに物理エンジンを設定
	this->setPhysicsBody(playerPb);

	//タグを設定
	this->setTag(1);

	//初期座標の指定
	this->setPosition(Point(354, 352));


	playerPb->setDynamic(true);
	playerPb->setContactTestBitmask(true);

	return true;
}

void PlayerSprite::onEnter()
{
	Sprite::onEnter();
	this->setTexture("stage/chara/Player.png");
}

Sprite* PlayerSprite::createPlayer()
{
	
	//プレイヤーを返す
	return this;
}

/*更新*/
void PlayerSprite::update(Layer* layer,int state,float at)
{

	(this->*updateFunc[state])(layer , at);

}

void PlayerSprite::setPhysicsState(bool dynamic, bool contact){
	getPhysicsBody()->setDynamic(dynamic);
	getPhysicsBody()->setContactTestBitmask(contact);
}


void PlayerSprite::move(Layer* layer, float at)
{
	mIsSound = false;
	//移動範囲の設定　（半径とってないよ
	this->getPhysicsBody()->setVelocity(this->getPhysicsBody()->getVelocity()*0.99);
	
	Vec2 pos = this->getPosition();
	int size = getContentSize().height;

	this->setPosition(MyMath::clamp(pos, Vec2(size/2, size/2),Vec2(6400-size/2,5376-size/2)));
}

void PlayerSprite::halfMove(Layer* layer, float at){
	this->getPhysicsBody()->setVelocity(this->getPhysicsBody()->getVelocity()*0.5);
	Vec2 pos = this->getPosition();
	this->setPosition(MyMath::clamp(pos, Vec2(0, 0), Vec2(6400, 5376)));
}

void PlayerSprite::jump(Layer* layer, float at){

	//画面サイズの取得
	Size visibleSize = Director::getInstance()->getVisibleSize();

	this->getPhysicsBody()->setVelocity(this->getPhysicsBody()->getVelocity()*0.f);
	if (!getActionByTag(99) && getOpacity() > 0){
		auto fadeOut = FadeOut::create(3);
		auto spen = RotateBy::create(3, 1080);
		auto spawn = Spawn::create(fadeOut, spen, nullptr);
		spawn->setTag(99);
		runAction(spawn);

	}
	if (!getActionByTag(99) && getOpacity() <= 0){

		int randX = (int)(rand() % 6400);
		int randY = (int)(rand() % 5376);

		this->setPosition(MyMath::clamp(Vec2(randX,randY), Vec2(0, 0), Vec2(6400, 5376)));
		auto fadeIn = FadeIn::create(3);
		fadeIn->setTag(99);
		runAction(fadeIn);
	}
	
	
	

}

void PlayerSprite::damage(Layer* layer, float at){
	//画面サイズの取得
	Size visibleSize = Director::getInstance()->getVisibleSize();

	this->getPhysicsBody()->setVelocity(this->getPhysicsBody()->getVelocity()*0.f);
	if (!getActionByTag(99) && getOpacity() > 0){
		auto fadeOut = FadeOut::create(3);
		auto spen = RotateBy::create(3, 1080);
		auto spawn = Spawn::create(fadeOut, spen, nullptr);
		spawn->setTag(99);
		runAction(spawn);

	}
	if (!getActionByTag(99) && getOpacity() <= 0){

		this->setPosition(354, 352);
		auto fadeIn = FadeIn::create(3);
		fadeIn->setTag(99);
		runAction(fadeIn);
	}

	//脂肪SE
	if (!mIsSound){
		auto deadSE = RappingAudio::getInstance()->getSE(DEAD);
		deadSE->play();
		mIsSound = true;
	}
}

void PlayerSprite::palsy(Layer* layer, float at){
	this->getPhysicsBody()->setVelocity(this->getPhysicsBody()->getVelocity()*0.f);
}


bool PlayerSprite::touchBegan(Point touchPos,const Vec2& layerPos)
{
	getPhysicsBody()->setDynamic(true);

	this->touchPoint = touchPos;

	Point point = touchPos - layerPos;

	Rect rect = boundingBox();
	return (rect.containsPoint(point));
}

void PlayerSprite::touchEnd(Point endPos)
{
	Vect force = -Vect(touchPoint.x - endPos.x, touchPoint.y - endPos.y);
	auto normalizeVec = ccpNormalize({ force.x, force.y });
	this->setRotation(atan2(normalizeVec.x,normalizeVec.y) * 180 / PI);
	this->getPhysicsBody()->applyImpulse(force);
}
