#include "Title.h"

Title::Title()
{
	std::cout << "Created Title" << std::endl;
}


Title::~Title()
{
	std::cout << "Title Destroyed" << std::endl;
	delete menu;
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_RenderClear(m_renderer);
	SDL_RenderPresent(m_renderer);
}

void Title::update()
{
	if (SDL_BUTTON_LEFT & SDL_GetMouseState(NULL, NULL))
	{
		nextState = GameState::STATE_LEVEL1;
	}
}

void Title::draw()
{
	SDL_RenderClear(m_renderer);
	menu->draw();
	SDL_RenderPresent(m_renderer);
}

void Title::init()
{
	menu = new Sprite(m_renderer);
	menu->loadImg("Assets/Graphics/menu2.png");
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
}
