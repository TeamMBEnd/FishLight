#ifndef BLENDLIGHT_H
#define BLENDLIGHT_H

#include "cocos2d.h"
#include <List>
USING_NS_CC;

#include "BlendLightState.h"

class BlendLight : public Sprite{
public:
	BlendLight();
	~BlendLight();

	void setScale(float scale) override;
	void addScale(float value);
	void setDraw(LIGHTSTATE lightState);
	bool isDraw(){ return mIsDraw; }
	void draw(BlendFunc func, float deltaTime, Vec2 pos);
	void onEnter() override;
	void initState();

private:
	bool animation(float deltaTime);
	
	bool mIsDraw;
	bool mIsLoop;
	LIGHTSTATE mLightState;
	float mIsTime;

};
#endif