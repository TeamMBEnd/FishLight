#include "BaseBGM.h"

using namespace CocosDenshion;
USING_NS_CC;

/*----------------------------------------------------------------------------------
コンストラクタ
 ----------------------------------------------------------------------------------*/
BaseBGM::BaseBGM(const std::string& filePath):
mFilePath(filePath)
{
}

/*----------------------------------------------------------------------------------
 デストラクタ
 ----------------------------------------------------------------------------------*/
BaseBGM::~BaseBGM(){	
	
}


/*----------------------------------------------------------------------------------
 音量調整
 ----------------------------------------------------------------------------------*/
void BaseBGM::setVolume(float volume){
	SimpleAudioEngine::getInstance() -> setBackgroundMusicVolume(volume);
}


/*----------------------------------------------------------------------------------
 ロード
 ----------------------------------------------------------------------------------*/
void BaseBGM::preload(){
	SimpleAudioEngine::getInstance() -> preloadBackgroundMusic(mFilePath.c_str());
}


/*----------------------------------------------------------------------------------
 再生
 ----------------------------------------------------------------------------------*/
void BaseBGM::play(){
	SimpleAudioEngine::getInstance() -> playBackgroundMusic(mFilePath.c_str(),true);
}


/*----------------------------------------------------------------------------------
 停止
 ----------------------------------------------------------------------------------*/
void BaseBGM::stop(){
	SimpleAudioEngine::getInstance() -> stopBackgroundMusic(mFilePath.c_str());
}


/*----------------------------------------------------------------------------------
 巻き戻し
 ----------------------------------------------------------------------------------*/
void BaseBGM::rewind(){
	SimpleAudioEngine::getInstance() -> rewindBackgroundMusic();
}


/*----------------------------------------------------------------------------------
 再度再生
 ----------------------------------------------------------------------------------*/
void BaseBGM::resume(){
	SimpleAudioEngine::getInstance() ->resumeBackgroundMusic();
}


/*----------------------------------------------------------------------------------
 一時停止
 ----------------------------------------------------------------------------------*/
void BaseBGM::pause(){
	SimpleAudioEngine::getInstance() ->pauseBackgroundMusic();
}


/*----------------------------------------------------------------------------------
クリエイト
 ----------------------------------------------------------------------------------*/
BaseBGM* BaseBGM::create(const std::string& filePath){
	
	auto inst = new BaseBGM( filePath );
	return inst;
}


