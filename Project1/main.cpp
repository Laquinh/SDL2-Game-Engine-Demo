#include "SDL.h"

#include "Game.hpp"

#undef main

int main() {
	const int fps = 120;
	const int frameDelay = 1000 / fps;

	int frameStart;
	int frameTime;

	Game game("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, false);

	while (game.is_running())
	{
		frameStart = SDL_GetTicks();

		game.handle_events();
		game.update();
		game.render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	return 0;
}