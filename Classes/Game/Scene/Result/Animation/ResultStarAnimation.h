#ifndef _RESULT_STAR_ANIMATION_H_
#define _RESULT_STAR_ANIMATION_H_

#include "cocos2d.h"
#include "IResultAnimation.h"

USING_NS_CC;

namespace
{
	/**
		@brief	アクションのタグ
	 */
	enum ActionTag
	{
		TAG_SEQ_ACTION = 0,
	};
}

/**
	@class	：	ResultStarAnimation
	@brief	：	星アニメーションクラス
	@author	：	利川聖太
 */
class ResultStarAnimation : public Sprite, public IResultAnimation
{
	
public:
	
	/**
		@brief	コンストラクタ
	 */
	ResultStarAnimation() = default;
	
	/**
		@brief	デストラクタ
	 */
	~ResultStarAnimation() = default;
	
	/**
		@brief	クリエイト関数マクロ
	 */
	CREATE_FUNC( ResultStarAnimation );
	
	/**
		@brief	初期化
	 
		@return	初期化が完了したか否か
	 */
	virtual bool init() override;
	
	/**
		@brief	アニメーションの再生
	 */
	virtual void playAnimation() override;
	
	/**
		@brief	アニメーションのスキップ
	 */
	virtual void skipAnimation() override;
};

#endif