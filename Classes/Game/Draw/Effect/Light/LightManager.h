#ifndef LIGHTMANAGER_H
#define LIGHTMANAGER_H

#include "BlendLight.h"
#include <List>

class LightManager{
public:
	~LightManager();

	void addDrawList(float animationTime,const Vec2* pos,float scale,bool isLoop);

	void draw(BlendFunc blend, float deltaTime, Vec2 pos);

	void init();

	void createLight(Layer* layer);

	static LightManager* getInstance();
private:
	typedef std::list<BlendLight*> LightList;

	LightManager();
	LightManager(const LightManager&);
	LightManager& operator=(const LightManager&);

	LightList mLightList;
};

inline LightManager* LightManager::getInstance(){
	static LightManager instance;
	return &instance;
}

#endif