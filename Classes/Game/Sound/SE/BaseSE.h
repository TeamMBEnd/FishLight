#ifndef _BASESE_H_
#define _BASESE_H_

#include "cocos2d.h"
#include <string>

class BaseSE {
public:
	//コンストラクタ
	BaseSE(const std::string& filePath);
	//デストラクタ
	~BaseSE();
	
	//音量調整
	void setVolume(float volume);
	//SE読み込み
	void preload();
	//再生
	void play(bool loop = false, float pitch = 1.0f,float pan = 0.0f, float gain = 1.0f);
	//停止
	void stop(unsigned int nId);
	//全て停止
	void stopAll();
	//再度再生
	void resume(unsigned int nId);
	//一時停止
	void pause(unsigned int nId);
	//全て一時停止
	void pauseAll();
	//解放
	void unload();
	//クリエイト
	static BaseSE* create(const std::string& filePath);
	
private:
	//メンバー用変数
	std::string mFilePath;

};

#endif