#ifndef STAGEMANAGER_H
#define STAGEMANAGER_H

#include "cocos2d.h"
#include <vector>

USING_NS_CC;

class EnemyManager;
class StageObjManager;
class SeaFireFlyManager;
class StageObj;

/*--------------------------------
ステージ全体の管理者
--------------------------------*/
class StageManager : public Node{
public:
	/*--------------------------------
	コンストラクタ
	--------------------------------*/
	StageManager();

	/*--------------------------------
	デストラクタ
	--------------------------------*/
	~StageManager();

	/*--------------------------------
	管理するマネージャーの登録
	--------------------------------*/
	void setManager(EnemyManager* em, StageObjManager* som,SeaFireFlyManager* sem);

	/*--------------------------------
	更新
	--------------------------------*/
	void update(float deltatime);
	void enemyMove(float deltatime, Vec2 targetPos);
	void touchUpdate(Point touchPos, Vec2 layerPos);
	void flyMove(Vec2 targetPos, Vec2 targetVel, float dt);
	bool flyTouchEnd(Point endPos);
	StageObj* getGoal();
	int getSeaFireFly();

	SeaFireFlyManager* getSeaFireFlyManager();

	/*--------------------------------
	生成マクロ
	--------------------------------*/
	CREATE_FUNC(StageManager);
private:
	EnemyManager* em;
	StageObjManager* som;
	SeaFireFlyManager* sfm;
};
#endif 