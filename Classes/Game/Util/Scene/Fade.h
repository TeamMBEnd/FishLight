#ifndef _FADE_H_
#define _FADE_H_

#include "cocos2d.h"

/**
	@namespace	：	Fade
	@brief		：	フェード用名前空間
	@author		：	利川聖太
 */
namespace Fade
{

namespace Scene
{
	/**
		@brief	トランジションフェードを行うシーン変更
	 
		@param	nextScene	次のシーン
		@param	duration	フェードを行う時間
		@param	fadeColor	フェードを行う色( デフォルトでは黒色 )
	 */
	void transition( cocos2d::Scene* nextScene, float duration, const cocos2d::Color3B& fadeColor = cocos2d::Color3B::BLACK );
}

}

#endif