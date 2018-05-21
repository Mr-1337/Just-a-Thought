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
	StateMachine(SDL_Renderer* renderer);
	~StateMachine();
	void setState(GameState::states newState);
	GameState::states getNextState();
	void update();
	void draw();

private:
	GameState* currentState;
	SDL_Renderer* m_renderer;
};

