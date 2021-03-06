#ifndef ALPAHBLEND_H_
#define ALPAHBLEND_H_

#include "cocos2d.h"

USING_NS_CC;

class AlphaBlendFunc
{
public:
	AlphaBlendFunc();
	~AlphaBlendFunc();

	void setBlendFunc(GLenum src, GLenum dst);
	//合成
	Sprite* synthesis(Sprite *sprites);
	Sprite* synthesis(Sprite *a,Sprite *b);
	Sprite* synthesis(Sprite *a,Sprite *b,Sprite *c);

	//今回のゲーム用の合成
	void maskBlend(RenderTexture* texture, float deltaTime,Vec2 pos);
	void lightBlend(Sprite *sprite,RenderTexture* texture);


private:
	BlendFunc mBlendFunc;
	RenderTexture* mTexture;
	Sprite* mMask;

};

#endif