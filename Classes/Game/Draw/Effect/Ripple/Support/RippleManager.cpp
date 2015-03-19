#include "RippleManager.h"
#include "RippleFactory.h"
#include "Game/Util/Release/ReleaseContainer.h"
#include "../Util/RippleRelease.h"

// コンストラクタ
RippleManager::RippleManager()
{
	// 参照カウンタを加算します
	this->retain();
	
	// 波紋生成クラスを生成し、自身に追加します
	auto factory = RippleFactory::create();
	factory->setName( "factory" );
	this->addChild( factory );
	
	// リストの解放
	ReleaseContainer::cleanList( mRippleList );
}

// デストラクタ
RippleManager::~RippleManager()
{
	// リストの解放
	ReleaseContainer::cleanList( mRippleList );
	
	// 追加されている子ノードを解放します
	this->removeAllChildren();
}

// 更新
void RippleManager::update( float deltaTime )
{
	std::for_each( mRippleList.begin(), mRippleList.end(), [ deltaTime ]( Ripple* ripple )
	{
		// 波紋クラスの更新
		ripple->update( deltaTime );
	} );
	
	// 波紋クラスの解放確認を行います
	mRippleList.remove_if( RippleRelease() );
}

// 波紋パーティクルの再生
void RippleManager::playRipple( Node* parent, RippleTag tag, const Vec2& createPos )
{
	// 波紋クラスのインスタンスを生成します
	auto factory	= ( RippleFactory* )this->getChildByName( "factory" );
	auto ripple		= factory->createRipple( tag );
	
	// 波紋パーティクルを再生し、リストに追加します
	ripple->playRipple( parent, createPos );
	mRippleList.push_back( ripple );
}

// 再生中の波紋があるか否か
bool RippleManager::isEmpty() const
{
	return mRippleList.empty();
}