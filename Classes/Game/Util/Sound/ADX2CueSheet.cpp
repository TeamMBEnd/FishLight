#include "ADX2CueSheet.h"
#include "ADX2Converter.h"

USING_NS_CC;

// コンストラクタ
ADX2CueSheet::ADX2CueSheet()
	: mAcbHandle( nullptr ) { }

// デストラクタ
ADX2CueSheet::~ADX2CueSheet()
{
	// ハンドルの解放
	criAtomExAcb_Release( mAcbHandle );
}

// インスタンスの生成
ADX2CueSheet* ADX2CueSheet::create( const char* acb, const char* awb )
{
	auto inst = new ADX2CueSheet();
	
	if ( inst && inst->loadAcb( acb, awb ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// キューシート情報を管理するハンドルの取得
CriAtomExAcbHn ADX2CueSheet::getAcbHandle()
{
	return mAcbHandle;
}

// ACBファイルの読み込み
bool ADX2CueSheet::loadAcb( const char* acb, const char* awb )
{
	// 各リソースのファイルパスを取得します
	auto acbPath	= ADX2Converter::toFilePath( acb );
	auto awbPath	= ADX2Converter::toFilePath( awb );
	
	// ACBファイルの読み込み
	mAcbHandle = criAtomExAcb_LoadAcbFile( NULL, acbPath.c_str(), NULL, awbPath.c_str(), NULL, 0 );
	
	if ( mAcbHandle == nullptr )
	{
		// 読み込みに失敗しました
		return false;
	}
	
	// 読み込みに成功しました
	return true;
}