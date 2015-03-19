#include "ResultLayer.h"
#include "Game/Util/Collision/CollisionListener.h"

// コンストラクタ
ResultLayer::ResultLayer( const ResultData& data, const Vec2& layerPos )
	: mResultManager( ResultManager::create( data ) )
{
	mRipple = RippleManager::create();

	auto screenSize = Vec2( 1280, 780 );
	auto allSize = Vec2( 6400, 5376 );
	this->setPosition( -layerPos );
}

// デストラクタ
ResultLayer::~ResultLayer()
{
	// Debug
	CCLOG( "ResultLayer : %s", __FUNCTION__ );
	
	mRipple->release();
}

// インスタンスの生成
ResultLayer* ResultLayer::create( const ResultData& data, const Vec2& layerPos )
{
	auto inst = new ResultLayer( data, layerPos );
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

Scene* ResultLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = ResultLayer::create( ResultData( 1, 2, 3, true ), Vec2::ZERO );
	
	scene->addChild( layer );
	
	return scene;
}

// 初期化
bool ResultLayer::init()
{
	if ( !LayerColor::initWithColor( Color4B::BLACK ) )
	{
		// 基底クラスの初期化が終了していない場合は終了します
		return false;
	}

	this->setOpacity(230);
	
	// 衝突検知リスナを追加します
	auto collisionListener = CollisionListener::create();
	this->addChild( collisionListener );
	
	// リザルト管理者を追加します
	this->addChild( mResultManager );
	
	// シングルタッチリスナを生成します
	auto singleTouchListener = EventListenerTouchOneByOne::create();
	singleTouchListener->setSwallowTouches( _swallowsTouches );
	
	// タッチ開始時のコールバック関数
	singleTouchListener->onTouchBegan = [ & ]( Touch* touch, Event* event )
	{
		// mRipple->playRipple( this, RippleTag::TAG_GIMMICK, touch->getLocation() );
		
		return true;
	};
	
	// タッチ終了時のコールバック関数
	singleTouchListener->onTouchEnded = [ & ]( Touch* touch, Event* event )
	{
		mResultManager->touchAction();
	};
	
	// イベントディスパッチャに登録します
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority( singleTouchListener, this );
	
	return true;
}