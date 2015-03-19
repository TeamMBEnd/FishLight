#include "AlphaBlend.h"
#include "Game/Draw/Effect/Light/LightManager.h"


AlphaBlendFunc::AlphaBlendFunc()
{
	mMask = Sprite::create("stage/DarkMask.png");
	mMask->retain();
}


AlphaBlendFunc::~AlphaBlendFunc()
{
	mMask->release();
	delete mTexture;
	mTexture = nullptr;
}

void AlphaBlendFunc::setBlendFunc(GLenum src, GLenum dst){
	
	mBlendFunc.src = src;
	mBlendFunc.dst = dst;

}

Sprite* AlphaBlendFunc::synthesis(Sprite *a, Sprite *b){
	Size win_size = Director::getInstance()->getWinSize();

	RenderTexture* texture = RenderTexture::create(win_size.width, win_size.height);
	b->setBlendFunc(mBlendFunc);


	texture->beginWithClear(1, 1, 1, 1);
	{	
		a->visit();
		b->visit();
		
	}
	texture->end();

	return texture->getSprite();
}


Sprite* AlphaBlendFunc::synthesis(Sprite *a, Sprite *b, Sprite *c){

	return nullptr;
}


Sprite* AlphaBlendFunc::synthesis(Sprite *sprites){

	return nullptr;
}

void AlphaBlendFunc::maskBlend(RenderTexture* texture, float deltaTime, Vec2 pos){

	//Size win_size = Director::getInstance()->getWinSize();
	setBlendFunc(GL_DST_COLOR,GL_ONE);
	//mMask->setPosition(win_size.width / 2 , win_size.height / 2 );
	//texture->beginWithClear(1,1,1,1);
	{
		//mMask->visit();
		LightManager::getInstance()->draw(mBlendFunc,deltaTime,pos);
	}
	//texture->end();

}

void AlphaBlendFunc::lightBlend(Sprite *mask, RenderTexture* texture){
	Size size = Director::getInstance()->getWinSize();

	setBlendFunc(GL_ZERO, GL_SRC_COLOR);

	mask->setPosition(size.width / 2, size.height / 2);
	texture->beginWithClear(1, 1, 1, 1);
	{
		mask->visit();
	}
	texture->end();
		
	texture->getSprite()->setBlendFunc(mBlendFunc);
}