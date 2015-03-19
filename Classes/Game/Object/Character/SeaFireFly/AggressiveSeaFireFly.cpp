#include "AggressiveSeaFireFly.h"
#include "Game/Draw/Effect/Ripple/Support/RippleTag.h"
#include "Game/Draw/Effect/Ripple/Support/RippleManager.h"
#include "Game/Draw/Effect/Light/SpotLight.h"
#include "FollowState.h"
#include "EscapeState.h"
#include "FreeState.h"
#include "System/MyMath.h"
#include "Game/Sound/RappingAudio.h"
#include "Game/Draw/Effect/Light/LightManager.h"

AggressiveSeaFireFly::AggressiveSeaFireFly() :
SeaFireFly(),
mRippleCounter(0),
alpha(0)
{
}

AggressiveSeaFireFly::~AggressiveSeaFireFly()
{
	if (getReferenceCount() != 0)
	{
		this->release();
	}
	mRippleManager->release();
}

bool AggressiveSeaFireFly::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	//波紋管理者の追加
	mRippleManager = RippleManager::create();
	return true;
}


void AggressiveSeaFireFly::update(Vec2 targetPos, Vec2 targetVel, Vec2 centerPos,float at,int group)
{
	if (mIsContact){
		// 波紋の生成
		createRipple();
		//ライト生成
		if (mNowState != FOLLOW)
		{
			changeState(std::shared_ptr<ISeaFireFlyState>(new FollowState));
		}
		mRippleCounter++;

		mIsContact = false;
	}
	mNowState = mCharaState->getState();
	//ライト描画

	mRippleManager->update(at);

	mTimer++;

	if (mTimer.getSecond() > 10)
	{
		mTimer.reset();
	}

	if (mRippleCounter >= 4)
	{
		changeState(std::shared_ptr<ISeaFireFlyState>(new EscapeState));
	}

	if (mIsDelete)
	{
		if (mRippleManager->isEmpty())
		{
			mIsDead = true;
			mIsDelete = false;
			this->getPhysicsBody()->setDynamic(false); //物理的挙動の有無
			this->getPhysicsBody()->setContactTestBitmask(false);
		}
	}
	deadCheck();
	LightManager::getInstance()->addDrawList(at, &getPosition(), 1.f, false);
}

void AggressiveSeaFireFly::onEnter()
{
	Sprite::onEnter();

	this->setTexture("stage/chara/SeaFireFly_Attack.png");
}

void AggressiveSeaFireFly::createRipple()
{
	Vec2 size = Vec2(getContentSize().width / 2, getContentSize().height / 2);
	mRippleManager->playRipple(this, RippleTag::TAG_ATTACK, size);
}

bool AggressiveSeaFireFly::isDead()
{
	return deleteEffect();
}


SEAFIREFLY AggressiveSeaFireFly::getKind()const
{
	return AGGRESSIVE;
}

bool AggressiveSeaFireFly::deadCheck()
{
	if (mNowState != ESCAPE) return false;
	alpha++;

	if (alpha >= 60)
	{
		changeState(std::shared_ptr<ISeaFireFlyState>(new FreeState()));
		//画面サイズの取得
		Size visibleSize = Director::getInstance()->getVisibleSize();

		this->getPhysicsBody()->setVelocity(this->getPhysicsBody()->getVelocity()*0.f);
		if (!getActionByTag(21) && getOpacity() > 0){
			auto fadeOut = FadeOut::create(1);
			fadeOut->setTag(21);
			runAction(fadeOut);
		}
		if (getOpacity() <= 0){

			mIsDelete = true;
			alpha = 0;
		}
		return true;
	}
	
	return false;
}
