#include "Title.h"
#include "Level1.h"

Title::Title()
{
	std::cout << "Created Title" << std::endl;

	menu = new Jangine::Sprite();

	menu->load("Assets/Graphics/tempmenu.png");

	int w, h;
	Jangine::GameSettings::getDimensions(&w, &h);
	menu->setWidthHeight(w, h);
	m_playButton = new MenuButton("Assets/Graphics/play.png");
	m_quitButton = new MenuButton("Assets/Graphics/quit.png");
	m_optionsButton = new MenuButton("Assets/Graphics/options.png");
	m_editorButton = new MenuButton("Assets/Graphics/editor.png");

	m_playButton->onClick = [this]() { m_nextState = std::make_shared<Level1>(); };
	m_quitButton->onClick = [this]() { m_quit = true; };

	m_playButton->setX(375);
	m_playButton->setY(400);
	m_optionsButton->setX(375);
	m_optionsButton->setY(460);
	m_editorButton->setX(375);
	m_editorButton->setY(520);
	m_quitButton->setX(375);
	m_quitButton->setY(580);
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
}


Title::~Title()
{
	std::cout << "Title Destroyed" << std::endl;
	delete menu;
	delete m_playButton;
	delete m_quitButton;
	delete m_optionsButton;
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_RenderClear(m_renderer);
	SDL_RenderPresent(m_renderer);
}

void Title::update(float timestep)
{
	m_playButton->update();
	m_optionsButton->update();
	m_quitButton->update();
	m_editorButton->update();
}

void Title::draw()
{
	SDL_RenderClear(m_renderer);
	menu->draw();
	m_playButton->draw();
	m_optionsButton->draw();
	m_editorButton->draw();
	m_quitButton->draw();
	SDL_RenderPresent(m_renderer);
}