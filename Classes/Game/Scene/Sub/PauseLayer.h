#ifndef _PAUSE_LAYER_H_
#define _PAUSE_LAYER_H_

#include "cocos2d.h"

USING_NS_CC;

class PauseLayer : public LayerColor
{
	
public:
	
	PauseLayer();
	
	~PauseLayer();
	
	static PauseLayer* create( const Vec2& layerPos );
	
	bool init( const Vec2& layerPos );
	
private:
	
	typedef std::function< void( Ref* ) > ButtonCallback;
	
	void putButton( const std::string& normal, const std::string& active, const Vec2& pos, ButtonCallback callback );
};

#endif