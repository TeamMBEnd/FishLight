#include "BlendLight.h"

BlendLight::BlendLight() :mIsDraw(false){
	BlendLight::init();
	mLightState.AnimationTime = 0;
	mLightState.pos = nullptr;
	setTexture("stage/Light.png");
	setVisible(mIsDraw);

}

BlendLight::~BlendLight(){
	mLightState.pos = nullptr;
}

void BlendLight::setScale(float scale) {
	mLightState.scale = scale;
	Sprite::setScale(mLightState.scale);
}

void BlendLight::addScale(float value){
	mLightState.scale += value;
}

void BlendLight::setDraw(LIGHTSTATE lightState){
	mLightState.pos = lightState.pos;
	mLightState.scale = lightState.scale;
	setScale(mLightState.scale);

	mLightState.AnimationTime = lightState.AnimationTime;
	mIsLoop = lightState.isLoop;
	mIsDraw = true;
	mIsTime = 0;
	setVisible(mIsDraw);
}

void BlendLight::draw(BlendFunc func,float deltatime,Vec2 pos){

	if (!mIsDraw) return;
	if (mLightState.isDraw != nullptr){
		mIsDraw = mLightState.isDraw;
		if (!mIsDraw) return;
	}
	if (!animation(deltatime))return;

	/*Vec2 test = *mLightState.pos + pos;*/
	setPosition(*mLightState.pos);
	setBlendFunc(func);

}

bool BlendLight::animation(float deltaTime){
	if (mIsLoop) return true;

	float value = 0.008f;
	addScale(value);
	setScale(mLightState.scale);

	mIsTime += deltaTime;

	if (mIsTime > mLightState.AnimationTime){
		mIsDraw = false;
		setVisible(mIsDraw);
		return false;
	}

	return true;

}
void BlendLight::onEnter(){

}

void BlendLight::initState(){
	mIsDraw = false;
	setVisible(mIsDraw);
}