#include "Game.hpp"

#include "SDL.h"
#include <iostream>
#include <memory>

Game::Game(std::string title, int x, int y, int w, int h, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem initialised...\n";

		window = std::unique_ptr<SDL_Window, SDL_Window_Destroyer>(SDL_CreateWindow(title.c_str(), x, y, w, h, fullscreen));
		if (window)
		{
			std::cout << "Window created\n";
		}

		renderer = std::unique_ptr<SDL_Renderer, SDL_Renderer_Destroyer>(SDL_CreateRenderer(window.get(), -1, 0));
		if (renderer)
		{
			std::cout << "Renderer created\n";
		}

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
}

void Game::handle_events()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::update()
{
}

void Game::render()
{
	SDL_RenderClear(renderer.get());
	SDL_RenderPresent(renderer.get());
}

Game::~Game()
{
	SDL_Quit();

	std::cout << "Game cleaned\n";
}

bool Game::is_running()
{
	return isRunning;
}

void Game::SDL_Window_Destroyer::operator()(SDL_Window* w) const
{
	SDL_DestroyWindow(w);

	std::cout << "Window destroyed\n";
}

void Game::SDL_Renderer_Destroyer::operator()(SDL_Renderer* r) const
{
	SDL_DestroyRenderer(r);

	std::cout << "Renderer destroyed\n";
}