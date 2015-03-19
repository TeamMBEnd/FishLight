#include "StageDataReader.h"
#include "Game/Util/FileIO/PlistReader.h"

// ステージデータの読み込み
StageDataReader::StageDataVector StageDataReader::read( const std::string& fileName )
{
	// plistファイルを読み込みます
	PlistReader		reader;
	auto valueMap =	reader.read( fileName );
	
	// 読み込んだデータを格納するベクタを準備します
	StageDataVector stageData;
	
	for ( auto map : valueMap )
	{
		// 読み込んだデータを格納します
		ReadData data;
		data.textureName	= map.at( "textureName"	).asString();
		data.positionX		= map.at( "positionX"	).asInt();
		data.positionY		= map.at( "positionY"	).asInt();
		data.scaleX			= map.at( "scaleX"		).asFloat();
		data.scaleY			= map.at( "scaleY"		).asFloat();
		stageData.push_back( data );
		
		// デバック出力
		debugLog( data );
	}
	
	return stageData;
}

// デバッグ出力
void StageDataReader::debugLog( const ReadData& data )
{
	CCLOG( "テクスチャの名前 : %s",	data.textureName.c_str()	);
	CCLOG( "X軸の座標 : %i",			data.positionX				);
	CCLOG( "Y軸の座標 : %i",			data.positionY				);
	CCLOG( "X軸の拡大率 : %f",		data.scaleX					);
	CCLOG( "Y軸の拡大率 : %f",		data.scaleY					);
}