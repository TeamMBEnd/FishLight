
#ifndef _STAGENUMBERWRITER_H_
#define _STAGENUMBERWRITER_H_

#include <string>
#include "cocos2d.h"

USING_NS_CC;

class StageNumberWriter{
public:
	
	StageNumberWriter();
	~StageNumberWriter();
		
	void writeStageNumber( const std::string &value);
	
};

#endif
