#ifndef _RESULT_SCORE_ANIMATION_H_
#define _RESULT_SCORE_ANIMATION_H_

#include "cocos2d.h"
#include "IResultAnimation.h"

USING_NS_CC;

namespace
{
	/**
		@brief	スプライトのタグ
	 */
	enum SpriteTag
	{
		TAG_CLEAR = 0,
		TAG_FIND,
		TAG_ANIMALS_TOP,
		TAG_OVERLOOKED,
		TAG_ANIMALS_MIDDLE,
		TAG_LOST,
		TAG_ANIMALS_DOWN,
		TAG_NUMBER_TOP,
		TAG_NUMBER_MIDDLE,
		TAG_NUMBER_DOWN,
	};
}

/**
	@class	：	ResultScoreAnimation
	@brief	：	スコア描画アニメーションクラス
	@author	：	利川聖太
 */
class ResultScoreAnimation : public Node, public IResultAnimation
{
	
public:
	
	/**
		@brief	コンストラクタ
	 
		@param	data	リザルトで使用する海ほたる情報
	 */
	ResultScoreAnimation( const ResultData& data );
	
	/**
		@brief	デストラクタ
	 */
	~ResultScoreAnimation() = default;
	
	/**
		@brief	インスタンスの生成
	 
		@param	data	リザルトで使用する海ほたる情報
		@return			インスタンス
	 */
	static ResultScoreAnimation* create( const ResultData& data );
	
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
	
private:
	
	/**
		@brief	テキストスプライトの設置
	 
		@param	fileName	ファイルの名前
		@param	drawPos		描画座標
		@param	delay		表示されるまでの遅延時間
		@param	tag			スプライトのタグ
	 */
	void putTextSprite( const std::string& fileName, const Point& drawPos, float delay, SpriteTag tag );
	
	/**
		@brief	ナンバースプライトの設置
	 
		@param	drawPos		描画座標
		@param	delay		表示されるまでの遅延時間
		@param	tag			スプライトのタグ
	 */
	void putNumberSprite( const Point& drawPos, u_int number, float delay, SpriteTag tag );
};

#endif