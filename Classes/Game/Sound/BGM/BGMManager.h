#ifndef _BGMMANAGER_H_
#define _BGMMANAGER_H_

#include <vector>
#include <map>
#include "BaseBGM.h"
#include "BGMTag.h"

class BGMManager {
	
public:
	//型定義
	typedef std::map<BGMTag , BaseBGM*> BGMArray;
	
public:
	//コンストラクタ
	BGMManager();
	//デストラクタ
	~BGMManager();
	
	//SE取得
	BaseBGM* getBGM(BGMTag tag);
	
	
private:
	//初期化
	void init();
	
	//BGM格納変数
	BGMArray mBGMArray;
};

#endif
