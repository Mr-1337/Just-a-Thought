#include "Level1.h"

Level1::Level1(SDL_Window* window)
	: GameState(window), gameWorld("Assets/Graphics/level1.json", m_renderer, m_cam, 30, 40)
{
	escape = false;
	gameWorld.load();
	m_player = new Player(m_renderer, gameWorld, m_cam);
	m_music = Mix_LoadMUS("Assets/Sound/boss1.ogg");
	Mix_PlayMusic(m_music, -1);
}

Level1::~Level1()
{
	delete m_player;
	std::cout << "Destroyed Level 1" << std::endl;
}

void Level1::update()
{
	m_player->update();
	const Uint8* keys = SDL_GetKeyboardState(NULL);

	if (keys[SDL_SCANCODE_ESCAPE])
	{
		if (!escape)
		{
			request.state = STATE_PAUSE;
			request.popCurrent = false;	
			escape = true;
		}
	}
	else if (request.state != STATE_QUIT)
	{
		escape = false;
		request.state = STATE_NONE;
	}
}

void Level1::draw()
{
	SDL_SetRenderDrawColor(m_renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderClear(m_renderer);
	m_player->draw();
	gameWorld.draw();
	SDL_RenderPresent(m_renderer);
}

void Level1::revealed()
{
	GameState::revealed();
	//Mix_PauseMusic();
	Mix_PlayMusic(m_music, -1);
}