#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include "cocos2d.h"
#include <list>
class Enemy;

USING_NS_CC;

/*--------------------------------
敵管理者
--------------------------------*/
class EnemyManager : public Node{
public:
	/*--------------------------------
	コンストラクタ
	--------------------------------*/
	EnemyManager();

	/*--------------------------------
	デストラクタ
	--------------------------------*/
	~EnemyManager();

	/*--------------------------------
	更新
	float deltatime フレーム
	--------------------------------*/
	void update(float deltatime, Vec2 targetPos);

	/*--------------------------------
	管理するオブジェクトの追加
	Enemy* obj 敵オブジェクト
	--------------------------------*/
	void addObj(Enemy* obj);

	/*--------------------------------
	管理しているオブジェクトの削除
	Enemy* obj 敵オブジェクト
	--------------------------------*/
	void deleteObj();

	/*--------------------------------
	生成マクロ
	--------------------------------*/
	CREATE_FUNC(EnemyManager);
private:
	/*--------------------------------
	敵を複数保存するコンテナ
	--------------------------------*/
	std::list<Enemy*> EnemyContainer;

};
#endif 