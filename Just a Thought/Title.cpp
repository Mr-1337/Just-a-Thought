#include "Title.h"

Title::Title(SDL_Renderer* renderer):
	GameState(renderer)
{
	std::cout << "Created Title" << std::endl;

	menu = new Sprite(m_renderer);

	menu->load("Assets/Graphics/tempmenu.png");

	int w, h;
	GameSettings::getDimensions(&w, &h);
	menu->setWidthHeight(w, h);
	m_play = new MenuButton(m_renderer, "Assets/Graphics/play.png");
	m_quit = new MenuButton(m_renderer, "Assets/Graphics/quit.png");
	m_options = new MenuButton(m_renderer, "Assets/Graphics/options.png");
	m_play->setX(375);
	m_play->setY(400);
	m_options->setX(375);
	m_options->setY(460);
	m_quit->setX(375);
	m_quit->setY(520);
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
}


Title::~Title()
{
	std::cout << "Title Destroyed" << std::endl;
	delete menu;
	delete m_play;
	delete m_quit;
	delete m_options;
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_RenderClear(m_renderer);
	SDL_RenderPresent(m_renderer);
}

void Title::update()
{
	m_play->update();
	m_options->update();
	m_quit->update();
	if (m_play->click())
	{
		nextState = GameState::STATE_LEVEL1;
	}
	if (m_options->click())
	{
		nextState = GameState::STATE_EDITOR;
	}
	if (m_quit->click())
	{
		nextState = GameState::STATE_QUIT;
	}
}

void Title::draw()
{
	SDL_RenderClear(m_renderer);
	menu->draw();
	m_play->draw();
	m_options->draw();
	m_quit->draw();
	SDL_RenderPresent(m_renderer);
}