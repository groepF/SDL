#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>

enum class GameState {PLAY, EXIT};

class Game
{
public:
	Game();
	~Game();

	void run();
	void initialize();
	void loop();
	void tick();

private:
	SDL_Window* window;
	int width, height;
	GameState gameState;
};

