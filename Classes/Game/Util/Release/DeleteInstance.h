#ifndef _DELETE_INSTANCE_H_
#define _DELETE_INSTANCE_H_

#include "cocos2d.h"

/**
	@class	：	DeleteInstance
	@brief	：	インスタンス削除用の関数オブジェクト
	@author	：	利川聖太
 */
class DeleteInstance
{
	
public:
	
	/**
		@brief	インスタンスを削除するか否か
	 
		@param	instance	インスタンス
		@return				インスタンスを削除するか否か
	 */
	template< typename T >
	bool operator () ( T* instance )
	{
		CC_SAFE_DELETE( instance );
		return true;
	}
};

#endif