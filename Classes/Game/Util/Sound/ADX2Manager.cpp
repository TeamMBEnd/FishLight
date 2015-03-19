#include "ADX2Manager.h"
#include "ADX2Converter.h"

USING_NS_CC;

// コンストラクタ
ADX2Manager::ADX2Manager()
	: mDbasID( 0 ) { }

// デストラクタ
ADX2Manager::~ADX2Manager()
{
	// ACFの登録解除
	criAtomEx_UnregisterAcf();
	
	// DSPバス設定のデタッチ
	criAtomEx_DetachDspBusSetting();
	
	// D-BASの破棄
	criAtomDbas_Destroy( mDbasID );
	
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
	
	// Win32用のライブラリ終了
	criAtomEx_Finalize_PC();
	
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_MAC )
	
	// Mac用のライブラリ終了
	criAtomEx_Finalize_MACOSX();
	
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
	
	// iOS用のライブラリ終了
	criAtomEx_Finalize_IOS();
	
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	
	// Android用のライブラリ終了
	criAtomEx_Finalize_ANDROID();
	
#endif
}

// インスタンスの生成
ADX2Manager* ADX2Manager::create()
{
	auto inst = new ADX2Manager();
	
	if ( inst )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// 初期化
void ADX2Manager::init( const std::string& acf )
{
	// エラー検知用のコールバック関数
	auto errorCallback = []( const CriChar8* errID, CriUint32 p1, CriUint32 p2, CriUint32* parray )
	{
		const CriChar8* errMsg;
		errMsg = criErr_ConvertIdToMessage( errID, p1, p2 );
		CCLOG( "%s\n", errMsg );
	};
	
	// メモリ確保, 解放関数
	auto userAlloc	= []( void* obj, CriUint32 size )	{ return malloc( size );	};
	auto userFree	= []( void* obj, void* ptr )		{ free( ptr );				};
	
	// エラーコールバック関数の登録
	criErr_SetCallback( errorCallback );
	
	// ユーザアロケータの登録
	criAtomEx_SetUserAllocator( userAlloc, userFree, NULL );
	
	// プラットフォーム別の初期化
	initPlatformSetting();
	
	// ファイルパスを取得します
	auto acfPath = ADX2Converter::toFilePath( acf.c_str() );
	
	// ACFファイルの登録
	criAtomEx_RegisterAcfFile( NULL, acfPath.c_str(), NULL, 0 );
	
	// DSPバス設定のアタッチ
	criAtomEx_AttachDspBusSetting( "DspBusSetting_0", NULL, 0 );
	
	// D-BASの生成
	mDbasID = criAtomDbas_Create( NULL, NULL, 0 );
}

// アプリ中断時のコールバック関数
void ADX2Manager::pauseApp()
{
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
	
	// iOS用のサウンド停止
	criAtomEx_StopSound_IOS();
	
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	
	// Android用のサウンド停止
	criAtomEx_StopSound_ANDROID();
	
#endif
}

// アプリ再開時のコールバック関数
void ADX2Manager::resumeApp()
{
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
	
	// iOS用のサウンド再開
	criAtomEx_StartSound_IOS();
	
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	
	// Android用のサウンド再開
	criAtomEx_StartSound_ANDROID();
	
#endif
}

// プラットフォーム別の初期化
void ADX2Manager::initPlatformSetting()
{
	// ファイルシステムライブラリを初期化します
	CriFsConfig fsConfig;
	criFs_SetDefaultConfig( &fsConfig );
	fsConfig.num_loaders = 32;
	
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
	
	// Win32用の初期化
	CriAtomExConfig_PC configPC;
	criAtomEx_SetDefaultConfig_PC( &configPC );
	configPC.atom_ex.fs_config				= &fsConfig;
	configPC.hca_mx.output_sampling_rate	= 32000;
	criAtomEx_Initialize_PC( &configPC, NULL, 0 );
	
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_MAC )
	
	// Mac用の初期化
	CriAtomExConfig_MACOSX configMacOSX;
	criAtomEx_SetDefaultConfig_MACOSX( &configMacOSX );
	configMacOSX.atom_ex.fs_config				= &fsConfig
	configMacOSX.hca_mx.output_sampling_rate	= 32000;
	criAtomEx_Initialize_MACOSX( &configMacOSX, NULL, 0 );
	
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
	
	// iOS用の初期化
	CriAtomExConfig_IOS configIOS;
	criAtomEx_SetDefaultConfig_IOS( &configIOS );
	configIOS.atom_ex.fs_config				= &fsConfig;
	configIOS.hca_mx.output_sampling_rate	= 32000;
	criAtomEx_Initialize_IOS( &configIOS, NULL, 0 );
	
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	
	// Android用の初期化
	CriAtomExConfig_ANDROID configAndroid;
	criAtomEx_SetDefaultConfig_ANDROID( &configAndroid );
	configAndroid.atom_ex.fs_config				= &fsConfig;
	configAndroid.hca_mx.output_sampling_rate	= 32000;
	criAtomEx_Initialize_ANDROID( &configAndroid, NULL, 0 );
	
#endif
	
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
	
	// ActivityのContextを取得します
	JniMethodInfo methodInfo;
	JniHelper::getStaticMethodInfo(	methodInfo, "org/cocos2dx/lib/Cocos2dxActivity", "getContext", "()Landroid/content/Context;" );
	
	// assetsフォルダへのアクセスを可能にします
	auto androidContextObject = ( jobject )methodInfo.env->CallStaticObjectMethod( methodInfo.classID, methodInfo.methodID );
	criFs_EnableAssetsAccess_ANDROID( JniHelper::getJavaVM(), androidContextObject );
	
#endif
}