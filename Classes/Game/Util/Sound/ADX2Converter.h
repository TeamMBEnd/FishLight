#ifndef _ADX2_CONVERTER_H_
#define _ADX2_CONVERTER_H_

#include <string>

/**
	@class	：	ADX2Converter
	@brief	：	コンバータクラス
				プラットフォーム依存の物を変換するクラスです。
 */
class ADX2Converter
{
	
public:
	
	/**
		@brief	ファイルパスの変換
	 
		@param	filePath	ファイルパス
		@return				変換済みのファイルパス
	 */
	static std::string toFilePath( const char* filePath );
	
private:
	
	/**
		@brief	コンストラクタ
	 */
	ADX2Converter() = delete;
	
	/**
		@brief	デストラクタ
	 */
	~ADX2Converter() = delete;
};

#endif