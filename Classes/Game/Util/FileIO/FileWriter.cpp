#include "FileWriter.h"

// コンストラクタ
FileWriter::FileWriter()
	: mUserDefault( UserDefault::getInstance() ) { }

// デストラクタ
FileWriter::~FileWriter() { }

// 整数値の書き込み
void FileWriter::writeInteger( const std::string& key, int value )
{
	mUserDefault->setIntegerForKey( key.c_str(), value );
	mUserDefault->flush();
}

// 浮動小数点数値の書き込み
void FileWriter::writeFloat( const std::string& key, float value )
{
	mUserDefault->setFloatForKey( key.c_str(), value );
	mUserDefault->flush();
}

// 文字列の書き込み
void FileWriter::writeString( const std::string& key, std::string value )
{
	mUserDefault->setStringForKey( key.c_str(), value );
	mUserDefault->flush();
}

// 真偽値の書き込み
void FileWriter::writeBoolean( const std::string& key, bool value )
{
	mUserDefault->setBoolForKey( key.c_str(), value );
	mUserDefault->flush();
}