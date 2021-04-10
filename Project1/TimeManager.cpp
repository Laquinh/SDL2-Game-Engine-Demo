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
	if (target > deltaTime)
	{
		SDL_Delay(target - deltaTime);
	}
}
