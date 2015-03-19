#include "SEManager.h"
#include "Game/Util/Release/DeleteContainer.h"
#include "SETag.h"


/*----------------------------------------------------------------------------------
 コンストラクタ
 ----------------------------------------------------------------------------------*/
SEManager::SEManager(){
	//初期化
	init();
}

/*----------------------------------------------------------------------------------
 コンストラクタ
 ----------------------------------------------------------------------------------*/
SEManager::~SEManager(){
	
	//解放
	DeleteContainer::cleanMap(mSEArray);
	
	//Debug用log
	CCLOG( "BaseSE : %s", __FUNCTION__ );
}

/*----------------------------------------------------------------------------------
 コンストラクタ
 ----------------------------------------------------------------------------------*/
void SEManager::init(){
	
	//filePath格納用変数
	const std::string filePath[] =
	{
		"sound/Cansel.wav",
		"sound/Decide.wav",
		"sound/Ripple01.wav",
		"sound/Ripple02.wav",
		"sound/Ripple03.wav",
		"sound/Ripple04.wav",
		"sound/Ripple05.wav",
		"sound/Ripple06.wav",
		"sound/Ripple07.wav",
		"sound/Ripple08.wav",
		"sound/Dead.wav",
		"sound/EnemyDead.wav",
		
		
		
	};
	
	//SE生成
	for (int i = 0; i < SETag::last ; ++i) {
		mSEArray.insert( std::make_pair( ( SETag )i, BaseSE::create( filePath[ i ] ) ));
	}
	
}

/*----------------------------------------------------------------------------------
 SE取得
 ----------------------------------------------------------------------------------*/
BaseSE* SEManager::getSE(SETag tag){
	
	//finditrの取得
	auto findItor = mSEArray.find(tag);
	
	//検索
	if ( findItor != mSEArray.end() )
	{
		// 検索に掛かった場合実行
		return mSEArray[tag];
	}
	//なかった場合ぬるぽ
	return nullptr;
	//Debug用log
	CCLOG("BGMManager::getBGM: file not found");
}


