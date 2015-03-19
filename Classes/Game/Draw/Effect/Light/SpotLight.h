#ifndef SPOTLIGHT_H
#define SPOTLIGHT_H

#include "cocos2d.h"

USING_NS_CC;

namespace SpotLight{
	void lightAnimation(const Vec2* pos, float AnimationTime, float MaxRadius, bool isfade);
	void lightDraw(const Vec2* pos, float radius);
	
};

#endif