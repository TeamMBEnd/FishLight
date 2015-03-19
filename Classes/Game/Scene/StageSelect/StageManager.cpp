#include "StageManager.h"
#include "StageObjManager.h"
#include "Game/Object/Character/Enemy/EnemyManager.h"
#include "Game/Object/Character/SeaFireFly/SeaFireFlyManager.h"
#include <algorithm>


StageManager::StageManager(){
	//参照カウンタ増やします
	this->retain();
}

StageManager::~StageManager(){
	som->release();
	em->release();
	delete sfm;

	if (this->getReferenceCount() != 0)
	{
		// 参照カウンタを減らす
		this->release();
	}
}

void StageManager::update(float deltatime){
	som->update(deltatime);	
}

void StageManager::setManager(EnemyManager* _em, StageObjManager* _som,SeaFireFlyManager* _sfm){
	em = _em;
	som = _som;
	sfm = _sfm;
}

void StageManager::touchUpdate(Vect touchPos, Vec2 layerPos){
	sfm->touch(touchPos, layerPos);
}

void StageManager::flyMove(Vec2 targetPos,Vec2 targetVel, float dt){
	sfm->update(targetPos,targetVel,dt);
}

bool StageManager::flyTouchEnd(Point endPos)
{
	return sfm->touchEnd(endPos);
}
void StageManager::enemyMove(float deltatime, Vec2 targetPos){
	em->update(deltatime, targetPos);
}

StageObj* StageManager::getGoal(){
	return som->getGoal();
}

int StageManager::getSeaFireFly(){
	return sfm->aliveSeaFireFly();
}

SeaFireFlyManager* StageManager::getSeaFireFlyManager()
{

	return sfm;
}