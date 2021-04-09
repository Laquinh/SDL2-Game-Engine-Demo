#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "Game.hpp"

class Engine
{
public:
	Engine();
	~Engine();

	void run();
private:
	Game game;
};

#endif