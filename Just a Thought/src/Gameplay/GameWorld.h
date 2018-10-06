#pragma once

#include <String>
#include <SDL.h>
#include "../IO/LevelConverter.h"
#include "../Graphics/Camera.h"

class GameWorld
{

public:
	GameWorld(const std::string& path, SDL_Renderer* renderer, const Camera& camera, int rows, int columns);
	~GameWorld();

	inline const std::vector <std::vector<char>> &getData() const { return m_mapData; }
	void setData(int x, int y, char value);
	void draw() const;

private:

	const int TILE_SIZE = 20;
	int rows, columns;
	std::vector<std::vector<char>> m_mapData;
	LevelConverter m_levLoader;
	SDL_Renderer* m_renderer;
	const Camera& m_cam;
};

