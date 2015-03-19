#include "DirectionScene.h"
#include "Game/Draw/DarknessMask.h"
#include "Game/Draw/Draw2D.h"
#include "Game/Draw/Effect/Light/SpotLight.h"
#include "Game/Scene/Main/MainLayer.h"
#include "Game/Util/DeterminedStage.h"
#include "Game/Util/Animation/SpriteAnimation.h"


USING_NS_CC;

Scene* DirectionScene::createScene(){
	auto scene = Scene::create();

	auto layer = DirectionScene::create();

	scene->addChild(layer);

	return scene;
}

DirectionScene::DirectionScene() : mParticle(nullptr){
}

bool DirectionScene::init(){
	
	if (!LayerGradient::initWithColor(Color4B(0, 0, 0, 0), Color4B(0, 0, 0, 0), Vec2(0, 0)))
	{
		return false;
	}
	//2D描画クラス作成
	addChild(Draw2D::getInstance()->create(), 90);
	
	//画面の幅を取得
	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto fade = DarknessMask::create(Color4B(0, 0, 0, 192), visibleSize);

	fade->setName("Fade");
	addChild(fade, 70);

	auto fadeFly = Sprite::create();
	fadeFly->setTexture("stage/chara/SeaFireFly.png");
	fadeFly->setName("FadeFly");
	fadeFly->setPosition(Vec2(0, 0));
	fadeFly->retain();

	addChild(fadeFly, 75);

	
	auto fadeAct = MoveTo::create(6, visibleSize);
	auto fadeOut = FadeOut::create(6);
	auto spawn = Spawn::create(fadeAct, fadeOut, nullptr);
	spawn->setTag(7);
	fadeFly->runAction(spawn);

	if (DeterminedStage::stageName != "Stage01"){
		fadeFly->stopAction(spawn);
		this->removeChildByName("FadeFly");
		mSceneState = MAIN;
	}
	
	this->schedule(schedule_selector(DirectionScene::update));
	this->scheduleUpdate();

	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(_swallowsTouches);
	listener->onTouchBegan = CC_CALLBACK_2(DirectionScene::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	
	auto back = Sprite::create("stage/BackGround.png");
	back->setPosition(0, 0);
	back->setScale(4, 4);

	addChild(back);

	return true;
}


DirectionScene::~DirectionScene()
{
	removeAllChildren();
	//mParticle->release();
}

void DirectionScene::update(float at){

	if (mSceneState != SCENEEND){
		(this->*updateFunc[mSceneState])(at);
	}

}

void DirectionScene::fadeIn(float at){
	auto fade = (Sprite*)getChildByName("FadeFly");
	auto mask = (LayerGradient*)getChildByName("Fade");

	if (!fade->getActionByTag(7)){
		removeChildByName("FadeFly");
		mSceneState = MAIN;
		return;
	}
}

void DirectionScene::sceneMain(float at){
	Size visibleSize = Director::getInstance()->getVisibleSize();

	createAnimation();

	if (!mParticle){
		auto filePath = "Particle2dx/Normal/GuideRipple.plist";
		mParticle = ParticleSystemQuad::create(filePath);
		mParticle->setPosition(visibleSize.width / 2, visibleSize.height / 2);
		mParticle->retain();

		addChild(mParticle,80);
	}

}

void DirectionScene::fadeOut(float at){

	auto scene = MainLayer::createScene();

	auto fade = TransitionFade::create(3, scene);

	Director::getInstance()->replaceScene(fade);

	mSceneState = SCENEEND;
}

bool DirectionScene::onTouchBegan(Touch *touch, Event* event){
	
	if (mSceneState != MAIN)
	{
		auto fadeSprite = (Sprite*)getChildByName("FadeFly");
		auto act = (Spawn*)fadeSprite->getActionByTag(7);
		act->setDuration(0.f);
		return true;
	}

	mSceneState = FADEOUT;
	
	return true;
}

void DirectionScene::createAnimation(){
	//パラパラ漫画
	if (!getChildByName("StartHand")){

		Util::SpriteAnimation spriteAnimation("Scene/Main/");

		auto animationSprite = spriteAnimation.create("StartHand", 4, 0.5f, true, true);
		
		animationSprite->setOpacity(0);
		auto fade = FadeIn::create(1.f);
		animationSprite->runAction(fade);
		
		Size visibleSize = Director::getInstance()->getVisibleSize();
		animationSprite->setPosition(visibleSize.width / 2, visibleSize.height / 2.5f);
		animationSprite->setAnchorPoint(Vec2(0, 0));

		addChild(animationSprite);
	}
}