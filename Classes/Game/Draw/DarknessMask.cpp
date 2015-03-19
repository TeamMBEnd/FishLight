#include "DarknessMask.h"

namespace DarknessMask{
	
	LayerColor* create(Color4B color, Size size){
		//BlendFunc a = { GL_ZERO, GL_SRC_COLOR };
		auto mask = LayerColor::create(color, size.width, size.height);

		mask->setName("Dark");
		//mask->setBlendFunc(a);
		return mask;
	}

	void destroy(Layer* layer){

		layer->removeChildByName("Dark");

	}
}
