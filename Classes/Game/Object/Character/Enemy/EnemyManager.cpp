#include "EnemyManager.h"
#include "Enemy.h"
#include <algorithm>
#include "EnemyRemove.h"
#include "Game/Util/Collision/CollisionFuncManager.h"
#include "Game/Util/Collision/CollisionDelegate.h"

EnemyManager::EnemyManager(){
	//参照カウンタ増やします
	this->retain();
}

EnemyManager::~EnemyManager(){
	std::for_each(EnemyContainer.begin(),
		EnemyContainer.end(),
		[](Enemy* obj){obj->releaseObj(); });
	deleteObj();
}

void EnemyManager::update(float deltatime, Vec2 targetPos){
	std::for_each(EnemyContainer.begin(), EnemyContainer.end(), [deltatime, targetPos](Enemy* obj){
		obj->update(deltatime, targetPos);
	});	

	deleteObj();
}

void EnemyManager::addObj(Enemy* obj){

	auto size = EnemyContainer.size();
	auto name = obj->getName() + std::to_string(size);
	obj->setName(name);
	
	auto c = CollisionDelegate<Enemy>::create(obj, &Enemy::onContact);
	CollisionFuncManager::getInstance()->addFunc(obj->getName(), c);
	
	EnemyContainer.push_back(obj);
}

void EnemyManager::deleteObj(){

	EnemyContainer.remove_if(EnemyRemove());
}


