#include "Timer.h"
#include "cocos2d.h"


MyTimer::MyTimer(int _time) :time(_time), isStart(false), isStop(false)
{
}

MyTimer::MyTimer(int _time,bool _isStart,bool _isStop) :
time(_time), isStart(_isStart), isStop(_isStop)
{
}

MyTimer::~MyTimer()
{
}

void MyTimer::countUp()
{
	time++;
}

void MyTimer::countDown()
{
	time--;
}


void MyTimer::pause()
{
	isStop = true;
}

void MyTimer::resume()
{
	isStop = false;
}

void MyTimer::reset()
{
	isStop = false;
	isStart = false;
	time = 0;
}

void MyTimer::begin()
{
	isStart = true;
}

int MyTimer::getTime()
{
	return time;
}

int MyTimer::getSecond()
{
	return time/30;
}

MyTimer MyTimer::operator + (int _time) const
{
	return MyTimer(time + _time,isStart,isStop);
}

MyTimer MyTimer::operator ++ (int)
{
	if (isStart&&!isStop)
	{
		this->time += 1;
	}
	
	return MyTimer(time,isStart,isStop);
}
