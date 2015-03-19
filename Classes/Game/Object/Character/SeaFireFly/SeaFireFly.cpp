#include "SeaFireFly.h"
#include "FollowState.h"
#include "Game/Draw/Effect/Ripple/Support/RippleManager.h"
#include "SnapState.h"
#include "Game/Draw/Effect/Light/SpotLight.h"
#include "Game/Draw/Effect/Light/LightManager.h"
#include "Game/Draw/Effect/Particle/SimpleParticle.h"
#include "Game/Sound/RappingAudio.h"
#include "Game/Draw/Effect/Ripple/Support/RippleCounter.h"

SeaFireFly::SeaFireFly() :mIsContact(false), mNowState(FREE), mIsDead(false), mTimer(0), mAngle(0), mEffectCount(0), mDeleteCount(0), mIsDelete(false)
{
	this->retain();
}

SeaFireFly::~SeaFireFly()
{
	if (getReferenceCount() != 0)
	{
		release();
	}
	mRippleManager->release();
}

bool SeaFireFly::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	//波紋管理者の追加
	mRippleManager = RippleManager::create();

	return true;
}


void SeaFireFly::update(Vec2 targetPos, Vec2 targetVel, Vec2 centerPos, float dt,int group)
{
	if (mIsContact){
		// 波紋の生成
		createRipple();
		//ライト生成
		LightManager::getInstance()->addDrawList(10.f, &getPosition(), 3.f, false);
		
		if (mNowState != FOLLOW&&group < 4)
		{
			changeState(std::shared_ptr<ISeaFireFlyState>(new FollowState));
		}

		mIsContact = false; 
	}

	mNowState = mCharaState->getState();
	mRippleManager->update(dt);
	mTimer++;

	if (mTimer.getSecond() > 16)
	{
		mTimer.reset();
	}

	if (mIsDelete)
	{
		if (mRippleManager->isEmpty())
		{
			mIsDead = true;
			this->getPhysicsBody()->setDynamic(false); //物理的挙動の有無
			this->getPhysicsBody()->setContactTestBitmask(false);
			this->getPhysicsBody()->setCollisionBitmask(false);
		}
	}
	LightManager::getInstance()->addDrawList(dt, &getPosition(), 1.f, false);
}


void SeaFireFly::move( SeaFireFly* targetObject, Vec2 targetVel, Vec2 centerPos)
{
	mCharaState->update(this, targetObject, targetVel, centerPos);
}


void SeaFireFly::onEnter()
{
	Sprite::onEnter();
	/* 自身にテクスチャをセット */
	setTexture("stage/chara/SeaFireFly.png");
}


SeaFireFly* SeaFireFly::create(Vect position, const std::string& name)
{

	/* 初期座標の設定 */
	this->setPosition( position );


	/* ウミホタルに対しての物理エンジンを生成 */
	PhysicsBody* body = PhysicsBody::createCircle(25);

	this->setName(name);
	body->setDynamic(true); //物理的挙動の有無
	body->setContactTestBitmask(true);


	body->setMass(1.0f);

	body->setCollisionBitmask(true);

	/* 物理エンジンをウミホタルに設定 */
	this->setPhysicsBody( body );

	
	//LightManager::getInstance()->addDrawList(1, &getPosition(), 1.f, true,mIsLight);

	/* 自身を返す */
	return this;
}



void SeaFireFly::changeState(std::shared_ptr<ISeaFireFlyState> charaState)
{
	mCharaState = charaState;
}

void SeaFireFly::onContact(Node* node){
	if (strstr(node->getName().c_str(), "Ripple"))
	{
		if (mTimer.getTime() == 0){
			mIsContact = true;
			mTimer.begin();

			RippleCounter::add();
			auto se = RappingAudio::getInstance()->getSE((SETag)RippleCounter::g_RippleCount);
			se->play();
		}
	}

	if (strstr(node->getName().c_str(), "Enemy"))
	{
		setVisible(false);
		//mIsDead = true;
		deleteEffect();
		mIsDelete = true;
		
		//脂肪SE
		auto deadSE = RappingAudio::getInstance()->getSE(ENEMYDEAD);
		deadSE->play();
	}
}

void SeaFireFly::touchBegan(Point touchPos,Vec2 layerPos){
	Point point = touchPos - layerPos;

	Rect rect = boundingBox();

	if (rect.containsPoint(point)){
		getPhysicsBody()->setDynamic(true); //物理的挙動の有無
		
		getPhysicsBody()->setContactTestBitmask(true);
	}

	mTouchPoint = touchPos;
}

void SeaFireFly::touchEnd(Point endPos)
{
	changeState(std::shared_ptr<ISeaFireFlyState>(new SnapState(mTouchPoint,endPos)));
}

bool SeaFireFly::isDead()
{
	return mIsDead;
}

State SeaFireFly::getState()
{
	return mNowState;
}

void SeaFireFly::createRipple()
{
	Vec2 size = Vec2(getContentSize().width / 2, getContentSize().height / 2);
	mRippleManager->playRipple(this, RippleTag::TAG_SEAFIREFLY, size);
}

SEAFIREFLY SeaFireFly::getKind() const
{
	return NORMAL;
}

bool SeaFireFly::deleteEffect()
{
	if (!mIsDead)return false;
	if (!this->getParent()) return true;
	mDeleteCount += 64;
	mEffectCount += 64;
	setOpacity(256 - mEffectCount);
	auto particle = SimpleParticle::create("SeaFireFlyDelete", this->getPosition());
	auto parent = this->getParent();
	parent->getChildByName("Player")->addChild(particle);
	mIsDead = true;
	removeFromParent();
	
	return true;
}

