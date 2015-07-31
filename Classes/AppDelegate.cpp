#include "AppDelegate.h"
#include "Game/Scene/Title/TitleScene.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
: mADX2Manager(ADX2Manager::create())
{
	mADX2Manager->retain();
}

AppDelegate::~AppDelegate()
{
	mADX2Manager->release();
}

bool AppDelegate::applicationDidFinishLaunching()
{
	auto director = Director::getInstance();
	auto glView = director->getOpenGLView();

	if (!glView)
	{
		glView = GLView::create("FishLight");
		director->setOpenGLView(glView);
	}

	director->setDisplayStats(false);

	director->setAnimationInterval(1.f / 60.f);
	glView->setDesignResolutionSize(1280, 780, ResolutionPolicy::SHOW_ALL);

	mADX2Manager->init("ADX2Sound/ADX2_samples.acf");

	auto scene = TitleScene::createScene();
	director->runWithScene(scene);
	//test
	return true;
}

void AppDelegate::applicationDidEnterBackground()
{
	Director::getInstance()->stopAnimation();
	SimpleAudioEngine::getInstance()->stopBackgroundMusic();

	mADX2Manager->pauseApp();
}

void AppDelegate::applicationWillEnterForeground()
{
	Director::getInstance()->startAnimation();
	SimpleAudioEngine::getInstance()->resumeAllEffects();

	mADX2Manager->resumeApp();
}