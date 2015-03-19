#ifndef CAMERA_H
#define CAMERA_H

#include "cocos2d.h"

USING_NS_CC;

//カメラクラス
//まだ実装内容が微妙なので使わないで

class MyCamera{
public:
	~MyCamera(){}
	//カメラは
	static MyCamera* GetInstance();

	ActionCamera* create();

	//ターゲットの追加（をしたいなぁ）
	//正確には上書き
	void addTarget(Node* node);

	//カメラ位置設定
	void setEye(float x,float y, float z);
	

private:
	MyCamera(){}
	MyCamera(const MyCamera&);
	MyCamera& operator=(const MyCamera&);
	ActionCamera* camera;
};

inline MyCamera* MyCamera::GetInstance(){
	static MyCamera instance;
	return &instance;
}
#endif