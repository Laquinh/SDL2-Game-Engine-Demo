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
	const int fps = 60;

	TimeManager::init();

	while (game.is_running())
	{
		TimeManager::update_deltaTime();

		game.handle_events();
		game.update();
		game.render();

		TimeManager::limit_fps(fps);
	}
}
