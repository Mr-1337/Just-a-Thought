#include "Level1.h"

Level1::Level1()
{
}


Level1::~Level1()
{
}


void Level1::update()
{
	m_player->update();
}


void Level1::draw()
{
	SDL_RenderClear(m_renderer);	
	m_ground->draw();
	m_player->draw();
	SDL_RenderPresent(m_renderer);
}


void Level1::init()
{
	m_player = new Player(m_renderer);
	m_ground = new Sprite(m_renderer);
	m_ground->loadImg("Assets/Graphics/ground.png");
	m_ground->draw();
	SDL_Surface* cursor = IMG_Load("Assets/Graphics/cursor.png");
	SDL_SetCursor(SDL_CreateColorCursor(cursor, 0, 0));
	//outputPixels();
}

void Level1::outputPixels()
{
	LevelConverter lc(1024,768);
	lc.openFile("Assets/Graphics/ground.data");
	lc.formatBytes();
	lc.outputBytes();
	//lc.printBytes();
}
