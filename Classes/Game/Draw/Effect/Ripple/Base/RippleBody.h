#ifndef _RIPPLE_BODY_H_
#define _RIPPLE_BODY_H_

#include "cocos2d.h"

USING_NS_CC;

/**
	@class	：	RippleBody
	@brief	：	波紋クラス用の物理構造クラス
	@author	：	利川聖太
 */
class RippleBody : public Node
{
	
public:
	
	/**
		@brief	コンストラクタ
	 
		@param	scaleValue	拡大値に加算する値
	 */
	RippleBody( float scaleValue );
	
	/**
		@brief	デストラクタ
	 */
	~RippleBody() = default;
	
	/**
		@brief	インスタンスの生成
	 
		@param	拡大値に加算する値
		@return	インスタンス
	 */
	static RippleBody* create( float scaleValue );
	
	/**
		@brief	物理構造の生成
	 
		@param	particle	物理構造を追加する波紋パーティクル
		@param	deltaTime	デルタ時間
	 */
	void createBody( ParticleSystemQuad* particle, float deltaTime );
	
private:
	
	// メンバ変数の宣言
	PhysicsMaterial	mMaterial;		// 物質特徴
	float			mBodyScale;		// 物理構造の拡大値
	float			mScaleValue;	// 拡大値に加算する値
};

#endif