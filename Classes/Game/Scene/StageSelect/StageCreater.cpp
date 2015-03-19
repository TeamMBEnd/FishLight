#include "StageCreater.h"
#include <vector>
#include <string>
#include "Game/Object/Character/Enemy/EnemyFactory.h"
#include "Game/Object/Character/Enemy/Enemy.h"
#include <algorithm>
#include "StageFactory.h"
#include "Game/Object/Stage/StageObj.h"
#include "StageManager.h"
#include "Game/Object/Character/SeaFireFly/SeaFireFly.h"
#include "Game/Util/FileIO/PlistReader.h"
#include "StageDataReader.h"
#include "Game/Util/DeterminedStage.h"
#include "Game/Object/Character/SeaFireFly/AggressiveSeaFireFly.h"



StageManager* Stage::StageCreater::create(Layer* layer,const std::string& filename){
	
	StageDataReader sdr;
	
	StageManager* sm = StageManager::create();
	EnemyManager* em = EnemyManager::create();
	StageFactory sf;
	EnemyFactory ef;

	StageObjManager* som = StageObjManager::create();
	SeaFireFlyManager* sfm = new SeaFireFlyManager();
	sfm->init();

	auto plistcontener = sdr.read(filename);
	for (auto objStr : plistcontener){

		createEnemy(layer,&ef, em, objStr);

		createStageObj(layer,&sf, som, objStr);

		createSeaFly(layer, sfm, objStr);

	}
	sm->setManager(em, som, sfm);

	return sm;
}

void Stage::StageCreater::createEnemy(Layer* layer,EnemyFactory* factory, EnemyManager* enemyManager, const ReadData data){
	
	
	Enemy* obj = factory->order(data.textureName);
	
	if (obj){
		obj->retain();
		//敵オブジェクトをマネージャーに追加
		enemyManager->addObj(obj);
		auto sprite = obj->enemyCreate(Size(data.positionX, data.positionY));
		sprite->setName(obj->getName());
		layer->addChild(sprite);
	}
}

void Stage::StageCreater::createStageObj(Layer* layer,StageFactory* factory, StageObjManager* stageObjManager, const ReadData data){
	
	auto obj = factory->order(data.textureName);

	if (obj){
		obj->setPosition(Size(data.positionX, data.positionY));
		stageObjManager->addObj(obj);
		layer->addChild(obj);
	}
}

void Stage::StageCreater::createSeaFly(Layer* layer, SeaFireFlyManager* seaFlyManager, const ReadData data){
	if (strstr(data.textureName.c_str(), "SeaFireFly.png")){
		seaFlyManager->add(layer, SeaFireFly::create(), Vec2(data.positionX, data.positionY), FREE);
	}
	if (strstr(data.textureName.c_str(), "SeaFireFly_Attack.png")){
		seaFlyManager->add(layer, AggressiveSeaFireFly::create(), Vec2(data.positionX, data.positionY), FREE);
	}
}