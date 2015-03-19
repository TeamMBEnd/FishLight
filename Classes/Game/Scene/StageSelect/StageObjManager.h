#ifndef STAGEOBJMANAGER_H
#define STAGEOBJMANAGER_H

#include "cocos2d.h"
#include <list>
class StageObj;

USING_NS_CC;

/*--------------------------------
ギミックの管理者
--------------------------------*/
class StageObjManager : public Node{
public:
	/*--------------------------------
	コンストラクタ
	--------------------------------*/
	StageObjManager();
	
	/*--------------------------------
	デストラクタ
	--------------------------------*/
	~StageObjManager();

	/*--------------------------------
	更新
	float deltatime フレーム
	--------------------------------*/
	void update(float deltatime);

	/*--------------------------------
	管理するオブジェクトの追加
	StageObj* obj
	--------------------------------*/
	void addObj(StageObj* obj);
	
	/*--------------------------------
	管理しているオブジェクトの削除
	StageObj* obj
	--------------------------------*/
	void deleteObj();

	StageObj* getGoal();

	/*--------------------------------
	生成マクロ
	--------------------------------*/
	CREATE_FUNC(StageObjManager);
private:
	/*--------------------------------
	ギミックを複数保存するコンテナ
	--------------------------------*/
	std::list<StageObj*> stageObjContainer;

};
#endif 