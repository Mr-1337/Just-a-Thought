#include "GameState.h"

GameState::GameState(SDL_Renderer* renderer):nextState(STATE_NONE),m_renderer(renderer)
{
	
}

GameState::~GameState()
{
}

GameState::states GameState::getNextState()
{
	return nextState;
}
