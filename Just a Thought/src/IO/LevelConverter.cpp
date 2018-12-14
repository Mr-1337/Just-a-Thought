#include "LevelConverter.h"


LevelConverter::LevelConverter(GameWorld& world)
	: data(std::vector < std::vector <char> >()), world(world)
{
}

LevelConverter::~LevelConverter()
{
	std::cout << "RIP CONVERTER" << std::endl;
	inputFile.close();
	outputFile.close();
}

void LevelConverter::openFile(const std::string& filename)
{
	inputFile.open(filename);
	inputFile >> jsonWorld;
}

void LevelConverter::loadBytes()
{
	data = jsonWorld["tiles"].get< std::vector <std::vector <char> >>();
	outputFile.open("Assets/Graphics/level1.json");
}

void LevelConverter::outputBytes()
{

	std::cout << "outputting level bytes" << std::endl;

	outputFile.open("Assets/Graphics/level1.json");

	outputFile << jsonWorld.dump(4);

}

void LevelConverter::printBytes()
{
	std::cout << "Creating text from map data" << std::endl;
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size(); j++)
		{
			std::cout << data[i][j];
		}
		std::cout << std::endl;
	}
}