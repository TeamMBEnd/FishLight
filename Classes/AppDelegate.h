#ifndef _APP_DELEGATE_H_
#define _APP_DELEGATE_H_

#include "cocos2d.h"
#include "Game/Util/Sound/ADX2Manager.h"

/**
	@class	：	AppDelegate
	@brief	：	アプリケーション統括者クラス
test
 */
class AppDelegate : private cocos2d::Application
{
	
public:
	
	/**
		@brief	コンストラクタ
	 */
	AppDelegate();
	
	/**
		@brief	デストラクタ
	 */
	virtual ~AppDelegate();
	
	/**
		@brief	アプリケーションの起動準備が整った時に呼ばれるコールバック関数
	 
		@return	アプリケーションを開始するか否か
	 */
	bool applicationDidFinishLaunching() override;
	
	/**
		@brief	アプリケーションが非アクティブ状態になった時に呼ばれるコールバック関数
	 */
	void applicationDidEnterBackground() override;
	
	/**
		@brief	アプリケーションがアクティブ状態になった時に呼ばれるコールバック関数
	 */
	void applicationWillEnterForeground() override;
	
private:
	
	// メンバ変数の宣言
	ADX2Manager*	mADX2Manager;	// ADX2管理者
};

#endif