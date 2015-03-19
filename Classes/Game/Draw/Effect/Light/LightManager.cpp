#include "LightManager.h"

#include <algorithm>

#define LightNum 40

LightManager::LightManager(){
	for (int i = 0; i < LightNum; i++){
		BlendLight* light = new BlendLight();
		light->retain();
		mLightList.push_back(light);
	}
}

LightManager::~LightManager(){
	auto it = mLightList.begin();
	auto end = mLightList.end();
	for (; it != end;){
		(*it)->release();
		(*it) = nullptr;
		it = mLightList.erase(it);
		++it;
	}
}

void LightManager::addDrawList(float animationTime,const Vec2* pos, float scale, bool isLoop){
	
	
		LIGHTSTATE info;
		info.AnimationTime = animationTime;
		info.pos = pos;
		info.scale = scale;
		info.isLoop = isLoop;
		info.isDraw = nullptr;

		auto it = mLightList.begin();

		for (; it != mLightList.end();){
			if (!(*it)->isDraw()){
				(*it)->setDraw(info);
				return;
			}
			++it;
		}
}

void LightManager::draw(BlendFunc blend, float deltaTime, Vec2 pos){
	std::for_each(mLightList.begin(), mLightList.end(),
					[blend,deltaTime,pos](BlendLight* obj){obj->draw(blend,deltaTime,pos); });
}

void LightManager::init(){
	auto it = mLightList.begin();
	auto end = mLightList.end();
	for (; it != end;){
		(*it)->release();
		(*it) = nullptr;
		it = mLightList.erase(it);
	}

	for (int i = 0; i < LightNum; i++){
		BlendLight* light = new BlendLight();
		light->retain();
		mLightList.push_back(light);
	}

	auto it2 = mLightList.begin();
	auto end2 = mLightList.end();
	for (; it2 != end2;){
		(*it2)->initState();
		++it2;
	}
}


void LightManager::createLight(Layer* layer){
	auto it = mLightList.begin();
	auto end = mLightList.end();
	for (; it != end;){
		layer->addChild((*it),60);
		++it;
	}
}