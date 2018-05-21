#pragma once
#include <SDL.h>
class Timer
{
public:
	Timer();
	void start();
	void pause();
	void stop();
	int getTicks();
	~Timer();
private:
	unsigned int ticks;
};

