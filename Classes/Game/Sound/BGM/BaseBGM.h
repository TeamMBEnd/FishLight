#ifndef _BASEBGM_H_
#define _BASEBGM_H_

#include "cocos2d.h"
#include <string>

class BaseBGM {

public:
	//コンストラクタ
	BaseBGM(const std::string& filePath);
	//デストラクタ
	~BaseBGM();
	
	//音量調整
	void setVolume(float volume);
	//BGMロード
	void preload();
	//再生
	void play();
	//停止
	void stop();
	//巻き戻し
	void rewind();
	//再度再生
	void resume();
	//一時停止
	void pause();
	
	//クリエイト
	static BaseBGM* create(const std::string& filePath);
	
private:
	//メンバー用変数
	std::string mFilePath;
};

#endif