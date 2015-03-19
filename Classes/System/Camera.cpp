#include "Camera.h"


#include "Camera.h"

ActionCamera* MyCamera::create(){
	//camera = new ActionCamera();

	return camera;
}

void MyCamera::addTarget(Node* node){
	camera->setTarget(node);
}

void MyCamera::setEye(float x, float y, float z){
	auto eye = camera->getEye();
	eye = Vec3(x, 0, 10);
	camera->setEye(eye);
	camera->setCenter(Vec3(x, 0, 0));
}




////namespace CAMERA{
////	void move(Layer* layer){
////
////		auto p = layer->getChildByTag(1);
////
////		layer->getPhysicsBody()->setVelocity(p->getPhysicsBody()->getVelocity()*-0.98);
////
////		Vec2 layerPos = layer->getPosition();
////
////		StagePos = Vec4(0 - layerPos.x, 0 - layerPos.y, layer->getContentSize().width - layerPos.x, layer->getContentSize().height - layerPos.y);
////	}
////}
