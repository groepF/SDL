#include "Game.h"

#include <iostream>
#include <string>

void fatalError(std::string error)
{
	std::cout << error << std::endl;
	std::cout << "Enter any key to quit...";
	int tmp;
	std::cin >> tmp;
	SDL_Quit();
	exit(1);
}

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

	mSprite.initialize(-0.5f, -0.5f, 1.0f, 1.0f);

	loop();
}

void Game::initialize()
{
	// Initialize SDL.
	SDL_Init(SDL_INIT_EVERYTHING);
	// Create a window.
	window = SDL_CreateWindow("Super Game - Deluxe", 
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		SDL_WINDOW_OPENGL
	);
	// Check if the window is not null.
	if (window == nullptr) 
	{
		fatalError("SDL Window could not be created...");
	}
	// Get the context.
	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	// Check if the context is not null.
	if (glContext == nullptr) 
	{
		fatalError("SDL_GL context could not be created...");
	}
	// Initialize glew.
 	GLenum error = glewInit();
	// Check if glew initialized correctly.
	if (error != GLEW_OK)
	{
		fatalError("Glew could not be initialized...");
	}
	// Set a double buffer.
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void Game::loop()
{
	while (gameState != GameState::EXIT)
	{
		tick();
		render();
	}
	SDL_Quit();
}

void Game::render()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	mSprite.render();

	SDL_GL_SwapWindow(window);
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
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				gameState = GameState::EXIT;
				break;
			}
			break;
		}
		render();
	}
}