#include "SDL.h"

#include "Game.hpp"

#undef main

int main() {
	Game game("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, false);

	while (game.is_running())
	{
		game.handle_events();
		game.update();
		game.render();
	}

	return 0;
}