#ifndef _ESCAPESTATE_H_
#define _ESCAPESTATE_H_

#include "ISeaFireFlyState.h"
#include "SeaFireFlyMove.h"

class EscapeState : public ISeaFireFlyState
{
public:
	EscapeState();
	~EscapeState();

	void update(SeaFireFly* seaFireFly, SeaFireFly* targetObject, Vec2 targetVel, Vec2 centerPos);

	State getState();

private:
	float alpha;
};
#endif