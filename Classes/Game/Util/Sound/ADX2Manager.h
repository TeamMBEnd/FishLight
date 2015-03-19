#ifndef _ADX2_MANAGER_H_
#define _ADX2_MANAGER_H_

#include "cocos2d.h"
#include "cri_adx2le.h"
#include <string>

// OS別のインクルード
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
#include <AudioToolbox/AudioSession.h>
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
#include "platform/android/jni/JniHelper.h"
#endif

/**
	@class	：	ADX2Manager
	@brief	：	ADX2管理者クラス
				初期化やアプリの再開時、中断時の処理を行うクラスです。
 */
class ADX2Manager : public cocos2d::Ref
{
	
public:
	
	/**
		@brief	コンストラクタ
	 */
	ADX2Manager();
	
	/**
		@brief	デストラクタ
	 */
	~ADX2Manager();
	
	/**
		@brief	インスタンスの生成
	 
		@return	インスタンス
	 */
	static ADX2Manager* create();
	
	/**
		@brief	初期化
	 
		@param	acf	ACFファイルの名前
	 */
	void init( const std::string& acf );
	
	/**
		@brief	アプリ中断時のコールバック関数
	 */
	void pauseApp();
	
	/**
		@brief	アプリ再開時のコールバック関数
	 */
	void resumeApp();
	
private:
	
	/**
		@brief	プラットフォーム別の初期化
	 */
	void initPlatformSetting();
	
private:
	
	// メンバ変数の宣言
	CriAtomDbasId	mDbasID;	// D-BAS管理用のID
};

#endif