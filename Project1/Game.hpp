#ifndef GAME_HPP
#define GAME_HPP

#include "SDL.h"
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

	struct SDL_Window_Destroyer
	{
		void operator()(SDL_Window* w) const;
	};
	std::unique_ptr<SDL_Window, SDL_Window_Destroyer> window;

	struct SDL_Renderer_Destroyer
	{
		void operator()(SDL_Renderer* r) const;
	};
	std::unique_ptr<SDL_Renderer, SDL_Renderer_Destroyer> renderer;
};

#endif