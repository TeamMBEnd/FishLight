#ifndef BLENDLIGHTSTATE_H
#define BLENDLIGHTSTATE_H

/*---------------------------------------------------
	BlendLightState.h
	ライトを描画したいときに登録する構造体
---------------------------------------------------*/

#include "cocos2d.h"
USING_NS_CC;

struct LIGHTSTATE{
	float scale;
	const Vec2* pos;
	float AnimationTime;
	bool isLoop;
	bool* isDraw;
};

#endif