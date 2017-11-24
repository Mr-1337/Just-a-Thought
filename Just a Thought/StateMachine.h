#pragma once

#include "GameState.h"
#include "Intro.h"
#include "Title.h"
#include "Level1.h"
#include "Editor.h"

//Houses all the different game states, facilitates their usage, and contains logic for switching

class StateMachine
{
public:
	StateMachine();
	~StateMachine();
	void setState(int state);
	int getNextState();
	void update();
	void draw();
	void setRenderer(SDL_Renderer* renderer);
private:
	GameState* currentState;
	SDL_Renderer* m_renderer;
};

