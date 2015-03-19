#ifndef DARKNESSMASK_H
#define DARKNESSMASK_H

#include "cocos2d.h"

USING_NS_CC;

namespace DarknessMask{

	LayerColor* create(Color4B color,Size size);

	void destroy(Layer* layer);
};
#endif