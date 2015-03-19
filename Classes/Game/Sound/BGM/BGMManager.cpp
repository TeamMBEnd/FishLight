#include "BGMManager.h"
#include "BGMTag.h"
#include "Game/Util/Release/DeleteContainer.h"


/*----------------------------------------------------------------------------------
 コンストラクタ
 ----------------------------------------------------------------------------------*/
BGMManager::BGMManager(){
	//初期化
	init();
}


/*----------------------------------------------------------------------------------
デストラクタ
 ----------------------------------------------------------------------------------*/
BGMManager::~BGMManager(){
	//解放
	DeleteContainer::cleanMap(mBGMArray);
	
	//Debug用log
	CCLOG( "BaseBGM : %s", __FUNCTION__ );
}

/*----------------------------------------------------------------------------------
初期化
 ----------------------------------------------------------------------------------*/
void BGMManager::init(){
	
	//filePath格納用変数
	const std::string filePath[] =
	{
		"sound/stage1.wav",
		"sound/Title.wav",
		
		//"sound/Ending.wav",
	};
	
	//BGM生成
	for(int i = 0; i < BGMTag::end; ++i)
	{
		mBGMArray.insert( std::make_pair( ( BGMTag )i, BaseBGM::create( filePath[ i ] ) ));
	}
}

/*----------------------------------------------------------------------------------
 BGM取得
 ----------------------------------------------------------------------------------*/
BaseBGM* BGMManager::getBGM(BGMTag tag){
	//findItorの取得
	auto findItor = mBGMArray.find(tag);
	
	//検索
	if ( findItor != mBGMArray.end() )
	{
		// 検索に掛かった場合実行
		return mBGMArray[tag];
	}
	
	//なかった場合ぬるぽ
	return nullptr;
	//Debug用log
	CCLOG("BGMManager::getBGM: file not found");
}