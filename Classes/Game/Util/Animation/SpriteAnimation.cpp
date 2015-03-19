#include "SpriteAnimation.h"

using namespace Util;

SpriteAnimation::SpriteAnimation(const std::string& path){
	m_ResourcePath = path;
}


Sprite* SpriteAnimation::create(const std::string& spriteName, const int count, const float delay, const bool restart, const bool repeat){
	
	std::string r_spriteName = spriteName;

	Sprite* r_firstSprite = Sprite::create(m_ResourcePath + r_spriteName + "1.png");
	r_firstSprite->setName(spriteName);

	auto r_animation = Animation::create();
	for (int i = 2; i <= count; ++i){
		r_animation->addSpriteFrameWithFileName(m_ResourcePath + r_spriteName + std::to_string(i) + ".png");
	}
	r_animation->setRestoreOriginalFrame(restart);
	r_animation->setDelayPerUnit(delay);

	//繰り返すなら
	if (repeat){
		Animate* animate = Animate::create(r_animation);
		RepeatForever* repeatTrue = RepeatForever::create(animate);
		r_firstSprite->runAction(repeatTrue);
	}

	return r_firstSprite;
}

void SpriteAnimation::setResourcesPath(const std::string& path){
	m_ResourcePath = path;
}