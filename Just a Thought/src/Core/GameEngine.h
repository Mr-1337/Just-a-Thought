#pragma once
//Contains core facilities for the game engine

#include <SDL.h>
#include <iostream>
#include "../Game States/StateMachine.h"
#include "GameSettings.h"

class GameEngine
{
public:
	GameEngine(std::string title);
	~GameEngine();
	void appLoop();
private:	
	
	SDL_Event m_event;
	SDL_Renderer* m_renderer;
	SDL_Window* m_window;
	StateMachine* stateMachine;
	
};