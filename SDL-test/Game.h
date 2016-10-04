#pragma once

#include <SDL/SDL.h>
#include <GL/glew.h>

#include "Sprite.h"


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
	void render();

private:
	SDL_Window* window;
	GameState gameState;
	int width, height;

	Sprite mSprite;
};

