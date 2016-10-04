#include "Game.h"
#include <Box2D/Box2D.h>
#include <string>

Game::Game()
{
	window = nullptr;
	gameState = GameState::PLAY;
	width = 1024;
	height = 768;

	b2Vec2 gravity = b2Vec2(0, -9.8);

	world = new b2World(gravity);
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
	
	SDL_SetWindowTitle(window, "Super Game - Deluxe");
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

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