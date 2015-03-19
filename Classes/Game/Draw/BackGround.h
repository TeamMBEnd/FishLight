/*----------------------------------
 Created by settyan on 2014/12/15.
 背景生成クラス
 ----------------------------------*/

#ifndef __FishLight__BackGround__
#define __FishLight__BackGround__

#include "cocos2d.h"

class BackGround{
	
	
private:
    
   // cocos2d::Point clampValue;  //くらんぷの値
    
public:
    BackGround();
    void Initialize(cocos2d::Layer* layer);
	
	/*--------------------------------
	 背景生成(＊レイヤー情報)
	 --------------------------------*/
	void create(cocos2d::Layer* layer);
	
	/*   void Update(cocos2d::Layer* layer);*/
};

#endif /* defined(__FishLight__BackGround__) */
