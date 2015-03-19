#ifndef _RIPPLE_H_
#define _RIPPLE_H_

#include "cocos2d.h"
#include "RippleBody.h"
#include <string>

USING_NS_CC;

/**
	@class	：	Ripple
	@brief	：	波紋クラス
	@author	：	利川聖太
 */
class Ripple : public Node
{
	
public:
	
	/**
		@brief	コンストラクタ
	 */
	Ripple();
	
	/**
		@brief	デストラクタ
	 */
	~Ripple();
	
	/**
		@brief	インスタンスの生成
	 
		@param	fileName	ファイルの名前
		@param	scaleValue	拡大値に加算する値
		@return				インスタンス
	 */
	static Ripple* create( const std::string& fileName, float scaleValue );
	
	/**
		@brief	初期化
	 
		@param	fileName	ファイルの名前
		@param	scaleValue	拡大値に加算する値
	 */
	bool init( const std::string& fileName, float scaleValue );
	
	/**
		@brief	更新
	 
		@param	deltaTime	デルタ時間
	 */
	void update( float deltaTime );
	
	/**
		@brief	波紋パーティクルの再生
	 
		@param	parent		波紋パーティクルを追加する親ノード
		@param	createPos	波紋パーティクルを生成する座標
	 */
	void playRipple( Node* parent, const Vec2& createPos );
	
	/**
		@brief	波紋パーティクルが終了したか否か
	 
		@return	波紋パーティクルが終了したか否か
	 */
	bool isParticleEnd() const;
	
private:
	
	// メンバ変数の宣言
	ParticleSystemQuad*	mParticle;		// 波紋パーティクル
	RippleBody*			mRippleBody;	// 波紋用の物理構造
	bool				mIsParticleEnd;	// 波紋パーティクルが終了したか否か
};

#endif