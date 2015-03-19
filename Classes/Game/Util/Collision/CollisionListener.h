#ifndef _COLLISION_LISTENER_H_
#define _COLLISION_LISTENER_H_

#include "cocos2d.h"

USING_NS_CC;

/**
	@class	：	CollisionListener
	@brief	：	衝突検知リスナクラス
	@author	：	利川聖太
 */
class CollisionListener : public Node
{
	
public:
	
	/**
		@brief	コンストラクタ
	 */
	CollisionListener() = default;
	
	/**
		@brief	デストラクタ
	 */
	~CollisionListener() = default;
	
	/**
		@brief	インスタンスの生成
	 */
	CREATE_FUNC( CollisionListener );
	
	/**
		@brief	初期化
	 
		@return	初期化が完了したか否か
	 */
	virtual bool init() override;
};

#endif