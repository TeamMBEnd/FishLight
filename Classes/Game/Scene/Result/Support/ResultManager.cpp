#include "ResultManager.h"
#include "Game/Scene/Title/TitleScene.h"
#include "Game/Util/Scene/Fade.h"
#include "Game/Util/FileIO/FileWriter.h"
#include "Game/Util/DeterminedStage.h"
#include "Game/Scene/Direction/DirectionScene.h"


// コンストラクタ
ResultManager::ResultManager( const ResultData& data )
	: mScoreAnimation( ResultScoreAnimation::create( data ) )
	, mStarAnimation( ResultStarAnimation::create() )
	, mCurrentFuncTag( FuncTag::TAG_SKIP_SPRITE )
	, mResultData( data )
{
	
}

// デストラクタ
ResultManager::~ResultManager()
{
	// Debug
	CCLOG( "ResultManager : %s", __FUNCTION__ );
}

// インスタンスの生成
ResultManager* ResultManager::create( const ResultData& data )
{
	auto inst = new ResultManager( data );
	
	if ( inst && inst->init() )
	{
		inst->autorelease();
		return inst;
	}
	
	CC_SAFE_DELETE( inst );
	return nullptr;
}

// 初期化
bool ResultManager::init()
{
	// スコア描画アニメーションクラスを追加します
	this->addChild( mScoreAnimation, 1 );
	
	// 関数ラッパーの初期化
	initFunc();
	
	return true;
}

// タッチ時のアクション
void ResultManager::touchAction()
{
	// 関数ラッパーがラップしている関数を呼び出します
	mTouchFuncs[ mCurrentFuncTag ]();
}

// 関数ラッパーの初期化
void ResultManager::initFunc()
{
	auto scoreSkip = [ & ]()
	{
		mScoreAnimation->skipAnimation();
		
		if (DeterminedStage::stageNum < 6){
			DeterminedStage::stageNum++;
		}

		if ( mResultData.isPerfect )
		{
			this->addChild( mStarAnimation, 0 );
			mCurrentFuncTag = FuncTag::TAG_SKIP_STAR;
			FileWriter fr;
			fr.writeBoolean( DeterminedStage::stageName, true );
			DeterminedStage::determinedStageFailePath = "";
			return;
		}
		
		mCurrentFuncTag = FuncTag::TAG_SCENE_CHANGE;

	};
	
	auto starSkip = [ & ]()
	{
		if ( mStarAnimation->isAnimation() )
		{
			mCurrentFuncTag = FuncTag::TAG_SCENE_CHANGE;
			this->touchAction();
			return;
		}
		
		mStarAnimation->skipAnimation();
		mCurrentFuncTag = FuncTag::TAG_SCENE_CHANGE;
	};
	
	auto sceneChange = [&]()
	{
		if (DeterminedStage::stageNum < 6){
			DeterminedStage::stageName = "stage2";
			Fade::Scene::transition(DirectionScene::createScene(), 1.0f);
			return;

		}
		
		DeterminedStage::stageNum = 0;
		Fade::Scene::transition(TitleScene::createScene(), 1.0f);
		
	};
	
	mTouchFuncs[ FuncTag::TAG_SKIP_SPRITE ]		= scoreSkip;
	mTouchFuncs[ FuncTag::TAG_SKIP_STAR ]		= starSkip;
	mTouchFuncs[ FuncTag::TAG_SCENE_CHANGE ]	= sceneChange;
}
