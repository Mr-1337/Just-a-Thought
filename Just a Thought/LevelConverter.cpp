#include "LevelConverter.h"


LevelConverter::LevelConverter(std::vector<std::vector<char> > &inputData)
	: data(inputData)
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
}

void LevelConverter::loadBytes()
{
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size(); j++)
		{
			data[i][j] = inputFile.get();
		}
	}
}

void LevelConverter::outputBytes()
{
	std::cout << "Creating map file from image" << std::endl;
	outputFile.open("Assets/Graphics/level1.jatmap");
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size(); j++)
		{
			outputFile << data[i][j];
		}
	}
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