#pragma once

#include <String>
#include <SDL.h>
#include "../IO/LevelConverter.h"
#include "../Graphics/Camera.h"

class GameWorld
{

public:
	GameWorld(const std::string& path, SDL_Renderer* renderer, const Camera& camera);
	~GameWorld();


	inline const std::vector <std::vector<char>> &getData() const { return m_mapData; }
	void draw();

private:
	std::vector<std::vector<char>> m_mapData;
	LevelConverter m_levLoader;
	SDL_Renderer* m_renderer;
	SDL_Rect m_rect;
	const int size = 20;
	const Camera& m_cam;
	int xOffset, yOffset;
};

