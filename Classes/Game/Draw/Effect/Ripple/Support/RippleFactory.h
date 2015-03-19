#ifndef _RIPPLE_FACTORY_H_
#define _RIPPLE_FACTORY_H_

#include "cocos2d.h"
#include "../Base/Ripple.h"
#include "RippleTag.h"
#include "RippleParameter.h"

USING_NS_CC;

/**
	@class	：	RippleFactory
	@brief	：	波紋生成クラス
	@author	：	利川聖太
 */
class RippleFactory : public Node
{
	
public:
	
	/**
		@brief	コンストラクタ
	 */
	RippleFactory();
	
	/**
		@brief	デストラクタ
	 */
	~RippleFactory();
	
	/**
		@brief	インスタンスの生成
	 */
	CREATE_FUNC( RippleFactory );
	
	/**
		@brief	波紋クラスのインスタンスの生成
	 
		@param	tag	生成したい波紋クラスのタグ
		@return		波紋クラスのインスタンス
	 */
	Ripple* createRipple( RippleTag tag );
	
private:
	
	/**
		@brief	コピーコンストラクタ, 代入演算子の禁止
	 */
	RippleFactory( const RippleFactory& ) = delete;
	RippleFactory& operator = ( const RippleFactory& ) = delete;
	
	/**
		@brief	コンテナの初期化
	 */
	void initContainer();
	
	/**
		@brief	要素の挿入
	 
		@param	tag			登録するタグ
		@param	fileName	ファイルの名前
		@param	scaleValue	拡大値に加算する値
	 */
	void insert( RippleTag tag, const std::string& fileName, float scaleValue );
	
private:
	
	// 型定義
	typedef std::map< RippleTag, RippleParameter* >	ParamContainer;
	
	// メンバ変数の宣言
	ParamContainer	mParamContainer;	// パラメータ構造体のコンテナ
};

#endif