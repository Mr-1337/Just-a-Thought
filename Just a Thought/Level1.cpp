#include "Level1.h"

Level1::Level1(SDL_Renderer* renderer)
	: GameState(renderer), tiles(30, std::vector <char> (40)), Counter(renderer, "Halo 3"), frame(0)
{
	escape = false;
	for (int i = 0; i < 30; i++)
	{
		tiles[i].assign(40, 0);
	}
	LevelConverter converter(tiles);
	converter.openFile("Assets/Graphics/level1.jatmap");
	converter.loadBytes();
	m_player = new Player(m_renderer, tiles);
	enemy = new Enemy(renderer, *m_player);
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
	//delete enemy;
	//delete m_player;
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
	else
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
	enemy->draw();
	rect.w = size;
	rect.h = size;
	for (int i = 0;i < 30;i++)
	{
		for (int j = 0;j < 40;j++)
		{
			rect.x = size * j;
			rect.y = size * i;
			switch (tiles[i][j])
			{
			case 1:
				SDL_SetRenderDrawColor(m_renderer, 0xff, 0x00, 0x00, 0xff);
				SDL_RenderFillRect(m_renderer, &rect);
				break;
			case 2:
				SDL_SetRenderDrawColor(m_renderer, 0x00, 0xff, 0x00, 0xff);
				SDL_RenderFillRect(m_renderer, &rect);
				break;
			}
		}
	}
	Counter.draw();
	SDL_RenderPresent(m_renderer);
}