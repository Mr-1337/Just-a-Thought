#include "Level1.h"

Level1::Level1(SDL_Renderer* renderer)
	: GameState(renderer), Counter(renderer, "Halo 3"), frame(0), gameWorld("Assets/Graphics/leve1.jatmap", renderer)
{
	escape = false;
	m_player = new Player(m_renderer, gameWorld);
	fontColor.r = 0;
	fontColor.g = 63;
	fontColor.b = 255;
	fontColor.a = 255;
	Counter.load("Assets/Font/Halo3.ttf", 48, fontColor);
	fpsTimer.start();
	fps = " ";

}

Level1::~Level1()
{
	delete m_player;
	std::cout << "Destroyed Level 1" << std::endl;
}

void Level1::update()
{
	frame++;	
	m_player->update();

	if (fpsTimer.getTicks() != 0)
	{
		fps = std::to_string(1000 * frame / fpsTimer.getTicks());
	}
	Counter.updateText(fps, fontColor);
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
	//enemy->draw();
	gameWorld.draw();
	Counter.draw();
	SDL_RenderPresent(m_renderer);
}