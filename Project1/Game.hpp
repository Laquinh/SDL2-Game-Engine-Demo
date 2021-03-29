#ifndef GAME_HPP
#define GAME_HPP

#include "SDL.h"
#include "SDL_image.h"
#include "destroyers.hpp"

#include <iostream>
#include <memory>

class Game
{
public:
	Game(std::string title, int x, int y, int w, int h, bool fullscreen);
	~Game();
	void handle_events();
	void update();
	void render();

	bool is_running();

private:
	bool isRunning;

	unique_SDL_Window window;
	unique_SDL_Renderer renderer;
};

#endif