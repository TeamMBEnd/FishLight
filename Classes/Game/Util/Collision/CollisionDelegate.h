#ifndef _COLLISION_DELEGATE_H_
#define _COLLISION_DELEGATE_H_

#include "cocos2d.h"
#include "ICollisionDelegate.h"
#include <functional>

USING_NS_CC;

/**
	@class	：	CollisionDelegate
	@brief	：	衝突判定用のデリゲート
	@author	：	利川聖太
 */
template< class T >
class CollisionDelegate : public ICollisionDelegate
{
	
public:
	
	// 型定義
	typedef void ( T::*CallbackFunc )( Node* );
	
	/**
		@brief	関数の登録
	 
		@param	object	登録するインスタンス
		@param	func	登録する関数
	 */
	void setFunc( T* object, CallbackFunc func )
	{
		mFunc = std::bind( func, object, std::placeholders::_1 );
	}
	
	/**
		@brief	関数の実行
	 
		@param	otherNode	衝突したオブジェクトの情報
	 */
	virtual void runFunc( Node* otherNode ) override
	{
		mFunc( otherNode );
	}
	
	/**
		@brief	インスタンスの生成, コールバック関数の登録
				例 : create( this, &XXX::onContact );
	 
		@param	object	登録するインスタンス
		@param	func	登録する関数
	 */
	static ICollisionDelegate* create( T* object, CallbackFunc func )
	{
		CollisionDelegate* instance = new CollisionDelegate();
		instance->setFunc( object, func );
		return instance;
	}
	
private:
	
	// メンバ変数の宣言
	std::function< void( Node* ) >	mFunc;	// コールバック関数の関数ラッパ
};

#endif