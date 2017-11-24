#pragma once
//Contains core facilities for the game engine itself. Everything delegates up to here

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <cstdlib>
#include <SDL_mixer.h>
#include <ctime>
#include "Sprite.h"
#include "Player.h"
#include "StateMachine.h"
#include "GameSettings.h"

class GameEngine
{
public:
	GameEngine();
	~GameEngine();
	void appLoop();
private:	

	SDL_Event m_event;
	SDL_Renderer* m_renderer;
	SDL_Window* m_window;
	bool m_quit;
	void eventHandler();
	StateMachine stateMachine;
	
};