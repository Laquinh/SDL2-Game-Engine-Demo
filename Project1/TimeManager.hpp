#ifndef TIMEMANAGER_HPP
#define TIMEMANAGER_HPP

namespace TimeManager
{
	void init();
	void update_deltaTime();
	double get_deltaTime();
	void limit_fps(double target);

	inline double deltaTime;
	inline double currentTime;
}

#endif