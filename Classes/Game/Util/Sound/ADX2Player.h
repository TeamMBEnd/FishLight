#ifndef _ADX2_PLAYER_H_
#define _ADX2_PLAYER_H_

#include "cocos2d.h"
#include "cri_adx2le.h"
#include "ADX2CueSheet.h"
#include <string>

/**
	@class	：	ADX2Player
	@brief	：	プレーヤクラス
				CriAtomExPlayerやCriAtomExVoicePoolを使用し、音を再生するクラスです。
 */
class ADX2Player : public cocos2d::Ref
{
	
public:
	
	/**
		@brief	コンストラクタ
	 */
	ADX2Player();
	
	/**
		@brief	デストラクタ
	 */
	~ADX2Player();
	
	/**
		@brief	インスタンスの生成
	 
		@param	acb	ACBファイルの名前
		@param	awb	AWBファイルの名前
		@return		インスタンス
	 */
	static ADX2Player* create( const char* acb, const char* awb );
	
	/**
		@brief	初期化
	 
		@param	acb	ACBファイルの名前
		@param	awb	AWBファイルの名前
		@return		初期化に成功したか否か
	 */
	bool init( const char* acb, const char* awb );
	
	/**
		@brief	音の再生
				再生している音に対して何かをする場合、
				戻り値であるプレイバックIDを保持する必要があります。
	 
		@param	cueID	キューID
		@return			プレイバックID
	 */
	CriAtomExPlaybackId play( CriAtomExCueId cueID );
	
	/**
		@brief	音の停止
	 
		@param	playbackID	プレイバックID
	 */
	void stop( CriAtomExPlaybackId playbackID );
	
	/**
		@brief	プレーヤの停止
	 */
	void stopPlayer();
	
	/**
		@brief	キューの数の取得
	 
		@return	キューシート内のキューの数
	 */
	CriSint32 getNumCues() const;
	
	/**
		@brief	再生開始後の経過時間の取得
	 
		@param	cueID	キューID
		@return			経過時間
	 */
	CriSint64 getTime( CriAtomExPlaybackId playbackID ) const;
	
	/**
		@brief	キューの名前の取得
	 
		@param	cueID	キューID
		@return			キューIDに紐づくキューの名前
	 */
	std::string getCueName( CriAtomExCueId cueID );
	
private:
	
	// メンバ変数の宣言
	ADX2CueSheet*			mCueSheet;				// キューシート
	CriAtomExPlayerHn		mPlayerHandle;			// 音声を再生するハンドル
	CriAtomExVoicePoolHn	mVoicePoolHandle;		// ボイスプールを制御するハンドル( ADX/HCAコーデック用 )
	CriAtomExVoicePoolHn	mHcaMxVoicePoolHandle;	// ボイスプールを制御するハンドル(  HCA-MXコーデック用 )
};

#endif