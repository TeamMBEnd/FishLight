#include "SeaFireFlyManager.h"
#include "FollowState.h"
#include "FreeState.h"
#include <memory>
#include <string>
#include "Game/Util/Collision/CollisionFuncManager.h"
#include "Game/Util/Collision/CollisionDelegate.h"
#include "Game/Util/Release/ReleaseInstance.h"
#include "SeaFireFlyRemove.h"
#include "Game/Scene/Result/Support/ResultData.h"

SeaFireFlyManager::SeaFireFlyManager() :mTimer(0), lostSeaFireFly(0)
{
	mContainer.clear();
	retain();
}

SeaFireFlyManager::~SeaFireFlyManager()
{
	cleanUp();
	release();
}

bool SeaFireFlyManager::init()
{
	mContainer.clear();

	return true;
}

void SeaFireFlyManager::update(Vec2 targetPos, Vec2 targetVel,float dt)
{
	for (auto seaFireFly : mContainer)
	{
		if ( !seaFireFly ) return;
		seaFireFly->update(targetPos, targetVel, targetPos, dt,aliveSeaFireFly());

		SeaFireFlyContainer::iterator it;
		for (it = mContainer.begin(); it != mContainer.end();)
		{
			seaFireFly->move((*it), targetVel, targetPos);
			it++;
		}

		lostCounter(seaFireFly);
		
	}
	mTimer++;
	mContainer.remove_if(SeaFireFlyRemove());
}

void SeaFireFlyManager::add(Node* player, SeaFireFly* instance, Vec2 position, State state)
{
	auto str = "SeaFireFly" + std::to_string( mContainer.size() );
	auto seaFireFly = instance->create(position, str);
	if (state == FOLLOW)
		seaFireFly->changeState(std::shared_ptr<ISeaFireFlyState>(new FollowState()));
	else if (state==FREE)
		seaFireFly->changeState(std::shared_ptr<ISeaFireFlyState>(new FreeState()));

	player->addChild(seaFireFly,0);
	seaFireFly->retain();

	auto c = CollisionDelegate<SeaFireFly>::create(seaFireFly, &SeaFireFly::onContact);
	CollisionFuncManager::getInstance()->addFunc(seaFireFly->getName(), c);
	
	mContainer.push_back(seaFireFly);
}

void SeaFireFlyManager::touch(Point touchPos, Vec2 layerPos)
{

	for (auto seaFireFly : mContainer)
	{
		seaFireFly->touchBegan(touchPos,layerPos);
	}
	mTimer.begin();
}

bool SeaFireFlyManager::touchEnd(Point endPos)
{
	const int snapCount = 3;

	if (mTimer.getSecond() < snapCount)
	{
		mTimer.reset();
		return false;
	}

	if (!containerCheck())return false;

	SeaFireFlyContainer::iterator it = mContainer.begin();

	
	
	while ((*it)->getState() != FOLLOW)
	{
		it++;
	}

	(*it)->touchEnd(endPos);

	mTimer.reset();

	return true;
}

void SeaFireFlyManager::cleanUp()
{
	mContainer.remove_if( ReleaseInstance() );
}


bool SeaFireFlyManager::containerCheck()
{
	for (auto seaFireFly : mContainer)
	{
		if (seaFireFly->getState() == FOLLOW)
		{
			return true;
		}
	}
	return false;
}


float SeaFireFlyManager::aliveSeaFireFly(){
	
	int seaFireFlyCount = 0;
	
	if(!containerCheck())return seaFireFlyCount;
	
	for (auto seaFireFly : mContainer)
	{
		if(seaFireFly->getState() == FOLLOW 
			&& seaFireFly->getKind() == NORMAL)
		{
			seaFireFlyCount++;
		}
	}
	return seaFireFlyCount;
}

ResultData SeaFireFlyManager::seaFireFlyCheck()
{
	int seaFireFly = aliveSeaFireFly();
	
	ResultData data(seaFireFly, 0, lostSeaFireFly,isParfect());

	return data;
}

void SeaFireFlyManager::lostCounter(SeaFireFly* seaFireFly)
{
	if (seaFireFly->getKind() != NORMAL)return;

	if (seaFireFly->isDead())
	{
		++lostSeaFireFly;
	}
}

bool SeaFireFlyManager::isParfect()
{
	const int tortalNumber = 4;
	int seaFireFly = aliveSeaFireFly();
	if (tortalNumber == seaFireFly)
		return true;
	return false;
}