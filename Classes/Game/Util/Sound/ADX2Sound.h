#ifndef _ADX2_SOUND_H_
#define _ADX2_SOUND_H_

#include "cocos2d.h"
#include "cri_adx2le.h"
#include "ADX2Player.h"
#include "ADX2PlayerTag.h"
#include <string>
#include <map>

/**
	@class	：	ADX2Sound
	@brief	：	サウンドクラス
				各プレーヤを管理するクラスです。ユーザは基本的にこのクラスを使用します。
 */
class ADX2Sound
{
	
public:
	
	/**
		@brief	デストラクタ
	 */
	~ADX2Sound();
	
	/**
		@brief	インスタンスの取得
	 
		@param	インスタンス
	 */
	static ADX2Sound* getInstance();
	
	/**
		@brief	プレーヤの生成
	 
		@param	acb	ACBファイルの名前
		@param	awb	AWBファイルの名前
		@param	tag	プレーヤ管理用のタグ
	 */
	void createPlayer( const std::string& acb, const std::string& awb, ADX2PlayerTag tag );
	
	/**
		@brief	プレーヤの破棄
	 
		@param	tag	プレーヤ管理用のタグ
	 */
	void deletePlayer( ADX2PlayerTag tag );
	
	/**
		@brief	更新
	 
		@param	deltaTime	デルタ時間
	 */
	void update( float deltaTime );
	
	/**
		@brief	プレーヤの取得
	 
		@param	tag	取得したいプレーヤのタグ
		@return		プレーヤのインスタンス
					プレーヤが生成されていない場合はnullptrが返却されます。
	 */
	ADX2Player* getPlayer( ADX2PlayerTag tag );
	
private:
	
	/**
		@brief	コンストラクタ, コピーコンストラクタ, 代入演算子の禁止
	 */
	ADX2Sound();
	ADX2Sound( const ADX2Sound& ) = delete;
	ADX2Sound& operator = ( const ADX2Sound& ) = delete;
	
public:
	
	// 型定義
	typedef std::map< ADX2PlayerTag, ADX2Player* >	PlayerContainer;
	
	// メンバ変数の宣言
	PlayerContainer	mPlayerContainer;	// プレーヤを管理するコンテナ
};

#endif