#include "StageObjManager.h"
#include "Game/Object/Stage/StageObj.h"
#include <algorithm>
#include "Game/Object/Stage/ObjRemove.h"
#include "Game/Util/Collision/CollisionFuncManager.h"
#include "Game/Util/Collision/CollisionDelegate.h"


StageObjManager::StageObjManager(){
	//参照カウンタ増やします
	this->retain();
}

StageObjManager::~StageObjManager(){
	std::for_each(stageObjContainer.begin(),
				  stageObjContainer.end(),
					[](StageObj* obj){obj->releaseObj(); });
	deleteObj();
}

void StageObjManager::update(float deltatime){
	std::for_each(stageObjContainer.begin(), stageObjContainer.end(), [deltatime](StageObj* obj){obj->update(deltatime); });

	deleteObj();
}

void StageObjManager::addObj(StageObj* obj){
	auto size = stageObjContainer.size();
	auto name = obj->getName() + std::to_string(size);
	obj->setName(name);

	//衝突したときに呼ばれる関数の登録
	auto c = CollisionDelegate<StageObj>::create(obj, &StageObj::onContact);
	CollisionFuncManager::getInstance()->addFunc(obj->getName(), c);

	stageObjContainer.push_back(obj);
}

void StageObjManager::deleteObj(){
	stageObjContainer.remove_if(ObjRemove());
}

StageObj* StageObjManager::getGoal(){
	auto itor = stageObjContainer.begin();
	auto end = stageObjContainer.end();

	while (itor != end)
	{
		if (strstr((*itor)->getName().c_str(),"Goal")){
			//strstr(node->getName().c_str(), "Enemy")
			return (*itor);
		}
		++itor;
	}
	return nullptr;
}
