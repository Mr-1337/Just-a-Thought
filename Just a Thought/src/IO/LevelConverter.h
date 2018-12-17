#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>

#include "../Gameplay/GameWorld.h"

class LevelConverter
{
public:
	LevelConverter(GameWorld& world);
	~LevelConverter();
	void openFile(const std::string& filename);
	void loadBytes();
	void outputBytes();
	void printBytes();

private:
	std::ifstream inputFile;
	std::ofstream outputFile;

	GameWorld& world;

	std::vector <std::vector <char> > &data;

	std::filesystem::path filePath;
};

