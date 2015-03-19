#include "PauseLayer.h"
#include "Game/Util/Scene/Fade.h"
#include "Game/Scene/Title/TitleScene.h"
#include "Game/Scene/Main/MainLayer.h"

PauseLayer::PauseLayer()
{

}

PauseLayer::~PauseLayer()
{
	this->stopAllActions();
}

PauseLayer* PauseLayer::create( const cocos2d::Vec2& layerPos )
{
	auto inst = new PauseLayer();
	
	if ( inst && inst->init( layerPos ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

bool PauseLayer::init( const cocos2d::Vec2& layerPos )
{
	if ( !LayerColor::initWithColor( Color4B::BLACK ) )
	{
		return false;
	}
	
	this->setPosition( layerPos );
	this->setOpacity( 120 );
	
	auto singleTouchListener = EventListenerTouchOneByOne::create();
	singleTouchListener->setSwallowTouches( _swallowsTouches );
	
	singleTouchListener->onTouchBegan = [ & ]( Touch* touch, Event* event )
	{
		return true;
	};
	
	singleTouchListener->onTouchEnded = [ & ]( Touch* touch, Event* event )
	{
		
	};
	
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority( singleTouchListener, this );
	
	auto icon = Sprite::create( "Scene/Pause/Icon.png" );
	icon->setAnchorPoint( Vec2::ANCHOR_BOTTOM_LEFT );
	icon->setPosition( Vec2( 254, 540 ) );
	this->addChild( icon );
	
	auto continueCallback	= [ & ]( Ref* sender )
	{
		auto parent = static_cast< Scene* >( this->getParent() );
		parent->getPhysicsWorld()->setSpeed( 1.0f );
		this->removeFromParent();
	};
	
	auto retryCallback		= [ & ]( Ref* sender ) { Fade::Scene::transition( MainLayer::createScene(), 1.0f ); };
	auto retireCallback		= [ & ]( Ref* sender ) { Fade::Scene::transition( TitleScene::createScene(), 1.0f ); };
	
	putButton( "Continue_Normal.png",	"Continue_Active.png",	Vec2(  52, 116 ), continueCallback );
	// putButton( "Retry_Normal.png",		"Retry_Active.png",		Vec2( 426, 116 ), retryCallback );
	putButton( "Retire_Normal.png",		"Retire_Active.png",	Vec2( 868, 116 ), retireCallback );
	
	return true;
}

void PauseLayer::putButton( const std::string& normal, const std::string& active, const Vec2& pos, ButtonCallback callback )
{
	auto buttonImg = MenuItemImage::create( "Scene/Pause/" + normal, "Scene/Pause/" + active, callback );
	buttonImg->setAnchorPoint( Vec2::ANCHOR_BOTTOM_LEFT );
	buttonImg->setPosition( pos );
	
	auto buttonMenu = Menu::create( buttonImg, nullptr );
	buttonMenu->setPosition( Vec2::ZERO );
	this->addChild( buttonMenu );
}