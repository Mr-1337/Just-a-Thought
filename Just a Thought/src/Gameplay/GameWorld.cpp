#include "GameWorld.h"



GameWorld::GameWorld(const std::string& path, const Jangine::Camera& camera, int rows, int columns) :
	m_path(path), m_renderer(), m_cam(camera), m_rows(rows), m_columns(columns), m_tileData(rows, std::vector<char>(columns))
{
	std::cout << m_path << std::endl;
}


GameWorld::~GameWorld()
{
	m_iFile.close();
	m_oFile.close();
}


void GameWorld::load()
{

	m_iFile.open(m_path);

}


void GameWorld::save()
{

}


void GameWorld::setData(int x, int y, char value)
{
	if ((y >= 0 && y < m_rows) && (x >= 0 && x < m_columns))
	{
		m_tileData[y][x] = value;
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

	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_columns; j++)
		{
			rect.x = TILE_SIZE * j - xOffset;
			rect.y = TILE_SIZE * i - yOffset;
			switch (m_tileData[i][j])
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