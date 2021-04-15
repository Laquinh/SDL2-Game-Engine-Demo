#ifndef TIMEMANAGER_HPP
#define TIMEMANAGER_HPP

#include <chrono>

namespace TimeManager
{
	using namespace std::chrono;
	using Clock = system_clock;

	void init();
	void update_deltaTime();
	//Clock::duration get_deltaTime();
	double get_deltaTime();
	void limit_fps(double target);

	Clock::time_point get_time();

	inline microseconds deltaTime;
	inline Clock::time_point currentTime;
}

#endif