#include "ResultScoreAnimation.h"

// コンストラクタ
ResultScoreAnimation::ResultScoreAnimation( const ResultData& data )
{
	// メンバ変数の初期化
	mResultData = data;
}

// インスタンスの生成
ResultScoreAnimation* ResultScoreAnimation::create( const ResultData& data )
{
	auto inst = new ResultScoreAnimation( data );
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// 初期化
bool ResultScoreAnimation::init()
{
	// アニメーションの再生
	playAnimation();
	
	return true;
}

// アニメーションの再生
void ResultScoreAnimation::playAnimation()
{
	// テキストを遅延させて描画します
	putTextSprite( "TextStageClear.png",	Point( 230, 550 ), 1.5f,	TAG_CLEAR			);
	putTextSprite( "TextFind.png",			Point(  86, 374 ), 2.5f,	TAG_FIND			);
	putTextSprite( "TextAnimals.png",		Point( 754, 378 ), 3.0f,	TAG_ANIMALS_TOP		);
	//putTextSprite( "TextOverlooked.png",	Point(  86, 264 ), 3.5f,	TAG_OVERLOOKED		);
	//putTextSprite( "TextAnimals.png",		Point( 754, 266 ), 4.0f,	TAG_ANIMALS_MIDDLE	);
	putTextSprite( "TextLost.png",			Point(  86, 146 ), 4.5f,	TAG_LOST			);
	putTextSprite( "TextAnimals.png",		Point( 754, 152 ), 5.0f,	TAG_ANIMALS_DOWN	);
	
	// ナンバーを遅延させて描画します
	putNumberSprite( Point( 710, 380 ),	mResultData.findSFF,		3.0f,	TAG_NUMBER_TOP		);
	//putNumberSprite( Point( 710, 268 ),	mResultData.overlookedSFF,	4.0f,	TAG_NUMBER_MIDDLE	);
	putNumberSprite( Point( 710, 154 ),	mResultData.lostSFF,		5.0f,	TAG_NUMBER_DOWN		);
}

// 現在行われているアクションのスキップ
void ResultScoreAnimation::skipAnimation()
{
	for ( auto child : this->getChildren() )
	{
		// シークエンスアクションを取得します
		auto act = ( Sequence* )child->getActionByTag( child->getTag() );
		
		// アクションが実行されている場合のみスキップします
		if ( !act ) { continue; }
		act->setDuration( 0.0f );
	}
}

// テキストスプライトの設置
void ResultScoreAnimation::putTextSprite( const std::string& fileName, const Point& drawPos, float delay, SpriteTag tag )
{
	auto textSprite	= Sprite::create( "Scene/Result/" + fileName );
	auto seqAction	= Sequence::create( DelayTime::create( delay ),
									    FadeIn::create( 2.0f ),
									    CallFunc::create( [ & ]() { mIsAnimation = true; } ),
									    nullptr );
	
	textSprite->setTag( tag );
	seqAction->setTag( tag );
	textSprite->setOpacity( 0 );
	textSprite->setAnchorPoint( Point::ANCHOR_BOTTOM_LEFT );
	textSprite->setPosition( drawPos );
	textSprite->runAction( seqAction );
	this->addChild( textSprite );
}

// ナンバースプライトの設置
void ResultScoreAnimation::putNumberSprite( const Point& drawPos, u_int number, float delay, SpriteTag tag )
{
	auto numberSprite	= Sprite::create( "Scene/Result/Numbers.png" );
	auto seqAction		= Sequence::create( DelayTime::create( delay ),
										    FadeIn::create( 2.0f ),
										    CallFunc::create( [ & ]() { mIsAnimation = true; } ),
										    nullptr );
	auto frameSize		= Point( 32, 52 );
	
	numberSprite->setTag( tag );
	seqAction->setTag( tag );
	numberSprite->setOpacity( 0 );
	numberSprite->setAnchorPoint( Point::ANCHOR_BOTTOM_LEFT );
	numberSprite->setTextureRect( Rect( frameSize.x * ( number ), frameSize.y * 0, frameSize.x, frameSize.y ) );
	numberSprite->setPosition( drawPos );
	numberSprite->runAction( seqAction );
	this->addChild( numberSprite );
}