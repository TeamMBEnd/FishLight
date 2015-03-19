#ifndef _TIMER_H_
#define _TIMER_H_
class MyTimer
{ 
public:
	MyTimer(int _time);
	MyTimer(int _time, bool _isStart, bool _isStop);
	~MyTimer();

	void countUp();
	void countDown();
	void pause();
	void resume();
	void reset();
	void begin();
	bool IsStart();
	
	MyTimer operator + (int _time)const;
	MyTimer operator ++ (int);
	int getTime();
	int getSecond();
	
private:
	int time;
	bool isStart;
	bool isStop;
};

#endif

