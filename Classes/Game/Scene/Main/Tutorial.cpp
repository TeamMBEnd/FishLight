#include"Tutorial.h"
#include "TutorialAnimation.h"
#include "Game/Object/Character/Player/Player.h"
#include "Game/Util/Animation/SpriteAnimation.h"

using namespace Scenes;

Sprite* Tutorial::createWindow(){

	Sprite* window = Sprite::create("Scene/Main/Bar.png");

	window->setName("tutorial");	
	
	window->setOpacity(0);
	window->runAction(FadeIn::create(2));

	//子ノードにアニメーションを追加
	TutorialAnimation r_tutorialAnimation;
	r_tutorialAnimation.createAnimation(window);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	window->setPosition(visibleSize.width / 2, visibleSize.height / 1.25f);

	return window;
}

void Tutorial::update(Layer* layer,Player* player){
	
	Vec2 visibleSize = Director::getInstance()->getVisibleSize();
	
	if (layer->getChildByName("Touch")){
		layer->getChildByName("Touch")->setPosition(player->getChildByName("PlayerSprite")->getPosition() - player->getChildByName("PlayerSprite")->getContentSize() / 1.5f);
	}

	if (player->getChildByName("PlayerSprite")->getPositionX() > visibleSize.x / 2){
		if ((Sprite*)layer->getChildByName("tutorial")->getOpacity() <= 0) return;

		if (!layer->getChildByName("tutorial")->getActionByTag(555)){
			auto tutorial = (Sprite*)layer->getChildByName("tutorial");
			auto tutofade = FadeOut::create(1.5f);
			tutofade->setTag(555);
			tutorial->runAction(tutofade);

			tutorial->getChildByName("tutorialkey")->runAction(FadeOut::create(1.5f));
			tutorial->getChildByName("tutorialhand")->runAction(FadeOut::create(1.5f));
			tutorial->getChildByName("tutorialmodel")->runAction(FadeOut::create(1.5f));
		}

		//　パラパラ漫画
		if (!layer->getChildByName("Touch")){
			Util::SpriteAnimation spriteAnimation("Scene/Main/");
			auto r_animationSprite = spriteAnimation.create("Touch", 10, 0.5f, true, true);

			r_animationSprite->setOpacity(0);
			auto fade = FadeIn::create(1.f);
			r_animationSprite->runAction(fade);
			r_animationSprite->setAnchorPoint(Vec2(0, 0));
			layer->addChild(r_animationSprite);
		}
	}
}