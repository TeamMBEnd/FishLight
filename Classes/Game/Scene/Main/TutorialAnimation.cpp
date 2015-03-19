#include "TutorialAnimation.h"

using  namespace Scenes;

TutorialAnimation::TutorialAnimation(){ }

TutorialAnimation::~TutorialAnimation(){ }


void TutorialAnimation::createAnimation(Sprite* parent){
	
	//矢印　追加
	createArrow(parent);

	//手　追加
	createHand(parent);
	
	//プレイヤー画像　追加
	createFish(parent);
}

void TutorialAnimation::createArrow(Sprite* parent){
	Sprite* key = Sprite::create("Scene/Main/MoveKey.png");

	key->setName("tutorialkey");
	key->setPosition(Vec2(parent->getContentSize() / 2));
	key->setRotation(-5);

	parent->addChild(key, 98);
}

void TutorialAnimation::createHand(Sprite* parent){
	Sprite* hand = Sprite::create("Scene/Main/MoveHand.png");
	hand->setName("tutorialhand");

	//Fish画像とうごくタイミングをずらす
	hand->setPosition(Vec2(150, 50));
	auto handSeq = Sequence::create(
		Sequence::create(MoveTo::create(3, Vec2(800, 150)),
		DelayTime::create(1.5f),
		CallFunc::create([hand]()
	{
		hand->setPosition(150, 50);
	}), nullptr), nullptr);

	RepeatForever* handRepeat = RepeatForever::create(handSeq);

	hand->runAction(handRepeat);

	parent->addChild(hand,100);
}

void TutorialAnimation::createFish(Sprite* parent){
	Sprite* model = Sprite::create("Scene/Main/Player.png");
	model->setName("tutorialmodel");

	//腕同様
	auto seq = Sequence::create(
		DelayTime::create(1.5f),
		Sequence::create(MoveTo::create(3, Vec2(800, 150)),
		CallFunc::create([model]()
	{
		model->setPosition(150, 50);
	}), nullptr), nullptr);
	RepeatForever* repeat = RepeatForever::create(seq);
	model->setPosition(Vec2(150, 50));
	model->setRotation(85);
	model->runAction(repeat);

	parent->addChild(model, 99);
}