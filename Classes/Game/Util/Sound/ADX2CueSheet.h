#ifndef _ADX2_CUESHEET_H_
#define _ADX2_CUESHEET_H_

#include "cocos2d.h"
#include "cri_adx2le.h"

/**
	@class	：	ADX2CueSheet
	@brief	：	キューシートクラス
				ACBファイル( キュー情報、再生パラメータ、メモリ再生用波形データをキューシート単位でパッキング )と
				AWBファイル( ストリーム再生用波形データをキューシート単位でパッキング )を読み込み、管理するクラスです。
 */
class ADX2CueSheet : public cocos2d::Ref
{
	
public:
	
	/**
		@brief	コンストラクタ
	 */
	ADX2CueSheet();
	
	/**
		@brief	デストラクタ
	 */
	~ADX2CueSheet();
	
	/**
		@brief	インスタンスの生成
	 
		@param	acb	ACBファイルの名前
		@param	awb	AWBファイルの名前
		@return		インスタンス
	 */
	static ADX2CueSheet* create( const char* acb, const char* awb );
	
	/**
		@brief	キューシート情報を管理するハンドルの取得
	 
		@return	ACBハンドル
	 */
	CriAtomExAcbHn getAcbHandle();
	
private:
	
	/**
		@brief	ACBファイルの読み込み
	 
		@param	acb	ACBファイルの名前
		@param	awb	AWBファイルの名前
		@return		読み込みに成功したか否か
	 */
	bool loadAcb( const char* acb, const char* awb );
	
private:
	
	// メンバ変数の宣言
	CriAtomExAcbHn	mAcbHandle;	// キューシート情報を管理するハンドル
};

#endif