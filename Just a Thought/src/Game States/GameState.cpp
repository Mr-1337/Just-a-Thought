#include "GameState.h"

GameState::GameState(SDL_Window* window)
	: m_window(window), m_renderer(SDL_GetRenderer(window))
{
	if (m_renderer == NULL)
		std::cout << "Renderer is INVALID\n";
}

GameState::~GameState()
{
}

void GameState::eventHandler()
{
	while (SDL_PollEvent(&m_event) != 0)
	{
		switch (m_event.type)
		{
		case SDL_QUIT:
			request.state = STATE_QUIT;
		}
	}
}

void GameState::revealed()
{
	request.state = STATE_NONE;
	request.popCurrent = true;
	request.popPrev = false;
}

GameState::StateRequest GameState::getStateRequest()
{
	return request;
}
