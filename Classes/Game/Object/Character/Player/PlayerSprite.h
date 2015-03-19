#ifndef _PLAYERSPRITE_H_
#define _PLAYERSPRITE_H_

#include "cocos2d.h"


USING_NS_CC;

enum PLAYERSTATE{
	normal = 0,
	halfmove,
	whirlpool,
	damage,
	Palsy,
	End
};

class PlayerSprite : public cocos2d::Sprite
{
public:
	PlayerSprite();
	~PlayerSprite();


	virtual bool init();
	void onEnter() override;
	Sprite* createPlayer();
	void update(Layer* layer,int state,float at);
	void move(Layer* layer, float at);
	void halfMove(Layer* layer, float at);
	void jump(Layer* layer, float at);
	void palsy(Layer* layer, float at);

	bool touchBegan(Point touchPos, const Vec2& layerPos);
	void touchEnd(Point endPos);
	
	void setPhysicsState(bool a, bool b);

	void damage(Layer* layer, float at);

	CREATE_FUNC(PlayerSprite);

	//更新関数ポインタ
	void(PlayerSprite::*updateFunc[PLAYERSTATE::End])(Layer* layer, float atW);

private:
	Point touchPoint;
	bool  isTouch;
	bool  mIsSound;
	
};


#endif