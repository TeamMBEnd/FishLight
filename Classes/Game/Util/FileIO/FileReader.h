#ifndef _FILE_READER_H_
#define _FILE_READER_H_

#include "cocos2d.h"
#include <string>

USING_NS_CC;

/**
	@class	：	FileReader
	@brief	：	ファイル読み込みクラス
	@author	：	利川聖太
 */
class FileReader
{
	
public:
	
	/**
		@brief	コンストラクタ
	 */
	FileReader();
	
	/**
		@brief	デストラクタ
	 */
	~FileReader();
	
	/* ===== 各型に対応した読み込み ================================================== */
	int readInteger( const std::string& key ) const;
	float readFloat( const std::string& key ) const;
	std::string readString( const std::string& key ) const;
	bool readBoolean( const std::string& key ) const;
	/* =========================================================================== */
	
private:
	
	// メンバ変数の宣言
	UserDefault*	mUserDefault;	// ユーザデフォルト
};

#endif