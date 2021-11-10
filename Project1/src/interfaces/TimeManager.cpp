#include "TimeManager.hpp"
#include <chrono>
#include <thread>
#include <iostream>

namespace TimeManager
{
	void init()
	{
		currentTime = Clock::now();
	}

	void update_deltaTime()
	{
		auto newTime = Clock::now();
		deltaTime = duration_cast<microseconds>(newTime - currentTime);
		currentTime = newTime;
	}

	/*Clock::duration get_deltaTime()
	{
		return deltaTime;
	}*/

	double get_deltaTime()
	{
		return deltaTime.count() / 1000000.0;
	}

	void limit_fps(double target)
	{
		duration dt = duration<double, std::ratio<1>>(1.0 / target);
		if (dt > deltaTime)
		{
			std::this_thread::sleep_for(dt - deltaTime);
		}
	}

	Clock::time_point get_time()
	{
		return Clock::now();
	}
}