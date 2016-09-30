#include "Game.h"



Game::Game()
{
	window = nullptr;
	gameState = GameState::PLAY;
	width = 1024;
	height = 768;
}


Game::~Game()
{
}

void Game::run()
{
	initialize();
	loop();
}

void Game::initialize()
{
	// Initialize SDL.
	SDL_Init(SDL_INIT_EVERYTHING);
	// Create a window.
	window = SDL_CreateWindow("Game", 
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		SDL_WINDOW_OPENGL
	);
}

void Game::loop()
{
	while (gameState != GameState::EXIT)
	{
		tick();
	}
}

void Game::tick()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			gameState = GameState::EXIT;
			break;
		}
	}
}