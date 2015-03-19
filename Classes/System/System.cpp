#include "System.h"

USING_NS_CC;

void System::updateKey(Node* node){

	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto lis = EventListenerKeyboard::create();

	lis->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event* event) {
		if (EventKeyboard::KeyCode::KEY_ESCAPE == keyCode){
			Director::getInstance()->end();
		}
	};

	dispatcher->addEventListenerWithSceneGraphPriority(lis, node);
}