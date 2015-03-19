#include "MainState.h"
#include "Game/Object/Character/Player/Player.h"
#include "Game/Util/Collision/CollisionListener.h"	
#include "Game/Object/Stage/Goal.h"
#include "Game/Draw/Effect/Blend/AlphaBlend.h"
#include "Game/Scene/Result/Layer/ResultLayer.h"
#include "Game/Draw/Effect/Light/LightManager.h"
#include "Game/Draw/DarknessMask.h"
#include "Game/Draw/BackGround.h"
#include "Game/Scene/StageSelect/StageCreater.h"
#include "Game/Scene/StageSelect/StageManager.h"
#include "Game/Sound/RappingAudio.h"
#include "Game/Util/DeterminedStage.h"
#include "Tutorial.h"


USING_NS_CC;

MainState::MainState(Layer* _layer):m_Tutorial(nullptr){
	layer = _layer;
	init();
}

MainState::~MainState(){

	delete m_Tutorial;
	RappingAudio::getInstance()->getBGM(BGMTag::PLAY)->stop();
	m_Player->release();
	m_Manager->release();
	DarknessMask::destroy(layer);
}

// on "init" you need to initialize your instance
bool MainState::init()
{

	//衝突判定の追加
	auto col = CollisionListener::create();
	layer->addChild(col);

	//背景の追加
	BackGround bg;
	bg.Initialize(layer);

	//ステージを作成
	Stage::StageCreater sc;
	DeterminedStage::set();
	m_Manager = sc.create(layer, DeterminedStage::determinedStageFailePath);

	auto node = Node::create();
	auto func = CallFunc::create([&]() { auto bgm = RappingAudio::getInstance()->getBGM(BGMTag::PLAY); bgm->play(); });
	auto delay = DelayTime::create(1.5f);
	auto seq = Sequence::create(delay, func, nullptr);
	node->runAction(seq);
	layer->addChild(node);


	//暗闇＆ライト
	LightManager::getInstance()->init();
	m_Blend = new AlphaBlendFunc();
	m_Blend->setBlendFunc(GL_ZERO, GL_SRC_COLOR);

	layer->addChild(DarknessMask::create(Color4B(0, 0, 0, 240), Size(6400, 5376)), 50);

	LightManager::getInstance()->createLight(layer);


	//プレイヤーの追加
	m_Player = Player::create();
	auto playerSprite = m_Player->createPlayer();
	m_Player->addChild(playerSprite);
	layer->addChild(m_Player, 60);

	//カメラをプレイヤーに追従させる(画像が移動するので画像に合わせる)
	layer->runAction(Follow::create(playerSprite, Rect(0, 0, 6400, 5376)));

	if (DeterminedStage::stageNum == 0){
		m_Tutorial = new Scenes::Tutorial();
		layer->addChild(m_Tutorial->createWindow(), 100);
	}

	return true;
}

bool MainState::onTouchBegan(Touch *touch, Event* event,const Vec2& LayerPos)
{
	if (mSceneState != MAIN) return true;

	//ゴール時操作不能
	if (!m_Manager->getGoal()) return false;

	Vect touchPoint = touch->getLocation();
	if (m_Player->touchBegan(touchPoint, LayerPos)){
		if (layer->getChildByName("Touch")){
			layer->removeChildByName("Touch");
		}
	}
	m_Manager->touchUpdate(touchPoint, getPosition());

	auto location = touch->getLocation() - getPosition();

	return true;
}


void MainState::onTouchEnded(Touch *touch, Event* event)
{
	if (mSceneState != MAIN) return;
	//ゴール時操作不能
	if (!m_Manager->getGoal())return;

	auto location = touch->getLocation() - getPosition();
	Vect endPoint = touch->getLocation();
	if (m_Manager->flyTouchEnd(endPoint))return;
	m_Player->touchEnd(endPoint);

}

void MainState::update(float at)
{
	Size win_size = Director::getInstance()->getWinSize();

	if (mSceneState < 3){
		if (!layer->getParent()->getChildByName("PauseLayer"))
		{
			(this->*updateFunc[mSceneState])(at);
		}
	}

	m_Blend->maskBlend(nullptr, at, layer->getPosition());

}

void MainState::fadeIn(float at){
	mSceneState = MAIN;
}

void MainState::sceneMain(float at){

	//ゴール時操作不能
	if (!m_Manager->getGoal())return;


	m_Player->update(layer, at);
	m_Manager->update(at);

	auto* sprite = m_Player->getChildByName("PlayerSprite");
	m_Manager->flyMove(sprite->getPosition(), sprite->getPhysicsBody()->getVelocity(), at);
	m_Manager->enemyMove(at, sprite->getPosition());


	//ゴール判定
	if (!m_Manager->getGoal()){
		//フェードアウト
		mSceneState = FADEOUT;
	}

	if (m_Tutorial){
		m_Tutorial->update(layer, m_Player);																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																											//記憶障害マン
	}
}

void  MainState::fadeOut(float at){
	m_Player->getChildByName("PlayerSprite")->getPhysicsBody()->setVelocity(Point(0, 0));
	m_Player->getChildByName("PlayerSprite")->getPhysicsBody()->setContactTestBitmask(false);
	m_Player->getChildByName("PlayerSprite")->getPhysicsBody()->setCollisionBitmask(false);

	if (!layer->getChildByName("resultLayer"))
	{
		auto r = m_Manager->getSeaFireFlyManager()->seaFireFlyCheck();
		auto resultLayer = ResultLayer::create(r, layer->getPosition());
		layer->addChild(resultLayer, 100);
		resultLayer->setName("resultLayer");
	}

}