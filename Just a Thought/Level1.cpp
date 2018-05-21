#include "Level1.h"

Level1::Level1(SDL_Renderer* renderer)
	: GameState(renderer), tiles(30, std::vector <char> (40)), Counter(renderer, "Halo 3")
{
	for (int i = 0; i < 30; i++)
	{
		tiles[i].assign(40, 0);
	}
	LevelConverter converter(tiles);
	converter.openFile("Assets/Graphics/level1.jatmap");
	converter.loadBytes();
	m_player = new Player(m_renderer, tiles);
	fontColor.r = 0;
	fontColor.g = 63;
	fontColor.b = 255;
	fontColor.a = 255;
	Counter.load("Assets/Font/Halo3.ttf", 48, fontColor);
	fpsTimer.start();
	
}

Level1::~Level1()
{

}

void Level1::update()
{
	static int frame = 0;
	frame++;	
	m_player->update();
	if (fpsTimer.getTicks() == 0)
		SDL_Delay(1);
	fps = std::to_string ( 1000 * frame / fpsTimer.getTicks() );
	Counter.updateText(fps, fontColor);
}

void Level1::draw()
{
	SDL_SetRenderDrawColor(m_renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderClear(m_renderer);
	m_player->draw();
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