#ifndef _RELEASE_INSTANCE_H_
#define _RELEASE_INSTANCE_H_

#include "cocos2d.h"

/**
	@class	：	ReleaseInstance
	@brief	：	ノード解放用の関数オブジェクト
	@author	：	利川聖太
 */
class ReleaseInstance
{
	
public:
	
	/**
		@brief	ノードを解放するか否か
	 
		@param	instance	インスタンス
		@return				ノードを解放するか否か
	 */
	bool operator () ( cocos2d::Node* instance )
	{
		CC_SAFE_RELEASE( instance );
		return true;
	}
};

#endif