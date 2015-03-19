#ifndef _SEAFIREFLYREMOVEAll_H_
#define _SEAFIREFLYREMOVEAll_H_

#include "SeaFireFly.h"

class SeaFireFlyRemoveAll
{
public:
	bool operator()(SeaFireFly* fly)
	{
		if (fly->getReferenceCount() != 0)
		{
			// 参照カウンタを減らす
			CC_SAFE_RELEASE(fly);
			return true;
		}
		return false;
	}
};

#endif