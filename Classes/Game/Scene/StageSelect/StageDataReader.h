#ifndef _STAGE_DATA_READER_H_
#define _STAGE_DATA_READER_H_

#include "Game/Util/FileIO/ReadData.h"
#include <string>
#include <vector>

/**
	@class	：	StageDataReader
	@brief	：	ステージデータの読み込みクラス
	@author	：	利川聖太
 */
class StageDataReader
{
	
public:
	
	// 型定義
	typedef std::vector< ReadData >	StageDataVector;
	
public:
	
	/**
		@brief	ステージデータの読み込み
	 
		@param	fileName	ファイルの名前
		@return				読み込んだデータを格納したベクタ
	 */
	StageDataVector read( const std::string& fileName );
	
private:
	
	/**
		@brief	デバッグ出力
	 
		@param	data	出力するパラメータ
	 */
	void debugLog( const ReadData& data );
};

#endif