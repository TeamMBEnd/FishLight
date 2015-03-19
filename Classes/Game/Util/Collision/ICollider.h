#ifndef _ICOLLIDER_H_
#define _ICOLLIDER_H_

#include "cocos2d.h"

USING_NS_CC;

/**
	@class	：	ICollider
	@brief	：	衝突オブジェクトインタフェイス
	@author	：	利川聖太
 */
class ICollider
{
	
public:
	
	/**
		@brief	デストラクタ
	 */
	virtual ~ICollider() { }
	
	/**
		@brief	衝突時に呼ばれるコールバック関数
	 
		@param	otherNode	衝突したオブジェクトの情報
	 */
	virtual void onContact( Node* otherNode ) = 0;
	
protected:
	
	/**
		@brief	コンストラクタ
	 */
	ICollider() { }
};

#endif