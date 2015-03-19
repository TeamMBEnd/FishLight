#include "TitleScene.h"
#include "Game/Scene/Direction/DirectionScene.h"
#include "Game/Scene/Main/MainLayer.h"
#include "Game/Draw/Effect/Particle/SimpleParticle.h"
#include "Game/Scene/StageSelect/StageSelectScene.h"
#include "Game/Sound/RappingAudio.h"
#include "Game/Util/DeterminedStage.h"
#include "Game/Util/FileIO/FileReader.h"
#include "Game/Util/FileIO/FileWriter.h"


USING_NS_CC;

using namespace cocos2d;
using namespace std;

#define VISIBLESIZE Director::getInstance()->getVisibleSize()
#define ORIGINSIZE Director::getInstance()->getVisibleOrigin()



/*----------------------------------------------------------------------------------
 コンストラクタ
 ----------------------------------------------------------------------------------*/
TitleScene::TitleScene(){
	transitionCount = 1;
	titleDelay = 0;
	nextFlag = 0;
	sceneCount = 0;

	FileWriter fr;
}

/*----------------------------------------------------------------------------------
 デストラクタ
 ----------------------------------------------------------------------------------*/
TitleScene::~TitleScene(){
	
	if(sceneCount == 5){
		auto a = RappingAudio::getInstance()->getBGM(TITLE);
		a->stop();
	}
	
}

/*----------------------------------------------------------------------------------
 シーン作成
 ----------------------------------------------------------------------------------*/
Scene* TitleScene::createScene(){
	auto scene = Scene::createWithPhysics();
	auto layer = TitleScene::create();
	scene->addChild(layer);
	return scene;
}


/*----------------------------------------------------------------------------------
 初期化
 ----------------------------------------------------------------------------------*/
bool TitleScene::init(){
	if (!LayerGradient::initWithColor(Color4B(0, 0, 0, 0), Color4B(0, 0, 0, 0), Vec2(0, 0)))
	{
		return false;
	}
	
	
	//繧後＞繧�繝ｼ縺輔＞縺�
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	//泡表示
	bableAdd();
	
	//背景表示
	backGraundDraw();
	//ロゴ表示
	logoDraw();
	
	//音再生
	bgmPlay();
	
	//各ボタン生成
	
	//auto a = RappingAudio::getInstance() -> getSE(SE1);
	//a->unload();
	
	//アップデートのスケジュール登録
	this->schedule(schedule_selector(TitleScene::update));
	
	//タッチ判定
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(TitleScene::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	
	
	return true;
}


/*----------------------------------------------------------------------------------
 更新
 ----------------------------------------------------------------------------------*/
void TitleScene::update(float at) {
	if(titleDelay < 150)titleCount();
	
	if(titleDelay == 15){
		//フェード処理
		auto fadeIn1 = FadeIn::create(3);
		titleBG->runAction(fadeIn1);
		//フェード処理
		auto fadeIn2 = FadeIn::create(3);
		titlelogo->runAction(fadeIn2);
	}
	
	
	if(nextFlag == 1){
		
		FileReader fr;
		
		CCLOG("aaaaaaaaaaaaa:%s",fr.readString("StageName").c_str());
		if(fr.readString("StageName") != ""){
			TitleContinuanceButton();
			
		}
		
		TitleFirstButton();
		TitleStageSelect();
		

		touchlogo->stopAction(repeatForever);
		touchlogo->setOpacity(0);
		nextFlag++;
	}
	
	if(sceneCount != 0){
		sceneSerect();
	}
	
	
	
	if(transitionCount == 1){
		touchStartDraw();
		//カウントの増加(タッチスタート点滅時)
		transitionCount++;
	}
	
	
	
}


/*----------------------------------------------------------------------------------
 タッチ判定
 ----------------------------------------------------------------------------------*/
bool TitleScene::onTouchBegan(Touch* touch, Event* event){
	
	//if(transitionCount != 2) return false;
	//カウントの増加(タッチ判定受領後)
	/*
	 touchlogo->stopAction(repeatForever);
	 touchlogo->setOpacity(255);
	 
	 auto blink = Blink::create(1, 10);
	 touchlogo->runAction(blink);
	 */
	
	nextFlag++;
	
	/*
	 auto scene = StageSelectScene::createScene();
	 auto fade = TransitionFade::create(5, scene);
	 Director::getInstance() -> replaceScene(fade);
	 */
	
	
	/*
	 auto scene = DirectionScene::createScene();
	 auto fade = TransitionFade::create(3, scene);
	 Director::getInstance() -> replaceScene(fade);

	 */

	return true;
}

/*----------------------------------------------------------------------------------
 タイトル背景表示
 ----------------------------------------------------------------------------------*/
void TitleScene::backGraundDraw(){
	
	
	//Spriteの生成
	titleBG = Sprite::create("Scene/Title/Title.png");
	titleBG -> setPosition(Vec2(VISIBLESIZE.width/2, VISIBLESIZE.height/2));
	titleBG -> setScale(1.3f, 1.1f);
	titleBG -> setOpacity(0);
	
	//追加
	this->addChild(titleBG,0);
	
	//フェード処理
	//auto fadeIn = FadeIn::create(3);
	//titleBG->runAction(fadeIn);
}

/*----------------------------------------------------------------------------------
 タイトルロゴ表示
 ----------------------------------------------------------------------------------*/
void TitleScene::logoDraw(){
	
	//Spriteの生成
	titlelogo = Sprite::create("Scene/Title/Tltile_Logo.png");
	titlelogo -> setPosition(Vec2(VISIBLESIZE.width/2, VISIBLESIZE.height/1.4));
	titlelogo -> setScale(0.9f, 1);
	titlelogo -> setOpacity(0);
	
	//追加
	this->addChild(titlelogo,1);
	
	//フェード処理
	//auto fadeIn = FadeIn::create(3);
	//titlelogo->runAction(fadeIn);
	
}

/*----------------------------------------------------------------------------------
 タッチスタート表示
 ----------------------------------------------------------------------------------*/
void TitleScene::touchStartDraw(){
	
	
	//Spriteの生成
	touchlogo = Sprite::create("Scene/Title/Touch_Start.png");
	touchlogo->setPosition(Point(VISIBLESIZE.width/2, VISIBLESIZE.height/4));
	touchlogo->setOpacity(0);
	this->addChild(touchlogo);
	
	//フェードインのアクション
	auto fadeIn = FadeIn::create(3);
	
	//フェードアウトのアクション
	auto fadeOut = FadeOut::create(1.5);
	
	//シークエンスの生成
	//フェードイン->フェードアウトの順番にアクションを並べる
	auto sequence = Sequence::create(fadeIn, fadeOut, NULL);
	
	//リピートの生成
	repeatForever = RepeatForever::create(sequence);
	
	//開始
	touchlogo->runAction(repeatForever);
}

/*----------------------------------------------------------------------------------
 タイトル内カウント関数
 ----------------------------------------------------------------------------------*/
void TitleScene::titleCount(){
	
	titleDelay++;
	CCLOG("%d",titleDelay);
	if(titleBG->getOpacity() == 255 && transitionCount == 0) {
		//カウントの増加(タイトル表示完了)
		transitionCount++;
	}
}

/*----------------------------------------------------------------------------------
 泡生成
 ----------------------------------------------------------------------------------*/
void TitleScene::bableAdd(){
	auto bable_left = SimpleParticle::create("TitleBubble", Point(VISIBLESIZE.width/2+350, 0));
	auto bable_right = SimpleParticle::create("TitleBubble", Point(VISIBLESIZE.width/2-350, 0));
	
	addChild(bable_left,30);
	addChild(bable_right,30);
	
}

/*----------------------------------------------------------------------------------
 BGM再生
 ----------------------------------------------------------------------------------*/
void TitleScene::bgmPlay(){

	
	auto node = Node::create();
	
	auto func = CallFunc::create([&]() { auto bgm = RappingAudio::getInstance()->getBGM(TITLE); bgm->play(); });
	auto delay = DelayTime::create(1.1f);

	auto seq = Sequence::create(delay, func, nullptr);

	node->runAction(seq);

	this->addChild(node);
}



/*----------------------------------------------------------------------------------
 コンテボタン
 ----------------------------------------------------------------------------------*/
void TitleScene::TitleContinuanceButton(){

	auto createContinuanceButton = [ & ]()
	{
		auto buttonImage = MenuItemImage::create( "Scene/Title/TitleContinuance.png",
												 "Scene/Title/TitleContinuance.png",
												 [ = ]( Ref* sender )
												 {
													 sceneCount = 1;
													 CCLOG("%i",sceneCount);
												 } );
		buttonImage->setAnchorPoint(Vec2(0,0));
		buttonImage->setPosition(452, VISIBLESIZE.height - 686);
		auto buttonMenu = Menu::create( buttonImage, nullptr );
		buttonMenu->setPosition( Vec2::ZERO );
		this->addChild( buttonMenu );
	};
	
	createContinuanceButton();
	
}

/*----------------------------------------------------------------------------------
 最初から
 ----------------------------------------------------------------------------------*/
void TitleScene::TitleFirstButton(){
	auto createFirstButton = [ & ]()
	{
		auto buttonImage = MenuItemImage::create( "Scene/Title/TitleFirst.png",
												 "Scene/Title/TitleFirst.png",
												 [ = ]( Ref* sender )
												 {
													 sceneCount = 2;
													 CCLOG("%i",sceneCount);
												 } );
		buttonImage->setAnchorPoint(Vec2(0,0));
		buttonImage->setPosition( 66, VISIBLESIZE.height - 682 );
		auto buttonMenu = Menu::create( buttonImage, nullptr );
		buttonMenu->setPosition( Vec2::ZERO );
		this->addChild( buttonMenu );
	};
	
	createFirstButton();
	
}

/*----------------------------------------------------------------------------------
 ステージセレクト
 ----------------------------------------------------------------------------------*/
void TitleScene::TitleStageSelect(){
	
	auto createStageSelect = [ & ]()
	{
		auto buttonImage = MenuItemImage::create( "Scene/Title/TitleStageSelect.png",
												 "Scene/Title/TitleStageSelect.png",
												 [ = ]( Ref* sender )
												 {
													 sceneCount = 3;
													 CCLOG("%i",sceneCount);
												 } );
		buttonImage->setAnchorPoint(Vec2(0,0));
		buttonImage->setPosition( 828,VISIBLESIZE.height - 686 );
		//buttonImage->setScale(0.5f,0.5f);
		auto buttonMenu = Menu::create( buttonImage, nullptr );
		buttonMenu->setPosition( Vec2::ZERO );
		this->addChild( buttonMenu );
	};
	createStageSelect();
}

void TitleScene::sceneSerect(){
	//続きから
	if(sceneCount == 1){
		FileReader fr;
        DeterminedStage::determinedStageFailePath = fr.readString("StageFilePath");
		DeterminedStage::stageName = fr.readString("StageName");

		auto scene = DirectionScene::createScene();
		auto fade = TransitionFade::create(3, scene);
		Director::getInstance() -> replaceScene(fade);
		sceneCount =5;
	}
	
	//最初から
	if(sceneCount == 2){
		DeterminedStage::determinedStageFailePath = "ParameterPlist\\Stage1.plist";
		DeterminedStage::stageName = "Stage01";
		DeterminedStage::stageNum = 0;
		auto scene = DirectionScene::createScene();
		auto fade = TransitionFade::create(3, scene);
		Director::getInstance() -> replaceScene(fade);
		sceneCount =5;
	}
	
	//ステージセレクト
	if(sceneCount == 3){
		
		auto scene = StageSelectScene::createScene();
		auto fade = TransitionFade::create(5, scene);
		Director::getInstance() -> replaceScene(fade);
		sceneCount =6;
	}
}


