#include "Ripple.h"

namespace
{
	const int SINGLE_REFERENCE = 1;
}

// コンストラクタ
Ripple::Ripple()
	: mParticle( nullptr )
	, mRippleBody( nullptr )
	, mIsParticleEnd( false )
{
	// 参照カウンタを加算します
	this->retain();
}

// デストラクタ
Ripple::~Ripple()
{
	// 追加されている子ノードを解放します
	this->removeAllChildren();
	
	// 波紋用の物理構造を解放します
	mRippleBody->release();
}

// インスタンスの生成
Ripple* Ripple::create( const std::string& fileName, float scaleValue )
{
	auto inst = new Ripple();
	
	if ( inst && inst->init( fileName, scaleValue ) )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// 初期化
bool Ripple::init( const std::string& fileName, float scaleValue )
{
	// インスタンスを生成します
	mParticle	= ParticleSystemQuad::create( "Particle2dx/Physics/" + fileName + ".plist" );
	mRippleBody	= RippleBody::create( scaleValue );
	
	// 各パラメータを設定します
	mParticle->retain();
	mParticle->setName( fileName );
	mParticle->stopSystem();
	mParticle->setAutoRemoveOnFinish( true );
	mParticle->setAnchorPoint( Vec2::ANCHOR_MIDDLE );
	
	return true;
}

// 更新
void Ripple::update( float deltaTime )
{
	if ( mParticle->isRunning() )
	{
		// パーティクルが実行されている間のみ物理構造を追加します
		mRippleBody->createBody( mParticle, deltaTime );
		return;
	}
	
	if ( mParticle->getReferenceCount() == SINGLE_REFERENCE )
	{
		// パーティクルを解放し終了の合図を出します
		mParticle->release();
		mIsParticleEnd = true;
	}
}

// 波紋パーティクルの再生
void Ripple::playRipple( Node* parent, const Vec2& createPos )
{
	// パーティクルを再生して親ノードに追加します
	mParticle->resetSystem();
	mParticle->setPosition( createPos );
	parent->addChild( mParticle );
}

// 波紋パーティクルが終了したか否か
bool Ripple::isParticleEnd() const
{
	return mIsParticleEnd;
}