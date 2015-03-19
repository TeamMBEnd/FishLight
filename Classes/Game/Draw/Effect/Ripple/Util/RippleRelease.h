#ifndef _RIPPLE_RELEASE_H_
#define _RIPPLE_RELEASE_H_

#include "../Base/Ripple.h"

/**
	@class	：	RippleRelease
	@brief	：	波紋クラス解放用の関数オブジェクト
	@author	：	利川聖太
 */
class RippleRelease
{
	
public:
	
	/**
		@brief	波紋クラスを解放するか否か
	 
		@param	ripple	波紋クラス
		@return			波紋クラスを解放するか否か
	 */
	bool operator () ( Ripple* ripple )
	{
		if ( ripple->isParticleEnd() )
		{
			CC_SAFE_RELEASE( ripple );
			return true;
		}
		
		return false;
	}
};

#endif