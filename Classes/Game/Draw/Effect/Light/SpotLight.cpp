#include "SpotLight.h"
#include "Game/Draw/Draw2D.h"

namespace SpotLight{
	void lightAnimation(const Vec2* pos, float AnimationTime, float MaxRadius, bool isfade){
		float radius = 0;
		float alpha = 0.1f;
		for (float i = 0.1f; alpha < 1.25f; alpha += 0.04f){
			DRAW2D->circleAnimetion(pos, AnimationTime, radius, isfade, Color4F(1, 1, 1, i));
			radius += 16.f;
		}
	}

	void lightDraw(const Vec2* pos,float _radius){
		
		//DRAW2D->DrawCircle(pos, _radius, Color4F(1, 1, 1, 1.f));
		//DRAW2D->DrawCircle(pos, _radius, Color4F(1, 1, 1, 0.5f));
		float radius =10.f;
		float alpha = 0.1f;
		for (float i = 0.1f; alpha < 1.75f; alpha += 0.05f){
			DRAW2D->drawCircle(pos,  radius, Color4F(1, 1, 1, i));
			radius += 4.0f;
		}
	}

}