/*--------------------------------------
StageSelectScene.cpp
FishLight
Created by settyan on 2015/01/13.
---------------------------------------*/

#include "StageSelectScene.h"
#include "Game/Scene/Direction/DirectionScene.h"
#include "Game/Util/DeterminedStage.h"
#include "Game/Util/FileIO/FileReader.h"
#include "Game/Draw/Effect/Particle/SimpleParticle.h"
#include "Game/Scene/StageSelect/StageNumberWriter.h"
#include "Game/Sound/RappingAudio.h"

#include <string>

USING_NS_CC;

using namespace cocos2d;
using namespace std;

#define VISIBLESIZE Director::getInstance()->getVisibleSize()
#define ORIGINSIZE Director::getInstance()->getVisibleOrigin()

/*----------------------------------------------------------------------------------
コンストラクタ
----------------------------------------------------------------------------------*/
StageSelectScene::StageSelectScene(){
	mStageNumber = 0;
	mStageSelect = false;
	mPrebiewOn = false;
	compFlag = false;
	mStageNull = false;
	minitFlag = true;
	mtest = 0;
}

/*----------------------------------------------------------------------------------
デストラクタ
----------------------------------------------------------------------------------*/
StageSelectScene::~StageSelectScene(){

	//ステージナンバーの書き込み(中断時)
	//StageNumberWriter snw;
	//snw.writeStageNumber(DeterminedStage::stageName);

	//ステージナンバーの書き込み（クリア）
	//StageNumberWriter snw;
	//snw.writeStageNumber("");
	auto a = RappingAudio::getInstance()->getBGM(TITLE);
	a->stop();

}
/*----------------------------------------------------------------------------------
シーン作成
----------------------------------------------------------------------------------*/
Scene* StageSelectScene::createScene(){
	auto scene = Scene::createWithPhysics();
	auto layer = StageSelectScene::create();
	scene->addChild(layer);
	return scene;
}

/*----------------------------------------------------------------------------------
初期化
----------------------------------------------------------------------------------*/
bool StageSelectScene::init(){
	if (!LayerGradient::initWithColor(Color4B(0, 0, 0, 0), Color4B(0, 0, 0, 0), Vec2(0, 0)))
	{
		return false;
	}

	iconDraw();
	backGroundDraw();
	minStageDraw();
	frameviem();


	//コンプの星生成
	star = Sprite::create("Scene/Result/CompleteStar.png");
	star->setPosition(Vec2(1800, 100));
	star->setScale(0.5f, 0.5f);
	this->addChild(star, 101);

	oklogo = Sprite::create("Scene/StageSelect/OK.png");
	oklogo->setPosition(Vec2(2000, 2000));
	oklogo->setScale(0.9f, 1);
	this->addChild(oklogo, 101);

	Lightlogo = Sprite::create("Scene/StageSelect/TouchButton.png");
	Lightlogo->setPosition(Vec2(2000, 2000));
	Lightlogo->setScale(1.5f, 1.5f);
	Lightlogo->setOpacity(0);
	this->addChild(Lightlogo, 101);

	auto bable = SimpleParticle::create("TitleBubble", Point(VISIBLESIZE.width / 2, 0));
	addChild(bable, 0);

	//アップデートのスケジュール登録
	this->schedule(schedule_selector(StageSelectScene::update));

	//タッチ判定
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(StageSelectScene::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	return true;
}

/*----------------------------------------------------------------------------------
更新
----------------------------------------------------------------------------------*/
void StageSelectScene::update(float at){



	//選択フレームの移動
	if (!minitFlag){
		Vec2 framePos[] =
		{
			Vec2(125, 500), Vec2(325, 500), Vec2(525, 500), Vec2(750, 500), Vec2(950, 500), Vec2(1150, 500),
			Vec2(125, 300), Vec2(325, 300), Vec2(525, 300),
			Vec2(125, 100), Vec2(325, 100), Vec2(525, 100),
		};
		mFrameSprite->setPosition(framePos[mStageNumber]);
	}
	else
		mFrameSprite->setPosition(Vec2(2000, 2000));

	//星の移動
	std::string stageName[] =
	{
		"Stage01", "Stage02", "Stage03",
		"Stage04", "Stage05", "Stage06",
		"Stage07", "Stage08", "Stage09",
		"Stage10", "Stage11", "Stage12",
	};
	if (mStageNull){
		FileReader fr;
		if (fr.readBoolean(stageName[mStageNumber])){
			star->setPosition(Vec2(1200, 100));
		}
		else star->setPosition(Vec2(1800, 100));
	}




	//アイコンの生成
	if (mtest == 1){

		oklogo->setPosition(Vec2(650, 700));

		//フェードインのアクション
		auto fadeIn = FadeIn::create(1.5);

		//フェードアウトのアクション
		auto fadeOut = FadeOut::create(1.5);

		//シークエンスの生成
		//フェードイン->フェードアウトの順番にアクションを並べる
		auto sequence = Sequence::create(fadeIn, fadeOut, NULL);

		//リピートの生成
		repeatForever = RepeatForever::create(sequence);

		Lightlogo->setPosition(Vec2(183, 705));

		Lightlogo->runAction(repeatForever);



		//フェードインのアクション
		auto fadeIn2 = FadeIn::create(1.5);

		//フェードアウトのアクション
		auto fadeOut2 = FadeOut::create(1.5);

		//シークエンスの生成
		//フェードイン->フェードアウトの順番にアクションを並べる
		auto sequence2 = Sequence::create(fadeIn2, fadeOut2, NULL);

		repeatForever = RepeatForever::create(sequence2);

		oklogo->runAction(repeatForever);

		//ステージ
		auto createOkButton = [&]()
		{
			auto buttonImage = MenuItemImage::create("Scene/StageSelect/OK.png",
				"Scene/StageSelect/OK.png",
				[=](Ref* sender)
			{
				mStageSelect = true;
			});

			buttonImage->setPosition(183, 705);
			buttonImage->setScale(0.8f, 0.8f);
			buttonImage->setOpacity(0);
			auto buttonMenu = Menu::create(buttonImage, nullptr);
			buttonMenu->setPosition(Vec2::ZERO);
			this->addChild(buttonMenu, 101);
		};



		//ステージ
		auto createLightButton = [&]()
		{
			auto buttonImage = MenuItemImage::create("Scene/StageSelect/TouchButton.png",
				"Scene/StageSelect/TouchButton.png",
				[=](Ref* sender)
			{
				mStageSelect = true;
			});

			buttonImage->setPosition(650, 700);
			buttonImage->setScale(0.5f, 0.5f);
			buttonImage->setOpacity(0);


			auto buttonMenu = Menu::create(buttonImage, nullptr);
			buttonMenu->setPosition(Vec2::ZERO);
			this->addChild(buttonMenu, 101);
		};

		createOkButton();
		createLightButton();

		mtest++;
	}

	//プレビューの表示
	previewDraw();

	//シーン繊維
	if (mStageSelect && mStageNull){

		mStageSelect = false;
		conversionToStagePath();

		auto scene = DirectionScene::createScene();
		auto fade = TransitionFade::create(1, scene);
		Director::getInstance()->replaceScene(fade);
	}

	if (minitFlag){
		mStageNumber = 0;
		mStageSelect = false;
		mPrebiewOn = false;
		compFlag = false;
		mStageNull = false;
		//minitFlag = false;
		mtest = 0;
		mFrameSprite->setPosition(Point(2000, 2000));
		oklogo->setPosition(Point(2000, 2000));
		Lightlogo->setPosition(Point(2000, 2000));
		//DeterminedStage::stageName = "";
		//DeterminedStage::determinedStageFailePath = "";
	}

}

/*----------------------------------------------------------------------------------
FailPath変換
----------------------------------------------------------------------------------*/
void StageSelectScene::conversionToStagePath(){

	std::string filePath[] =
	{
		"ParameterPlist/Stage1.plist", "ParameterPlist/Stage2.plist", "ParameterPlist/Stage3.plist",
		"ParameterPlist/Stage4.plist", "ParameterPlist/Stage5.plist", "ParameterPlist/Stage6.plist",
		"ParameterPlist/Stage7.plist", "ParameterPlist/Stage8.plist", "ParameterPlist/Stage9.plist",
		"ParameterPlist/Stage10.plist", "ParameterPlist/Stage11.plist", "ParameterPlist/Stage12.plist",
	};

	std::string stageName[] =
	{
		"Stage01", "Stage02", "Stage03",
		"Stage04", "Stage05", "Stage06",
		"Stage07", "Stage08", "Stage09",
		"Stage10", "Stage11", "Stage12",
	};

	DeterminedStage::init();
	DeterminedStage::determinedStageFailePath = filePath[mStageNumber];
	DeterminedStage::stageName = stageName[mStageNumber];
	DeterminedStage::stageNum = mStageNumber;
	//CCLOG("%s",DeterminedStage::stageName.c_str());
}


/*----------------------------------------------------------------------------------
タッチ判定
----------------------------------------------------------------------------------*/
bool StageSelectScene::onTouchBegan(Touch* touch, Event* event){

	return true;
}

/*----------------------------------------------------------------------------------
アイコン表示
----------------------------------------------------------------------------------*/
void StageSelectScene::iconDraw(){
	//アイコンの生成
	/*
	Sprite* titlelogo = Sprite::create("Scene/StageSelect/Icon.png");
	titlelogo -> setPosition(Vec2(VISIBLESIZE.width/2, VISIBLESIZE.height/1.1f));
	titlelogo -> setScale(0.9f, 1);
	this->addChild(titlelogo,3);
	*/

	auto createicon = [&]()
	{
		auto buttonImage = MenuItemImage::create("Scene/StageSelect/Icon.png",
			"Scene/StageSelect/Icon.png",
			[=](Ref* sender)
		{
			minitFlag = true;
		});

		buttonImage->setPosition(Vec2(VISIBLESIZE.width / 2, VISIBLESIZE.height / 1.1f));
		buttonImage->setScale(0.9f, 1);

		auto buttonMenu = Menu::create(buttonImage, nullptr);
		buttonMenu->setPosition(Vec2::ZERO);
		this->addChild(buttonMenu, 100);
	};

	createicon();
}

/*----------------------------------------------------------------------------------
背景表示
----------------------------------------------------------------------------------*/
void StageSelectScene::backGroundDraw(){
	//背景の生成
	/*Sprite* titlelogo1 = Sprite::create("Scene/StageSelect/BackGround.png");
	titlelogo1 -> setPosition(Vec2(VISIBLESIZE.width/2, VISIBLESIZE.height/1.4));
	titlelogo1 -> setScale(1.2f, 1.4f);
	titlelogo1 -> setTag(100);
	this->addChild(titlelogo1,0);*/

	auto createBack = [&]()
	{
		auto buttonImage = MenuItemImage::create("Scene/StageSelect/BackGround.png",
			"Scene/StageSelect/BackGround.png",
			[=](Ref* sender)
		{
			minitFlag = true;
		});

		buttonImage->setPosition(0, 0);
		buttonImage->setScale(2.0f, 1.4f);


		auto buttonMenu = Menu::create(buttonImage, nullptr);
		buttonMenu->setPosition(Vec2::ZERO);
		this->addChild(buttonMenu);
	};

	createBack();
}

/*----------------------------------------------------------------------------------
プレビュー枠表示
----------------------------------------------------------------------------------*/
void StageSelectScene::previewDraw(){

	std::string filePath[] =
	{
		"Scene/StageSelect/Stage1.png", "Scene/StageSelect/Stage2.png", "Scene/StageSelect/Stage3.png",
		"Scene/StageSelect/Stage4.png", "Scene/StageSelect/Stage5.png", "Scene/StageSelect/Stage6.png",
		"Scene/StageSelect/Stage7.png", "Scene/StageSelect/Stage8.png", "Scene/StageSelect/Stage9.png",
		"Scene/StageSelect/Stage10.png", "Scene/StageSelect/Stage11.png", "Scene/StageSelect/Stage12.png",
	};

	if (mPrebiewOn){
		PreviewImage[mStageNumber] = Sprite::create(filePath[mStageNumber]);
		PreviewImage[mStageNumber]->setPosition(950, 225);
		PreviewImage[mStageNumber]->setScale(1.5f, 1.4f);
		PreviewImage[mStageNumber]->setTag(mStageNumber);
		this->addChild(PreviewImage[mStageNumber], 100);
		mPrebiewOn = false;
	}

}

/*----------------------------------------------------------------------------------
小ステージ表示
----------------------------------------------------------------------------------*/
void StageSelectScene::minStageDraw(){

	std::string filePath[] =
	{
		"Scene/StageSelect/Stage1.png", "Scene/StageSelect/Stage2.png", "Scene/StageSelect/Stage3.png",
		"Scene/StageSelect/Stage4.png", "Scene/StageSelect/Stage5.png", "Scene/StageSelect/Stage6.png",
		"Scene/StageSelect/PreparationStage7.png", "Scene/StageSelect/PreparationStage8.png", "Scene/StageSelect/PreparationStage9.png",
		"Scene/StageSelect/PreparationStage10.png", "Scene/StageSelect/PreparationStage11.png", "Scene/StageSelect/PreparationStage12.png",
	};



	//ステージ
	auto createButton = [&](const Vec2& pos, int tag)
	{
		auto buttonImage = MenuItemImage::create(filePath[tag],
			filePath[tag],
			[=](Ref* sender)
		{
			if(tag > 5 ) return;
			
			minitFlag = false;
			mStageNumber = tag;
			mStageNull = true;
			mPrebiewOn = true;
			mtest++;
		});

		buttonImage->setPosition(pos);
		buttonImage->setScale(0.5f, 0.5f);
		auto buttonMenu = Menu::create(buttonImage, nullptr);
		buttonMenu->setPosition(Vec2::ZERO);
		this->addChild(buttonMenu, 100);
	};

	Vec2 poses[]
	{
		Vec2(125, 500), Vec2(325, 500), Vec2(525, 500), Vec2(750, 500), Vec2(950, 500), Vec2(1150, 500),
			Vec2(125, 300), Vec2(325, 300), Vec2(525, 300),
			Vec2(125, 100), Vec2(325, 100), Vec2(525, 100),

	};

	for (int i = 0; i < 12; ++i)
	{
		createButton(poses[i], i);
	}
}

/*----------------------------------------------------------------------------------
枠表示
----------------------------------------------------------------------------------*/
void StageSelectScene::frameviem(){
	mFrameSprite = Sprite::create("Scene/StageSelect/Frame.png");
	mFrameSprite->setPosition(Point(2000, 2000));
	mFrameSprite->setScale(0.5, 0.5);
	mFrameSprite->setTag(mStageNumber);
	this->addChild(mFrameSprite, 100);
}