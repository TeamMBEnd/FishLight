#include "CollisionListener.h"
#include "CollisionFuncManager.h"

// 初期化
bool CollisionListener::init()
{
	// リスナを生成します
	auto contactListener = EventListenerPhysicsContact::create();
	
	// 衝突時に呼ばれるコールバック関数を登録します
	contactListener->onContactBegin = [ & ]( PhysicsContact& contact )
	{
		return CollisionFuncManager::getInstance()->onContact( contact );
	};
	
	// リスナを登録します
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority( contactListener, this );
	
	return true;
}