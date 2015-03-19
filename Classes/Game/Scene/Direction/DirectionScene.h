#ifndef DIRECTIONSCENE_H
#define DIRECTIONSCENE_H

#include "cocos2d.h"
#include "Game/Scene/Sub/IScene.h"
USING_NS_CC;

class DirectionScene : public IScene {

public:

	static cocos2d::Scene* createScene();

	DirectionScene();
	~DirectionScene();

	virtual bool init();

	void update(float deltaTime) override;

	//çXêVä÷êî	
	void fadeIn(float at) override;
	void sceneMain(float at) override;
	void fadeOut(float at) override;

	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);


	CREATE_FUNC(DirectionScene);
private:
	ParticleSystemQuad* mParticle;

	void createAnimation();
};

#endif