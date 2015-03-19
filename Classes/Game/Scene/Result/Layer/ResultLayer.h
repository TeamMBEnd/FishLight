#ifndef _RESULT_LAYER_H_
#define _RESULT_LAYER_H_

#include "cocos2d.h"
#include "../Support/ResultManager.h"
#include "../Support/ResultData.h"

#include "Game/Draw/Effect/Ripple/Support/RippleManager.h"

USING_NS_CC;

/**
	@class	：	ResultLayer
	@brief	：	リザルトレイヤクラス
	@author	：	利川聖太
 */
class ResultLayer : public LayerColor
{
	
public:
	
	/**
		@brief	コンストラクタ
	 
		@param	data	リザルトで使用する海ほたる情報
	 */
	ResultLayer( const ResultData& data, const Vec2& layerPos );
	
	/**
		@brief	デストラクタ
	 */
	~ResultLayer();
	
	/**
		@brief	インスタンスの生成
	 
		@param	data	リザルトで使用する海ほたる情報
		@return			インスタンス
	 */
	static ResultLayer* create( const ResultData& data, const Vec2& layerPos );
	
	static Scene* createScene();
	
	/**
		@brief	初期化
	 
		@return	初期化が完了したか否か
	 */
	virtual bool init() override;
	
private:
	
	// メンバ変数の宣言
	ResultManager*	mResultManager;	// リザルト管理者
	
	RippleManager*	mRipple;
};

#endif