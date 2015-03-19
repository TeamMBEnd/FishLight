#ifndef STAGEOBJ_H
#define STAGEOBJ_H

#include "cocos2d.h"

USING_NS_CC;

class StageObj : public Sprite{

public:

	virtual ~StageObj(){}

	virtual void update(float deltatime) = 0;

	virtual void onContact(Node* node) = 0;

	virtual StageObj* clone() = 0;

	virtual void releaseObj(){
		_isDead = true;
		removeFromParent();
	}

	virtual bool isDead() = 0;
protected:
	bool _isDead;
};

#endif