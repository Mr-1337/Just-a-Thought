#include "GameEngine.h"

GameEngine::GameEngine():m_quit(false)
{
	//Only let the application loop execute if window creation and renderer creation succeed

	int width, height;
	GameSettings::getDimensions(&width, &height);
	m_window = SDL_CreateWindow("Just a Thought", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

	if (m_window == NULL)
	{
		std::cout << "Window creation failed! Error: " << SDL_GetError() << std::endl;
		m_quit = true;
	}
	else
	{
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (m_renderer == NULL)
		{
			std::cout << "Renderer creation failed! Error: " << SDL_GetError() << std::endl;
			m_quit = true;
		}
		else
		{
			SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);
			std::cout << "Engine construction successful!" << std::endl;
			stateMachine.setRenderer(m_renderer);
			stateMachine.setState(GameState::STATE_EDITOR);
		}
	}
}

GameEngine::~GameEngine()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
}

void GameEngine::appLoop()
{
	while (!m_quit)
	{
		stateMachine.setState(stateMachine.getNextState());
		eventHandler();
		stateMachine.update();
		stateMachine.draw();
	}
}

void GameEngine::eventHandler()
{
	while (SDL_PollEvent(&m_event) != 0)
	{
		if (m_event.type == SDL_QUIT)
		{
			m_quit = true;
		}
	}
}