#include "RippleBody.h"

// コンストラクタ
RippleBody::RippleBody( float scaleValue )
	: mMaterial( PHYSICSBODY_MATERIAL_DEFAULT )
	, mBodyScale( 0.f )
	, mScaleValue( scaleValue )
{
	// 参照カウンタを加算します
	this->retain();
	
	// 物質特徴を初期化します( 密度, 反発係数, 摩擦係数 )
	mMaterial.density		= 0.f;
	mMaterial.restitution	= 0.f;
	mMaterial.friction		= 0.f;
}

// インスタンスの生成
RippleBody* RippleBody::create( float scaleValue )
{
	auto inst = new RippleBody( scaleValue );
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// 物理構造の生成
void RippleBody::createBody( ParticleSystemQuad* particle, float deltaTime )
{
	// 拡大値を加算します
	mBodyScale += ( mScaleValue * deltaTime * 100.f );
	
	// 物理構造を生成します
	auto body = PhysicsBody::createCircle( mBodyScale, mMaterial );
	
	// 各パラメータを設定します
	body->setDynamic( true );
	body->setRotationEnable( false );
	body->setContactTestBitmask( true );
	body->setCollisionBitmask( false );
	
	// 波紋パーティクルに物理構造を追加します
	particle->setPhysicsBody( body );
}