#ifndef _IRESULT_ANIMATION_H_
#define _IRESULT_ANIMATION_H_

#include "../Support/ResultData.h"

/**
	@class	：	IResultAnimation
	@brief	：	リザルトで行うアニメーションの基底クラス
	@author	：	利川聖太
 */
class IResultAnimation
{
	
public:

	/**
		@brief	デストラクタ
	 */
	virtual ~IResultAnimation() { }
	
	/**
		@brief	アニメーションの再生
	 */
	virtual void playAnimation() = 0;
	
	/**
		@brief	アニメーションのスキップ
	 */
	virtual void skipAnimation() = 0;
	
	/**
		@brief	アニメーションが終了したか否か
	 
		@return	アニメーションが終了したか否か
	 */
	bool isAnimation() const;
	
protected:
	
	/**
		@brief	コンストラクタ
	 */
	IResultAnimation()
		: mResultData( ResultData( false, 0, 0, 0 ) )
		, mIsAnimation( false )
	{ }
	
	// メンバ変数の宣言
	ResultData	mResultData;	// リザルトで使用する海ほたる情報
	bool		mIsAnimation;	// アニメーションが終了したか否か
};

// アニメーションが終了したか否か
inline bool IResultAnimation::isAnimation() const
{
	return mIsAnimation;
}

#endif