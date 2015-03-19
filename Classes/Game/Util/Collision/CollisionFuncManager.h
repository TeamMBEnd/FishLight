#ifndef _COLLISION_FUNC_MANAGER_H_
#define _COLLISION_FUNC_MANAGER_H_

#include "cocos2d.h"
#include "ICollisionDelegate.h"
#include <string>
#include <map>

USING_NS_CC;

/**
	@class	：	CollisionFuncManager
	@brief	：	衝突時のコールバック関数を保持する管理者クラス
	@author	：	利川聖太
 */
class CollisionFuncManager
{
	
public:
	
	/**
		@brief	デストラクタ
	 */
	~CollisionFuncManager();
	
	/**
		@brief	インスタンスの取得
	 
		@return	インスタンス
	 */
	static CollisionFuncManager* getInstance();
	
	/**
		@brief	コールバック関数の追加
	 
		@param	nodeName	ノードの名前
		@param	delegate	追加するデリゲート
	 */
	void addFunc( const std::string& nodeName, ICollisionDelegate* delegate );
	
	/**
		@brief	コールバック関数の削除
	 
		@param	nodeName	ノードの名前
	 */
	void deleteFunc( const std::string& nodeName );
	
	/**
		@brief	衝突時に呼ばれるコールバック関数
	 
		@param	contact	衝突したオブジェクトの情報
		@return			衝突したか否か
	 */
	bool onContact( PhysicsContact& contact );
	
private:
	
	/**
		@brief	コンストラクタ, コピーコンストラクタ, 代入演算子の禁止
	 */
	CollisionFuncManager() { }
	CollisionFuncManager( const CollisionFuncManager& ) = delete;
	CollisionFuncManager& operator = ( const CollisionFuncManager& ) = delete;
	
	/**
		@brief	コールバック関数の実行
	 
		@param	key			関数を取り出すためのキー
		@param	otherNode	衝突したオブジェクトの情報
	 */
	void runFunc( const std::string& key, Node* otherNode );
	
public:
	
	// 型定義
	typedef std::map< std::string, ICollisionDelegate* >	DelegateContainer;
	
	// メンバ変数の宣言
	DelegateContainer	mDelegateContainer;	// デリゲートのコンテナ
};

#endif