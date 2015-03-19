#include "CollisionFuncManager.h"
#include "../Release/DeleteContainer.h"

// デストラクタ
CollisionFuncManager::~CollisionFuncManager()
{
	// コンテナの解放
	DeleteContainer::cleanMap( mDelegateContainer );
}

// インスタンスの取得
CollisionFuncManager* CollisionFuncManager::getInstance()
{
	// 唯一のインスタンスを保証します
	static CollisionFuncManager instance;
	return &instance;
}

// コールバック関数の追加
void CollisionFuncManager::addFunc( const std::string& nodeName, ICollisionDelegate* delegate )
{
	mDelegateContainer[ nodeName ] = delegate;
}

// コールバック関数の削除
void CollisionFuncManager::deleteFunc( const std::string& nodeName )
{
	mDelegateContainer.erase( nodeName );
}

// 衝突時に呼ばれるコールバック関数
bool CollisionFuncManager::onContact( PhysicsContact& contact )
{
	// 衝突したノードを取得します
	auto nodeA = contact.getShapeA()->getBody()->getNode();
	auto nodeB = contact.getShapeB()->getBody()->getNode();
	
	if ( !nodeA || !nodeB )
	{
		// 取得したノードが不正の場合、衝突判定は発生しません
		return false;
	}
	
	// コールバック関数の実行
	runFunc( nodeA->getName(), nodeB );
	runFunc( nodeB->getName(), nodeA );
	return true;
}

// コールバック関数の実行
void CollisionFuncManager::runFunc( const std::string& key, Node* otherNode )
{
	// マップ検索用イテレータの準備
	auto findItor = mDelegateContainer.find( key );
	
	if ( findItor != mDelegateContainer.end() )
	{
		// 検索に掛かった場合のみ実行します
		mDelegateContainer[ key ]->runFunc( otherNode );
	}
}