#ifndef _RIPPLE_MANAGER_H_
#define _RIPPLE_MANAGER_H_

#include "cocos2d.h"
#include "../Base/Ripple.h"
#include "RippleTag.h"
#include <list>

USING_NS_CC;

/**
	@class	：	RippleManager
	@brief	：	波紋管理者クラス
	@author	：	利川聖太
 */
class RippleManager : public Node
{
	
public:
	
	/**
		@brief	コンストラクタ
	 */
	RippleManager();
	
	/**
		@brief	デストラクタ
	 */
	~RippleManager();
	
	/**
		@brief	インスタンスの生成
	 */
	CREATE_FUNC( RippleManager );
	
	/**
		@brief	更新
	 
		@param	deltaTime	デルタ時間
	 */
	void update( float deltaTime );
	
	/**
		@brief	波紋パーティクルの再生
	 
		@param	parent		波紋パーティクルを追加する親ノード
		@param	tag			再生したい波紋パーティクルのタグ
		@param	createPos	波紋パーティクルを生成する座標
	 */
	void playRipple( Node* parent, RippleTag tag, const Vec2& createPos );
	
	/**
		@brief	再生中の波紋があるか否か
	 
		@return	再生中の波紋があるか否か
	 */
	bool isEmpty() const;
	
private:
	
	/**
		@brief	コピーコンストラクタ, 代入演算子の禁止
	 */
	RippleManager( const RippleManager& ) = delete;
	RippleManager& operator = ( const RippleManager& ) = delete;
	
private:
	
	// 型定義
	typedef std::list< Ripple* >	RippleList;
	
	// メンバ変数の宣言
	RippleList	mRippleList;	// 波紋クラスのリスト
};

#endif