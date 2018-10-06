#include "GameWorld.h"



GameWorld::GameWorld(const std::string& path, SDL_Renderer* renderer, const Camera& camera, int rows, int columns) :
	m_mapData(rows, std::vector<char>(columns)), m_levLoader(m_mapData), m_renderer(renderer), m_cam(camera)
{
	this->rows = rows;
	this->columns = columns;
	m_levLoader.openFile(path);
	m_levLoader.loadBytes();
}


GameWorld::~GameWorld()
{
}


void GameWorld::setData(int x, int y, char value)
{
	if ((y >= 0 && y < rows) && (x >= 0 && x < columns))
	{
		m_mapData[y][x] = value;
	}
	else
	{
		std::cout << "Attempted to index outside of world bounds!" << std::endl;
	}
}


void GameWorld::draw() const
{

	SDL_Rect rect = {0, 0, TILE_SIZE, TILE_SIZE};
	int xOffset = m_cam.getPos().first;
	int yOffset = m_cam.getPos().second;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			rect.x = TILE_SIZE * j - xOffset;
			rect.y = TILE_SIZE * i - yOffset;
			switch (m_mapData[i][j])
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
}