#include "Engine.hpp"
#include "TimeManager.hpp"

Engine::Engine():
	game("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 768, false)
{
}

Engine::~Engine()
{
}

void Engine::run()
{
	const int fps = 144;

	TimeManager::init();

	TimeManager::update_deltaTime();

	while (game.is_running())
	{
		game.handle_events();
		game.update();
		game.render();

		TimeManager::update_deltaTime();
		TimeManager::limit_fps(fps);
	}
}
