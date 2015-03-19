
#ifndef _SEMANAGER_H_
#define _SEMANAGER_H_


#include <map>
#include "SETag.h"
#include "BaseSE.h"

class SEManager {

public:
	//型定義
	typedef std::map<SETag,BaseSE*> SEArray;

public:
	//コンストラクタ
	SEManager();
	//デストラクタ
	~SEManager();
	
	//SE取得
	BaseSE* getSE(SETag tag);

private:
	//初期化
	void init();
	
	//SE格納変数
	SEArray mSEArray;
};

#endif