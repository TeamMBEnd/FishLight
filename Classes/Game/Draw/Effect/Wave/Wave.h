#ifndef WAVE_H
#define WAVE_H

#include "cocos2d.h"

#define WAVE 12 

USING_NS_CC;


class Wave : public Grid3DAction{
public:

	static Wave* create(float duration, const Size
		
		gridSize, unsigned int waves, float amplitude, bool horizontal, bool vertical);

	bool initWithDuration(float duration, const Size
		gridSize, unsigned int waves, float amplitude, bool horizontal, bool vertical);

	virtual Wave* clone(void) const override;

	virtual void update(float time) override;

	inline float getAmplitude() const { return _amplitude; }
	inline void setAmplitude(float amplitude) { _amplitude = amplitude; }

	inline float getAmplitudeRate() const { return _amplitudeRate; }
	inline void setAmplitudeRate(float amplitudeRate) { _amplitudeRate = amplitudeRate; }

	inline void setValue(float _value){ value = _value; }
	inline float setValue(){ return value; }

protected:
	unsigned int _waves;
	float _amplitude;
	float _amplitudeRate;
	bool _vertical;
	bool _horizontal;


private:
	float value;
	~Wave(){};
};
#endif