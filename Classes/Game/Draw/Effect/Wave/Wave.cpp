#include "Wave.h"
#include "WaveManager.h"
#define WAVE 12

Wave* Wave::create(float duration, const Size
	gridSize, unsigned int waves, float amplitude, bool horizontal, bool vertical){
	
	Wave* wave = new Wave();

	wave->initWithDuration(duration, gridSize, waves, amplitude, horizontal, vertical);
	wave->autorelease();

	return wave;
}

bool Wave::initWithDuration(float duration, const Size
	gridSize, unsigned int waves, float amplitude, bool horizontal, bool vertical){
	if (Grid3DAction::initWithDuration(duration, gridSize)){
		_waves = waves;
		_amplitude = amplitude;
		_amplitudeRate = 1.0f;
		_horizontal = horizontal;
		_vertical = vertical;
		value = amplitude / (duration * 60);
		return true;
	}
	return false;
}

Wave* Wave::clone(void) const {
	auto a = new Wave();
	a->initWithDuration(_duration, _gridSize, _waves, _amplitude, _horizontal, _vertical);
	a->autorelease();

	return a;
}

void Wave::update(float time){
	int i, j;

	if (_amplitude < 0){
		_amplitude = _amplitude + value;

		if (_amplitude > 0){
			_amplitude = 0;
		}
	}

	if (_amplitude > 0){
		_amplitude = _amplitude - value;

		if (_amplitude < 0){
			_amplitude = 0;
		}
	}

	for (i = 0; i < _gridSize.width + 1; ++i)
	{
		for (j = 0; j < _gridSize.height + 1; ++j)
		{
			Vec3 v = getOriginalVertex(Vec2(i, j));
			
			if (_vertical)
			{
				v.x = (v.x + (sinf(time * (float)M_PI * _waves * 2 + v.y * .01f) * _amplitude * _amplitudeRate));
			}

			if (_horizontal)
			{
				v.y = (v.y + (sinf(time * (float)M_PI * _waves * 2 + v.x * .01f) * _amplitude * _amplitudeRate));
			}

			setVertex(Vec2(i, j), v);
		}
	}
}