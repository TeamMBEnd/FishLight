#include "ADX2Player.h"

// コンストラクタ
ADX2Player::ADX2Player()
	: mCueSheet( nullptr )
	, mPlayerHandle( nullptr )
	, mVoicePoolHandle( nullptr )
	, mHcaMxVoicePoolHandle( nullptr ) { }

// デストラクタ
ADX2Player::~ADX2Player()
{
	// キューシートを解放します
	mCueSheet->release();
	
	// プレーヤの停止
	stopPlayer();
	
	// ハンドルの解放
	criAtomExPlayer_Destroy( mPlayerHandle );
	criAtomExVoicePool_Free( mVoicePoolHandle );
	criAtomExVoicePool_Free( mHcaMxVoicePoolHandle );
}

// インスタンスの生成
ADX2Player* ADX2Player::create( const char* acb, const char* awb )
{
	auto inst = new ADX2Player();
	
	if ( inst && inst->init( acb, awb ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// 初期化
bool ADX2Player::init( const char* acb, const char* awb )
{
	// キューシートの生成
	mCueSheet = ADX2CueSheet::create( acb, awb );
	mCueSheet->retain();
	
	// プレーヤハンドルの生成 & 初期設定
	CriAtomExPlayerConfig playerConfig;
	criAtomExPlayer_SetDefaultConfig( &playerConfig );
	mPlayerHandle = criAtomExPlayer_Create( &playerConfig, NULL, 0 );
	
	// ボイスプールハンドル( ADX/HCAコーデック用 )の生成 & 初期設定
	CriAtomExStandardVoicePoolConfig voicePoolConfig;
	criAtomExVoicePool_SetDefaultConfigForStandardVoicePool( &voicePoolConfig );
	voicePoolConfig.player_config.streaming_flag	= CRI_TRUE;
	voicePoolConfig.player_config.max_sampling_rate	= 48000 * 2;
	mVoicePoolHandle = criAtomExVoicePool_AllocateStandardVoicePool( &voicePoolConfig, NULL, 0 );
	
	// ボイスプールハンドル(  HCA-MXコーデック用 )の生成 & 初期設定
	CriAtomExHcaMxVoicePoolConfig hcaMxVoicePoolConfig;
	criAtomExVoicePool_SetDefaultConfigForHcaMxVoicePool( &hcaMxVoicePoolConfig );
	hcaMxVoicePoolConfig.player_config.streaming_flag		= CRI_TRUE;
	hcaMxVoicePoolConfig.player_config.max_sampling_rate	= 48000 * 2;
	mHcaMxVoicePoolHandle = criAtomExVoicePool_AllocateHcaMxVoicePool( &hcaMxVoicePoolConfig, NULL, 0 );
	
	return true;
}

// 音の再生
CriAtomExPlaybackId ADX2Player::play( CriAtomExCueId cueID )
{
	// 音声データのセット
	criAtomExPlayer_SetCueId( mPlayerHandle, mCueSheet->getAcbHandle(), cueID );
	
	// 再生を開始し、プレイバックIDを取得します
	auto playbackID = criAtomExPlayer_Start( mPlayerHandle );
	
	// プレイバックIDを返却します
	return playbackID;
}

// 音の停止
void ADX2Player::stop( CriAtomExPlaybackId playbackID )
{
	criAtomExPlayback_Stop( playbackID );
}

// プレーヤの停止
void ADX2Player::stopPlayer()
{
	criAtomExPlayer_Stop( mPlayerHandle );
}

// キューの数の取得
CriSint32 ADX2Player::getNumCues() const
{
	return criAtomExAcb_GetNumCues( mCueSheet->getAcbHandle() );
}

// 再生開始後の経過時間の取得
CriSint64 ADX2Player::getTime( CriAtomExPlaybackId playbackID ) const
{
	return criAtomExPlayback_GetTime( playbackID );
}

// キューの名前の取得
std::string ADX2Player::getCueName( CriAtomExCueId cueID )
{
	return criAtomExAcb_GetCueNameById( mCueSheet->getAcbHandle(), cueID );
}