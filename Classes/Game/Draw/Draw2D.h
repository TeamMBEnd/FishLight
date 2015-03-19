#ifndef  DRAW2D_H
#define  DRAW2D_H

#define DRAW2D Draw2D::getInstance()

#include "cocos2d.h"
#include <vector>

USING_NS_CC;

/*************************************************
	円を描画（アニメーション描画）するための構造体
*************************************************/
struct DrawInfo
{
	const Vec2* pos;
	float time;
	float AnimationTime;
	float radius;
	float maxRadius;
	Color4F color;
};

/**************************************************
　円や四角を描画するためのクラス
 （いまはスポットライトを描画するためだけのクラス）
  のちのち四角だけ描画などに対応させていくと思う
**************************************************/
class Draw2D{
public:
	~Draw2D();

	//DrawNode生成
	DrawNode* create();

	//描画対象追加
	void addDrawList(DrawInfo* info);

	void circleAnimetion(const Vec2* pos, float animationTime, float maxRadius, bool isfade, Color4F color = Color4F(1.f, 1.f, 1.f, 1.f));

	void circleAnimetion(const Vec2* pos, float nimationTime, float maxRadius, bool isfade, Color4F color,float startRadius);

	void drawCircle(const Vec2* pos, float radius, Color4F color);

	//描画
	void draw(float at);

	static Draw2D* getInstance();


private:
	typedef std::list<DrawInfo*> DrawList;

	//シングルトンにするよ～
	Draw2D():mDrawNode(nullptr){}
	Draw2D(const Draw2D&);
	Draw2D& operator=(const Draw2D&);
	DrawList mDrawList;
	DrawNode* mDrawNode;

};

inline Draw2D* Draw2D::getInstance(){
	static Draw2D instance;
	return &instance;
}
#endif