#include "StageNumberWriter.h"

StageNumberWriter::StageNumberWriter(){
	
}

StageNumberWriter::~StageNumberWriter(){
	
}

void StageNumberWriter::writeStageNumber( const std::string &value )
{
	// インスタンスの取得
	auto userDef = UserDefault::getInstance();
	
	// 値の書き込み
	userDef->setStringForKey("StageNumber", value);
	userDef->flush();
}