#ifndef _FILE_WRITER_H_
#define _FILE_WRITER_H_

#include "cocos2d.h"
#include <string>

USING_NS_CC;

/**
	@class	：	FileWriter
	@brief	：	ファイル書き込みクラス
	@author	：	利川聖太
 */
class FileWriter
{
	
public:
	
	/**
		@brief	コンストラクタ
	 */
	FileWriter();
	
	/**
		@brief	デストラクタ
	 */
	~FileWriter();
	
	/* ===== 各型に対応した書き込み ================================================== */
	void writeInteger( const std::string& key, int value );
	void writeFloat( const std::string& key, float value );
	void writeString( const std::string& key, std::string value );
	void writeBoolean( const std::string& key, bool value );
	/* =========================================================================== */
	
private:
	
	// メンバ変数の宣言
	UserDefault*	mUserDefault;	// ユーザデフォルト
};

#endif