#include "ResultStarAnimation.h"

// 初期化
bool ResultStarAnimation::init()
{
	if ( !Sprite::initWithFile( "Scene/Result/CompleteStar.png" ) )
	{
		// スプライトを初期化します
		return false;
	}
	
	// アニメーションの再生
	playAnimation();
	
	return true;
}

// アニメーションの再生
void ResultStarAnimation::playAnimation()
{
	// 各パラメータを設定します
	this->setAnchorPoint( Vec2::ANCHOR_MIDDLE );
	this->setPosition( Vec2( -100, 610 ) );
	
	// 回転, ジャンプ, コールバック, シークエンスアクションを用意します
	auto rotJumpAction	= Spawn::create( RotateTo::create( 4.5f, 1460 ),
										 JumpBy::create( 4.5f, Vec2( 1120, 0 ), -260, 5 ),
										 nullptr );
	auto callFuncAction	= CallFunc::create( [ & ]() { mIsAnimation = true; } );
	auto seqAction		= Sequence::create( rotJumpAction, callFuncAction, nullptr );
	
	// 後で停止するのでタグを設定します
	seqAction->setTag( ActionTag::TAG_SEQ_ACTION );
	
	// アクションを実行します
	this->runAction( seqAction );
}

// アニメーションのスキップ
void ResultStarAnimation::skipAnimation()
{
	// シークエンスアクションを取得します
	auto seqAction = ( Sequence* )this->getActionByTag( ActionTag::TAG_SEQ_ACTION );
	
	// アクションが実行されている場合のみスキップします
	if ( !seqAction ) { return; }
	seqAction->setDuration( 0.0f );
}