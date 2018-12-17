#pragma once

#include <SDL.h>
#include <iostream>
#include <fstream>
#include <Graphics/Camera.h>
#include <vector>
#include <string>

class GameWorld
{

public:
	GameWorld(const std::string& path, const Jangine::Camera& camera, int rows = 30, int columns = 40);
	~GameWorld();

	inline const std::vector <std::vector<char>> &getData() const { return m_tileData; }
	void setData(int x, int y, char value);

	void load();
	void save();

	void draw() const;

private:

	const int TILE_SIZE = 20;
	int m_rows;
	int m_columns;

	const std::string m_path;
	std::ifstream m_iFile;
	std::ofstream m_oFile;

	std::vector<std::vector<char>> m_tileData;
	//std::vector<Structures> m_structureData;
	//std::vector<EnemySpawns> m_enemyData;

	SDL_Renderer* m_renderer;
	const Jangine::Camera& m_cam;
};

