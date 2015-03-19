#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "cocos2d.h"
#include "PlayerSprite.h"

USING_NS_CC;

class RippleManager;
class SeaFireFlyManager;

class Player:public Node
{
public:
	Player();
	~Player();

	Sprite* createPlayer();

	bool init();
	void update(Layer* layer,float at);
	void move(Layer* layer);
	bool touchBegan(Point touchPos,Vec2 layerPos);
	void touchEnd(Point endPos);
	void createRipple();
	void onContact(Node* node);
	void action(float at);

	CREATE_FUNC(Player);
private:
	PlayerSprite* sprite;
	RippleManager* rippleManager;
	PLAYERSTATE state;
	float  timer;
};

#endif