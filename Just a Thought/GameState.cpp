#include "GameState.h"

GameState::GameState():nextState(0)
{
	
}

GameState::~GameState()
{
}

void GameState::setRenderer(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}

int GameState::getNextState()
{
	return nextState;
}
