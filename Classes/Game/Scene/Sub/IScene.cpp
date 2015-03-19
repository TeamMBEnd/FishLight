#include "IScene.h"


IScene::IScene() :mSceneState(FADEIN)
{
	updateFunc[0] = &IScene::fadeIn;
	updateFunc[1] = &IScene::sceneMain;
	updateFunc[2] = &IScene::fadeOut;
	updateFunc[3] = nullptr;

}