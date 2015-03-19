#include "RippleFactory.h"
#include "Game/Util/Release/DeleteContainer.h"

// コンストラクタ
RippleFactory::RippleFactory()
{
	// コンテナの初期化
	initContainer();
}

// デストラクタ
RippleFactory::~RippleFactory()
{
	// コンテナの解放
	DeleteContainer::cleanMap( mParamContainer );
}

// 波紋のインスタンスの生成
Ripple* RippleFactory::createRipple( RippleTag tag )
{
	// コンテナの要素を使用し、波紋クラスを生成します
	auto fileName	= mParamContainer[ tag ]->fileName;
	auto scaleValue	= mParamContainer[ tag ]->scaleValue;
	auto ripple		= Ripple::create( fileName, scaleValue );
	
	// インスタンスを返却します
	return ripple;
}

// コンテナの初期化
void RippleFactory::initContainer()
{
	// コンテナの解放
	DeleteContainer::cleanMap( mParamContainer );
	
	// 要素の挿入
	insert( RippleTag::TAG_SEAFIREFLY,	"RippleSeaFireFly",	0.25f );
	insert( RippleTag::TAG_PLAYER,		"RipplePlayer",		0.30f );
	insert( RippleTag::TAG_ATTACK,		"RippleAttack",		0.40f );
	insert( RippleTag::TAG_GIMMICK,		"RippleGimmick",	0.31f );
}

// 要素の挿入
void RippleFactory::insert( RippleTag tag, const std::string& fileName, float scaleValue )
{
	auto param			= new RippleParameter();
	param->fileName		= fileName;
	param->scaleValue	= scaleValue;
	mParamContainer.insert( std::make_pair( tag, param ) );
}