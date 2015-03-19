#include "WaveManager.h"
#include "Wave.h"

#define SEQUENCE 11
#define WAVE 12 
#define WAVE3D 13


WaveManager::WaveManager() :value(0){
}

void WaveManager::create(NodeGrid* grid, float duration, const Size& gridSize, unsigned int waves, float amplitude, bool horizontal, bool vertical){

	auto actWave = Wave::create(duration, gridSize, waves, amplitude, horizontal, vertical);

	actWave->setTag(WAVE);

	grid->runAction(actWave);
}

void WaveManager::create(NodeGrid* grid, float duration, const Size& gridSize, unsigned int waves, float amplitude){
	
	auto actWave = Waves3D::create(duration, gridSize, waves, amplitude);

	actWave->setTag(WAVE3D);

	grid->runAction(actWave);
}

void WaveManager::setAmplitude(NodeGrid* node){
		
	Waves3D* wave3d = (Waves3D*)node->getActionByTag(WAVE3D);

	if (!wave3d){
		Wave* wave = (Wave*)node->getActionByTag(WAVE);
		if (!wave) {
			return;
		}

		subAmp(wave, node);
		addAmp(wave, node);

		return;
	}
	subAmp(wave3d, node);
	addAmp(wave3d, node);
}

void WaveManager::subAmp(Wave* wave, NodeGrid* node){
	if (wave && wave->getAmplitude() > 0){
		float amp = wave->getAmplitude();

		wave->setAmplitude(amp - value);

		if (wave->getAmplitude() < 0){
			stop(node, wave);
		}
		return;
	}
}

void WaveManager::addAmp(Wave* wave, NodeGrid* node){
	if (wave && wave->getAmplitude() < 0){
		float amp = wave->getAmplitude();

		wave->setAmplitude(amp + value);

		if (wave->getAmplitude() > 0){
			stop(node, wave);
		}
	}
}

void WaveManager::subAmp(Waves3D* wave, NodeGrid* node){
	if (wave && wave->getAmplitude() > 0){
		float amp = wave->getAmplitude();

		wave->setAmplitude(amp - value);

		if (wave->getAmplitude() < 0){
			stop(node, wave);
		}
		return;
	}
}

void WaveManager::addAmp(Waves3D* wave, NodeGrid* node){
	if (wave && wave->getAmplitude() < 0){
		float amp = wave->getAmplitude();

		wave->setAmplitude(amp + value);

		if (wave->getAmplitude() > 0){
			stop(node, wave);
		}
	}
}

void WaveManager::setValue(float _value){
	value = _value;
}

void WaveManager::stop(NodeGrid* node,Wave* wave){
	node->stopAction(wave);
	auto endWave = Waves3D::create(0, Size(1,1), 0, 0);

	node->runAction(endWave);
}

void WaveManager::stop(NodeGrid* node, Waves3D* wave){
	//node->stopAction(wave);
	auto endWave = Waves::create(0, Size(1, 1), 0, 0,false,false);

	node->runAction(endWave);
}
