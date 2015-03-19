#include "ADX2Sound.h"

// デストラクタ
ADX2Sound::~ADX2Sound()
{
	// イテレータの先頭と末尾を取得します
	auto itor	= mPlayerContainer.begin();
	auto end	= mPlayerContainer.end();
	
	while ( itor != end )
	{
		// インスタンスを解放します
		CC_SAFE_RELEASE( itor->second );
		itor++;
	}
	
	// マップの解放
	mPlayerContainer.clear();
}

// インスタンスの生成
ADX2Sound* ADX2Sound::getInstance()
{
	static ADX2Sound instance;
	return &instance;
}

// プレーヤの生成
void ADX2Sound::createPlayer( const std::string& acb, const std::string& awb, ADX2PlayerTag tag )
{
	// プレーヤの生成
	auto player = ADX2Player::create( acb.c_str(), awb.c_str() );
	player->retain();
	
	// マップに格納します
	mPlayerContainer[ tag ] = player;
}

// プレーヤの破棄
void ADX2Sound::deletePlayer( ADX2PlayerTag tag )
{
	// プレーヤを解放します
	mPlayerContainer[ tag ]->release();
	
	// マップから破棄します
	mPlayerContainer.erase( tag );
}

// 更新
void ADX2Sound::update( float deltaTime )
{
	// サーバ処理の実行
	criAtomEx_ExecuteMain();
}

// プレーヤの取得
ADX2Player* ADX2Sound::getPlayer( ADX2PlayerTag tag )
{
	// 検索用イテレータの準備
	auto findItor = mPlayerContainer.find( tag );
	
	if ( findItor != mPlayerContainer.end() )
	{
		// 存在する場合はインスタンスを返却します
		return mPlayerContainer[ tag ];
	}
	
	// 存在しない場合はnullptrを返却します
	return nullptr;
}

// コンストラクタ
ADX2Sound::ADX2Sound()
{
	// マップの解放
	mPlayerContainer.clear();
}