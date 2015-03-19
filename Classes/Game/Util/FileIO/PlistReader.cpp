#include "PlistReader.h"

USING_NS_CC;

// プロパティリストの読み込み
PlistReader::ReadVector PlistReader::read( const std::string& fileName ) const
{
	// ファイルパスを取得します
	auto fileUtils	= FileUtils::getInstance();
	auto plistName	= fileUtils->fullPathForFilename( fileName );
	
	// プロパティリストのArray要素を取得します
	ValueVector array = fileUtils->getValueVectorFromFile( plistName.c_str() );
	
	// 読み込んだデータを格納するベクタを準備します
	ReadVector readVector;
	
	for ( auto map : array )
	{
		// Array要素内のDictionary要素を取得します
		auto dictionaryData = map.asValueMap();
		
		// 読み込んだデータを格納します
		readVector.push_back( dictionaryData );
	}
	
	return readVector;
}