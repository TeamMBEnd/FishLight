#ifndef BLENDLIGHTSTATE_H
#define BLENDLIGHTSTATE_H

/*---------------------------------------------------
	BlendLightState.h
	ÉâÉCÉgÇï`âÊÇµÇΩÇ¢Ç∆Ç´Ç…ìoò^Ç∑ÇÈç\ë¢ëÃ
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