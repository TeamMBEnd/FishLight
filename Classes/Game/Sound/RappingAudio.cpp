#include "Game/Sound/RappingAudio.h"

/*----------------------------------------------------------------------------------
 コンストラクタ
 ----------------------------------------------------------------------------------*/
RappingAudio::RappingAudio(){
	seManager = new SEManager();
	bgmManager = new BGMManager();
}

/*----------------------------------------------------------------------------------
 デストラクタ
 ----------------------------------------------------------------------------------*/
RappingAudio::~RappingAudio(){
	delete seManager;
	delete bgmManager;
}

/*----------------------------------------------------------------------------------
 BGM取得
 ----------------------------------------------------------------------------------*/
BaseBGM* RappingAudio::getBGM(BGMTag tag){
	return bgmManager->getBGM(tag);
}

/*----------------------------------------------------------------------------------
 SE取得
 ----------------------------------------------------------------------------------*/
BaseSE* RappingAudio::getSE(SETag tag){
	return seManager->getSE(tag);
}