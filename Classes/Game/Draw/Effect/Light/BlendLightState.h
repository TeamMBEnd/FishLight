#ifndef BLENDLIGHTSTATE_H
#define BLENDLIGHTSTATE_H

/*---------------------------------------------------
	BlendLightState.h
	���C�g��`�悵�����Ƃ��ɓo�^����\����
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