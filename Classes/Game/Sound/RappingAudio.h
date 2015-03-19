#ifndef _RAPPINGAUDIO_H_
#define _RAPPINGAUDIO_H_

#include "cocos2d.h"

#include "SE/SETag.h"
#include "SE/BaseSE.h"
#include "SE/SEManager.h"

#include "BGM/BGMTag.h"
#include "BGM/BaseBGM.h"
#include "BGM/BGMManager.h"


class RappingAudio {
public:
	
	//インスタンス取得
	static RappingAudio* getInstance();
	
	//BGM取得
	BaseBGM* getBGM(BGMTag tag);
	//SE取得
	BaseSE* getSE(SETag tag);
	
	//デストラクタ
	~RappingAudio();
	
private:
	
	//シングルトン
	RappingAudio();
	RappingAudio(const RappingAudio&);
	RappingAudio& operator=(const RappingAudio&);
	
	SEManager* seManager;
	BGMManager* bgmManager;
	
};

inline RappingAudio* RappingAudio::getInstance(){
	static RappingAudio instance;
	return &instance;
}

#endif