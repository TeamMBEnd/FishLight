#ifndef _OBJREMOVE_H_
#define _OBJREMOVE_H_

#include "StageObj.h"

class ObjRemove
{
public:
	bool operator()(StageObj* obj)
	{
		if (obj->isDead()){

			if (obj->getReferenceCount() != 0)
			{
				// 参照カウンタを減らす
				CC_SAFE_RELEASE(obj);
				return true;
			}
		}
		return false;
	}
};

#endif