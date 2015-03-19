#ifndef STAGECREATER_H
#define STAGECREATER_H

#include "Game/Util/FileIO/CSVReader.h"
#include "cocos2d.h"
#include "Game/Util/FileIO/ReadData.h"
#include <vector>

#include "StageObjManager.h"
#include "Game/Object/Character/SeaFireFly/SeaFireFlyManager.h"
#include "Game/Object/Character/Enemy/EnemyManager.h"

#include "StageFactory.h"
#include "Game/Object/Character/Enemy/EnemyFactory.h"

class StageManager;

USING_NS_CC;

namespace Stage{
		
	class StageCreater{
	public:
	
		StageManager* create(Layer* layer, const std::string& filename);

	private:
		void createEnemy(Layer* layer,EnemyFactory* factory, EnemyManager* enemyManager, const ReadData data);
		void createStageObj(Layer* layer,StageFactory* factory, StageObjManager* stageObjManager,const ReadData data);
		void createSeaFly(Layer* layer, SeaFireFlyManager* seaFlyManager,const ReadData data);

	};
}
#endif // !STAGECREATER_H
