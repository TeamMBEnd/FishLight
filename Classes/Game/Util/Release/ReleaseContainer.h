#ifndef _RELEASE_CONTAINER_H_
#define _RELEASE_CONTAINER_H_

#include "cocos2d.h"
#include "ReleaseInstance.h"
#include <list>
#include <map>

/**
	@namespace	：	ReleaseContainer
	@brief		：	ノードコンテナ解放用の名前空間
	@author		：	利川聖太
 */
namespace ReleaseContainer
{
	/**
		@brief	リストの全要素解放
	 
		@param	nodeList	要素を解放するリスト
	 */
	template< typename T >
	void cleanList( std::list< T* >& nodeList )
	{
		nodeList.remove_if( ReleaseInstance() );
		nodeList.clear();
	}
	
	/**
		@brief	マップの全要素解放
	 
		@param	nodeMap	要素を解放するマップ
	 */
	template< typename KEY, typename VALUE >
	void cleanMap( std::map< KEY, VALUE* >& nodeMap )
	{
		auto itor	= nodeMap.begin();
		auto end	= nodeMap.end();
		
		while ( itor != end )
		{
			CC_SAFE_RELEASE( itor->second );
			itor++;
		}
		
		nodeMap.clear();
	}
};

#endif