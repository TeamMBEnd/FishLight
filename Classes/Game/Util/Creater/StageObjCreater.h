#ifndef STAGEOBJCREATER_H
#define STAGEOBJCREATER_H

#include "Game/Scene/StageSelect/StageObjManager.h"
#include "Game/Util/FileIO/ReadData.h"
#include <vector>

typedef std::vector< ReadData >	StageDataVector;

namespace StageCreater{

	class StageObjCreater{
	public:
		StageObjManager* create(StageDataVector data);
	};
}
#endif