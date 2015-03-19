#ifndef _SEAFIREFLYMANAGER_H_
#define _SEAFIREFLYMANAGER_H_

#include <list>


#include "SeaFireFly.h"
#include "System/Timer.h"
#include "FollowPositionManager.h"
#include "Game/Scene/Result/Support/ResultData.h"


class SeaFireFlyManager : public Node
{
public:
	/* コンストラクタ */
	SeaFireFlyManager();
	/* デストラクタ */
	~SeaFireFlyManager();

	/**********************************

	初期化処理

	***********************************/
	bool init();

	/***********************************
	
	更新

	@param targetPos : 敵の座標

	*************************************/
	void update(Vec2 targetPos, Vec2 targetVel,float dt);


	/************************************
	
	追加

	@param instance : SeaFireFlyのインスタンス
	@param layer	: 画像を追加するレイヤー
	@param position : 初期座標
	@param state	: 初期状態

	**************************************/
	void add(Node* node,SeaFireFly* instance, Vec2 position,State state);

	/****************************************
	
	画面がタッチされた時の処理

	*****************************************/
	void touch(Point touchPos, Vec2 layerPos);


	/******************************************
	
	画面から指が離されたとき
	
	戻り値　:　ウミホタルが飛ばす条件が
			   整ってればtrue,ダメならfalse

	******************************************/
	bool touchEnd(Point endPos);

	/*****************************************
	
	コンテナの中の全要素を削除

	******************************************/
	void cleanUp();


	/*******************************************
	
	Follow状態のSeaFireFlyがいるかどうかのチェック

	*********************************************/
	bool containerCheck();
	
	/*******************************************
	 
	 生きているウミホタルの数
	 
	 *********************************************/
	float aliveSeaFireFly();

	/*********************************************
	
	クリア時にウミホタルが何匹いるかのチェック

	*********************************************/
	ResultData seaFireFlyCheck();

	/*********************************************
	
	失った数カウンター

	**********************************************/
	void lostCounter(SeaFireFly* seaFireFly);

	bool isParfect();

	CREATE_FUNC(SeaFireFlyManager);
private:
	typedef std::list<SeaFireFly*> SeaFireFlyContainer;
	SeaFireFlyContainer mContainer;
	MyTimer mTimer;
	int lostSeaFireFly;
};

#endif