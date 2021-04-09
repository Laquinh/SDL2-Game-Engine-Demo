#include "Engine.hpp"

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
	const double dt = 1000.0 / fps;

	double currentTime = SDL_GetTicks();
	double accumulator = 0.0;

	while (game.is_running())
	{
		double newTime = SDL_GetTicks();
		double frameTime = newTime - currentTime;
		currentTime = newTime;

		game.handle_events();
		game.update(frameTime / 1000);

		//for(int i = 0; i < 750; ++i) std::cout << frameTime << "\n";

		if (dt > frameTime)
		{
			SDL_Delay(dt - frameTime);
		}
		game.render();
	}
}
