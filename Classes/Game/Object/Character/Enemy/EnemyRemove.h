#ifndef _ENEMYREMOVE_H_
#define _ENEMYREMOVE_H_

#include "Enemy.h"

class EnemyRemove
{
public:
	bool operator()(Enemy* obj)
	{
		if (obj->dead()){
			CCLOG("count : %i", obj->getReferenceCount());

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