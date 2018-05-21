#pragma once

#include <SDL.h>
#include <iostream>
#include <SDL_mixer.h>
#include "Sprite.h"

//Abstract type for different GameStates

class GameState
{
public:
	GameState(SDL_Renderer* renderer);
	virtual ~GameState();
	virtual void update() = 0;
	virtual void draw() = 0;
	enum states
	{
		STATE_NONE,
		STATE_QUIT,
		STATE_INTRO,
		STATE_TITLE,
		STATE_EDITOR,
		STATE_LEVEL1
	};

	states getNextState();
protected:
	SDL_Renderer* m_renderer;
	states nextState;
};

