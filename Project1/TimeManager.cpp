#include "TimeManager.hpp"
#include "SDL.h"

void TimeManager::init()
{
	currentTime = SDL_GetTicks();
}

void TimeManager::update_deltaTime()
{
	double newTime = SDL_GetTicks();
	double frameTime = newTime - currentTime;
	currentTime = newTime;

	deltaTime = frameTime / 1000;
}

double TimeManager::get_deltaTime()
{
    return deltaTime;
}

void TimeManager::limit_fps(double target)
{
	double dt = 1000.0 / target;
	if (dt > deltaTime)
	{
		SDL_Delay(dt - deltaTime);
	}
}
