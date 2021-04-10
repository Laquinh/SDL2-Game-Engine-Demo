#ifndef TIMEMANAGER_HPP
#define TIMEMANAGER_HPP

class TimeManager
{
public:
	static void init();
	static void update_deltaTime();
	static double get_deltaTime();
	static void limit_fps(double target);
private:
	static inline double deltaTime;
	static inline double currentTime;
};

#endif