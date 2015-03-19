#include "FileReader.h"

// コンストラクタ
FileReader::FileReader()
	: mUserDefault( UserDefault::getInstance() ) { }

// デストラクタ
FileReader::~FileReader() { }

// 整数値の読み込み
int FileReader::readInteger( const std::string& key ) const
{
	return mUserDefault->getIntegerForKey( key.c_str() );
}

// 浮動小数点数値の読み込み
float FileReader::readFloat( const std::string& key ) const
{
	return mUserDefault->getFloatForKey( key.c_str() );
}

// 文字列の読み込み
std::string FileReader::readString( const std::string& key ) const
{
	return mUserDefault->getStringForKey( key.c_str() );
}

// 真偽値の読み込み
bool FileReader::readBoolean( const std::string& key ) const
{
	return mUserDefault->getBoolForKey( key.c_str() );
}