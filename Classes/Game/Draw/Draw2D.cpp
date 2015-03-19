#include "Draw2D.h"

Draw2D::~Draw2D(){
	auto it = mDrawList.begin();
	auto end = mDrawList.end();
	for (; it != end;){
		delete (*it);
		(*it) = nullptr;
		it = mDrawList.erase(it);
	}
}

DrawNode* Draw2D::create(){
	mDrawNode = DrawNode::create();

	mDrawNode->setName("drawNode");

	BlendFunc blend;
	blend.src = GL_DST_COLOR;
	blend.dst = GL_ONE;

	mDrawNode->setBlendFunc(blend);

	return mDrawNode;
}

void Draw2D::addDrawList(DrawInfo* info){

	mDrawList.push_back(info);
}

void Draw2D::drawCircle(const Vec2* pos, float radius, Color4F color = Color4F(1.f, 1.f, 1.f, 1.f)){

	//スポットライト描画
	DrawInfo* info = new DrawInfo();
	info->AnimationTime = 0.f;						//描画時間
	info->time = 0;									//描画時間を初期化
	info->pos = pos;                                //タッチ位置
	info->radius =  radius;                         //円の大きさ(初期)
	info->color = color;							//色情報							
	info->maxRadius = radius;						//円の最大サイズ（一回描画なので特に意味はなし）

	addDrawList(info);
}

void Draw2D::circleAnimetion(const Vec2* pos, float AnimationTime, float MaxRadius, bool isfade, Color4F color){
	DrawInfo* info = new DrawInfo();
	info->AnimationTime = AnimationTime;						//描画時間
	info->time = 0;												//描画時間を初期化
	info->pos = pos;										    //タッチ位置
	info->radius = 0.f;											//円の大きさ(初期)
	info->color = color;										//色情報							
	info->maxRadius = MaxRadius;								//円の最大サイズ（一回描画なので特に意味はなし）
	if (isfade){
		info->color.a = 0.f;
	}
	addDrawList(info);
}

void Draw2D::circleAnimetion(const Vec2* pos, float AnimationTime, float MaxRadius, bool isfade, Color4F color,float startRadius){
	DrawInfo* info = new DrawInfo();
	info->AnimationTime = AnimationTime;						//描画時間
	info->time = 0;												//描画時間を初期化
	info->pos = pos;										    //タッチ位置
	info->radius = startRadius;											//円の大きさ(初期)
	info->color = color;										//色情報							
	info->maxRadius = MaxRadius;								//円の最大サイズ（一回描画なので特に意味はなし）
	if (isfade){
		info->color.a = 0.f;
	}
	addDrawList(info);
}


//描画
void Draw2D::draw(float at){
	//一旦描画されているスポットライトを削除
	mDrawNode->clear();

	//描画対象が追加されてないなら何もしない
	if (mDrawList.empty()) {
		return;
	}

	//イテレーター回すよ
	auto it = mDrawList.begin();

	for (; it != mDrawList.end();){
		mDrawNode->drawDot(*(*it)->pos, (*it)->radius , (*it)->color);
		(*it)->time+=at;
		if ((*it)->maxRadius > (*it)->radius){
			(*it)->radius += (*it)->maxRadius / 480;
		}
		else if ((*it)->color.a > 0){
			(*it)->color.a -= 0.05f;
			if ((*it)->color.a < 0){
				(*it)->color.a = 0.f;
			}
		}

		if ((*it)->AnimationTime <= (*it)->time){
			delete (*it);
			(*it) = nullptr;
			it = mDrawList.erase(it);
			continue;
		}
		++it;
	}
}