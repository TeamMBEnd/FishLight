#ifndef WAVEMANAGER_H 
#define WAVEMANAGER_H

#include "Wave.h"
#include "cocos2d.h"

USING_NS_CC;
//namespace Wave{
	class WaveManager{
	public:
		WaveManager();

		static void create(NodeGrid* grid, float duration, const Size& gridSize, unsigned int waves, float amplitude);

		static void create(NodeGrid* grid, float duration, const Size& gridSize, unsigned int waves, float amplitude, bool horizontal, bool vertical);

		void setAmplitude(NodeGrid* node);

		void setValue(float value);

	private:
	
		void subAmp(Wave* wave,NodeGrid* node);
		void subAmp(Waves3D* wave, NodeGrid* node);

		void addAmp(Wave* wave, NodeGrid* node);
		void addAmp(Waves3D* wave, NodeGrid* node);

		void stop(NodeGrid* node, Wave* wave);
		void stop(NodeGrid* node,Waves3D* wave);

		float  value;

	};
//}
#endif