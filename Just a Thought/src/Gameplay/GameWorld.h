#pragma once

#include <String>
#include <SDL.h>
#include "../IO/LevelConverter.h"

class GameWorld
{

public:
	GameWorld(const std::string& path, SDL_Renderer* renderer);
	~GameWorld();


	inline const std::vector <std::vector<char>> &getData() const { return m_mapData; }
	void draw();

private:
	std::vector<std::vector<char>> m_mapData;
	LevelConverter m_levLoader;
	SDL_Renderer* m_renderer;
	SDL_Rect m_rect;
	const int size = 20;
};

