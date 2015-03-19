#ifndef _DELETE_CONTAINER_H_
#define _DELETE_CONTAINER_H_

#include "cocos2d.h"
#include "DeleteInstance.h"
#include <list>
#include <map>

/**
	@namespace	：	DeleteContainer
	@brief		：	インスタンスコンテナ削除用の名前空間
	@author		：	利川聖太
 */
namespace DeleteContainer
{
	/**
		@brief	リストの全要素削除
	 
		@param	instanceList	要素を削除するリスト
	 */
	template< typename T >
	void cleanList( std::list< T* >& instanceList )
	{
		instanceList.remove_if( DeleteInstance() );
		instanceList.clear();
	}
	
	/**
		@brief	マップの全要素削除
	 
		@param	instanceMap	要素を削除するマップ
	 */
	template< typename KEY, typename VALUE >
	void cleanMap( std::map< KEY, VALUE* >& instanceMap )
	{
		auto itor	= instanceMap.begin();
		auto end	= instanceMap.end();
		
		while ( itor != end )
		{
			delete itor->second;
			itor++;
		}
		
		instanceMap.clear();
	}
}

#endif