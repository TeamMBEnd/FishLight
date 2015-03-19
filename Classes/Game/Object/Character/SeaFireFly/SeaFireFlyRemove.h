#ifndef _SEAFIREFLYREMOVE_H_
#define _SEAFIREFLYREMOVE_H_

#include "SeaFireFly.h"

class SeaFireFlyRemove
{
public:
	bool operator()(SeaFireFly* fly)
	{
		if (fly->isDead()){
			if (fly->getReferenceCount() != 0)
			{
				// 参照カウンタを減らす
				CC_SAFE_RELEASE(fly);
				return true;
			}
		}
		return false;
	}
};

#endif