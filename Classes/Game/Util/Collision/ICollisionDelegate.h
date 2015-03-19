#ifndef _ICOLLISION_DELEGATE_H_
#define _ICOLLISION_DELEGATE_H_

#include "cocos2d.h"

USING_NS_CC;

/**
	@class	：	ICollisionDelegate
	@brief	：	衝突判定用のデリゲートインタフェイス
	@author	：	利川聖太
 */
class ICollisionDelegate
{
	
public:
	
	/**
		@brief	コンストラクタ
	 */
	ICollisionDelegate() { }
	
	/**
		@brief	デストラクタ
	 */
	virtual ~ICollisionDelegate() { }
	
	/**
		@brief	関数の実行
	 
		@param	otherNode	衝突したオブジェクトの情報
	 */
	virtual void runFunc( Node* otherNode ) = 0;
};

#endif