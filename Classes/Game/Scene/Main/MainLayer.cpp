#include "MainLayer.h"

USING_NS_CC;

MainLayer::~MainLayer(){
	delete state;
}

Scene* MainLayer::createScene()
{
	auto scene = Scene::createWithPhysics();

	auto layer = MainLayer::create();

	scene->addChild(layer);

	PhysicsWorld* world = scene->getPhysicsWorld();
	Vect gravity;

	gravity.setPoint(0, 0);

	world->setGravity(gravity);
	//world->setDebugDrawMask( PhysicsWorld::DEBUGDRAW_ALL );

	return scene;
}

bool MainLayer::init()
{

	if (!LayerGradient::initWithColor(Color4B(0, 0, 0, 0), Color4B(0, 0, 0, 0), Vec2(0, 0)))
	{
		return false;
	}

	//画面の幅を取得
	auto winSize = cocos2d::Director::getInstance()->getWinSize();

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(_swallowsTouches);

	listener->onTouchBegan = CC_CALLBACK_2(MainLayer::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(MainLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	this->schedule(schedule_selector(MainLayer::update));
	this->scheduleUpdate();

	state = new MainState(this);

	return true;
}

bool MainLayer::onTouchBegan(Touch *touch, Event* event)
{
	return state->onTouchBegan(touch, event,getPosition());
}


void MainLayer::onTouchEnded(Touch *touch, Event* event)
{
	state->onTouchEnded(touch, event);
}

void MainLayer::update(float at)
{
	state->update(at);
}