#include "GameWorld.h"



GameWorld::GameWorld(const std::string& path, SDL_Renderer* renderer, const Camera& camera) :
	m_mapData(30, std::vector<char>(40)), m_levLoader(m_mapData), m_renderer(renderer), m_cam(camera)
{
	m_levLoader.openFile("Assets/Graphics/level1.jatmap");
	m_levLoader.loadBytes();
}


GameWorld::~GameWorld()
{
}


void GameWorld::draw()
{
	m_rect.w = size;
	m_rect.h = size;
	xOffset = m_cam.getPos().first;
	yOffset = m_cam.getPos().second;

	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			m_rect.x = size * j - xOffset;
			m_rect.y = size * i - yOffset;
			switch (m_mapData[i][j])
			{
			case 1:
				SDL_SetRenderDrawColor(m_renderer, 0xff, 0x00, 0x00, 0xff);
				SDL_RenderFillRect(m_renderer, &m_rect);
				break;
			case 2:
				SDL_SetRenderDrawColor(m_renderer, 0x00, 0xff, 0x00, 0xff);
				SDL_RenderFillRect(m_renderer, &m_rect);
				break;
			}
		}
	}
}