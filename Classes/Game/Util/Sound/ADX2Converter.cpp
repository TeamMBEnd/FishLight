#include "cocos2d.h"
#include "ADX2Converter.h"

USING_NS_CC;

// ファイルパスの変換
std::string ADX2Converter::toFilePath( const char* filePath )
{
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC )
	
	// iOS, Mac用
	return FileUtils::getInstance()->fullPathForFilename( filePath );
	
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID ) || ( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
	
	// Android, Win32用
	return std::string( filePath );
	
#endif
}