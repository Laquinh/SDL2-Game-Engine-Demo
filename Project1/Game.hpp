#ifndef GAME_HPP
#define GAME_HPP

#include "SDL.h"
#include "SDL_image.h"
#include "destroyers.hpp"

#include "ColliderComponent.hpp"

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

	static void add_tile(int x, int y, int id);
	bool is_running();

	static inline unique_SDL_Renderer renderer = nullptr;
	static inline unique_SDL_Window window = nullptr;
	static inline std::vector<std::shared_ptr<ColliderComponent>> colliders = {};
	static inline SDL_Event event;
	static inline SDL_Rect camera;
private:
	bool isRunning;
};

#endif