#pragma once

#include <SDL.h>
#include <iostream>
#include <SDL_mixer.h>

//Abstract type for different GameStates

class GameState
{
public:
	GameState(SDL_Window* window);
	virtual ~GameState();
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void revealed();
	virtual void eventHandler();

	enum states
	{
		STATE_NONE,
		STATE_POP,
		STATE_QUIT,
		STATE_PAUSE,
		STATE_INTRO,
		STATE_TITLE,
		STATE_EDITOR,
		STATE_LEVEL1,
		STATE_OPTIONS
	};
	
	struct StateRequest
	{
		StateRequest()
		{
			popCurrent = true;
			popPrev = false;
			state = STATE_NONE;
		}
		bool popCurrent;
		bool popPrev;
		states state;
	};

	StateRequest getStateRequest();
protected:
	SDL_Event m_event;
	StateRequest request;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
};

