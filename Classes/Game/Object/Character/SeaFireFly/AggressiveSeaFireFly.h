#ifndef _AGGRESSIVESEAFIREFLY_H_
#define _AGGRESSIVESEAFIREFLY_H_

#include "SeaFireFly.h"

class AggressiveSeaFireFly:public SeaFireFly
{
public:
	AggressiveSeaFireFly();
	~AggressiveSeaFireFly();

	virtual bool init();

	void update(Vec2 targetPos, Vec2 targetVel, Vec2 centerPos,float st,int group) override;
	void onEnter() override;

	void createRipple() override;

	bool isDead()override;
	bool deadCheck();

	SEAFIREFLY getKind()const;

	CREATE_FUNC(AggressiveSeaFireFly);


private:
	int mRippleCounter;
	int alpha;
};

#endif