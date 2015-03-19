#include "EnemyFactory.h"
#include "Enemy.h"
#include "EnemyLurk.h"
#include "EnemyReaper.h"
#include "EnemyRebellion.h"
#include "EnemyJellyFish.h"
#include "EnemyRippleFish.h"

Enemy* EnemyFactory::order(const std::string &name){

	return  EnemyFactory::create(name);
}


Enemy* EnemyFactory::create(const std::string name){
	if (strstr(name.c_str(), "EnemyRebellion")){
		return EnemyRebellion::create();
	}
	if (strstr(name.c_str(),"EnemyReaper")){
		return EnemyReaper::create();
	}
	if (strstr(name.c_str(), "EnemyLurk")){
		return EnemyLurk::create();
	}
	if (strstr(name.c_str(), "JellyFish")){
		return EnemyJellyFish::create();
	}
	if (strstr(name.c_str(), "RippleFish")){
		return EnemyRippleFish::create();
	}
	return nullptr;
}
