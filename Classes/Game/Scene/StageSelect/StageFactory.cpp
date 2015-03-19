#include "StageFactory.h"
#include "Game/Object/Stage/Stone.h"
#include "Game/Object/Stage/SmallStone.h"
#include "Game/Object/Stage/BigStone.h"
#include "Game/Object/Stage/Goal.h"
#include "Game/Object/Stage/StageSeaFly.h"
#include "Game/Object/Stage/Alga.h"
#include "Game/Object/Stage/Whirlpool.h"

//マクロ定義
#define INSERT(KEY, VALUE) objContainer.insert(std::make_pair(KEY,VALUE));

StageFactory::StageFactory(){
	init();
}

StageFactory::~StageFactory(){
	auto ite = objContainer.begin();
	auto end = objContainer.end();

	while (ite != end)
	{
		CC_SAFE_RELEASE( ite->second );
		++ite;
	}

	objContainer.clear();

}

StageObj* StageFactory::order(const std::string &name){

	return  StageFactory::create(name);
}

void StageFactory::init(){


	objContainer.clear();

	INSERT("StoneBig.png", new BigStone());
	INSERT("StoneSmall.png", new SmallStone());
	INSERT("StoneNormal.png", new Stone());
	INSERT("Goal.png", new Goal());
	INSERT("Alga.png", new Alga());
	INSERT("Whirlpool.png", new Whirlpool());
}


StageObj* StageFactory::create(std::string name){
	
	if (!objContainer[name]) return nullptr;

	return objContainer[name]->clone();
}
