#ifndef _FREESTATE_H_
#define _FREESTATE_H_

#include "ISeaFireFlyState.h"

class FreeState : public ISeaFireFlyState
{
public:
	FreeState();
	~FreeState();

	void update(SeaFireFly* seaFireFly, SeaFireFly* targetObject, Vec2 targetVel, Vec2 centerPos);

	State getState();

private:

};



#endif