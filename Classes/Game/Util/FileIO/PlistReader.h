#ifndef _PLIST_READER_H_
#define _PLIST_READER_H_

#include "cocos2d.h"
#include <string>
#include <vector>

/**
	@class	：	PlistReader
	@brief	：	プロパティリスト読み込みクラス
	@author	：	利川聖太
 */
class PlistReader
{
	
public:
	
	// 型定義
	typedef std::vector< cocos2d::ValueMap >	ReadVector;
	
public:
	
	/**
		@brief	プロパティリストの読み込み
	 
		@param	fileName	ファイルの名前
		@return				読み込んだデータを格納したベクタ
	 */
	ReadVector read( const std::string& fileName ) const;
};

#endif