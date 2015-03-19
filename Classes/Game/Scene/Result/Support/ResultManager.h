#ifndef _RESULT_MANAGER_H_
#define _RESULT_MANAGER_H_

#include "cocos2d.h"
#include "../Animation/ResultScoreAnimation.h"
#include "../Animation/ResultStarAnimation.h"
#include "ResultData.h"

USING_NS_CC;

namespace
{
	/**
		@brief	関数のタグ
	 */
	enum FuncTag
	{
		TAG_SKIP_SPRITE = 0,
		TAG_SKIP_STAR,
		TAG_SCENE_CHANGE,
		TAG_LENGTH,
	};
}

/**
	@class	：	ResultManager
	@brief	：	リザルト管理者クラス
	@author	：	利川聖太
 */
class ResultManager : public Node
{
	
public:
	
	/**
		@brief	コンストラクタ
	 
		@param	data	リザルトで使用する海ほたる情報
	 */
	ResultManager( const ResultData& data );
	
	/**
		@brief	デストラクタ
	 */
	~ResultManager();
	
	/**
		@brief	インスタンスの生成
	 
		@param	data	リザルトで使用する海ほたる情報
		@return			インスタンス
	 */
	static ResultManager* create( const ResultData& data );
	
	/**
		@brief	初期化
	 
		@return	初期化が完了したか否か
	 */
	virtual bool init() override;
	
	/**
		@brief	タッチ時のアクション
	 */
	void touchAction();
	
private:
	
	/**
		関数ラッパーの初期化
	 */
	void initFunc();
	
private:
	
	// メンバ変数の宣言
	std::function< void() >	mTouchFuncs[ FuncTag::TAG_LENGTH ];	// タッチ時のアクションを格納する関数ラッパー
	ResultScoreAnimation*	mScoreAnimation;					// スコア描画アニメーション
	ResultStarAnimation*	mStarAnimation;						// 星アニメーション
	FuncTag					mCurrentFuncTag;					// 現在の関数ラッパータグ
	ResultData				mResultData;						// リザルトで使用する海ほたる情報
};

#endif