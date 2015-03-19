#include "Fade.h"

USING_NS_CC;

namespace Fade
{
	
namespace Scene
{
	// トランジションフェードを行うシーン変更
	void transition( cocos2d::Scene* nextScene, float duration, const Color3B& fadeColor )
	{
		auto scene = TransitionFade::create( duration, nextScene, fadeColor );
		Director::getInstance()->replaceScene( scene );
	}
}
	
}