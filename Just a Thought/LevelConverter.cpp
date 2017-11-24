#include "LevelConverter.h"


LevelConverter::LevelConverter(int w, int h)
{
	width = w;
	height = h;
	data.resize(width*height);
}

LevelConverter::~LevelConverter()
{
	inputFile.close();
	outputFile.close();
}

void LevelConverter::openFile(std::string filename)
{
	inputFile.open(filename, std::ios::binary);
}

void LevelConverter::formatBytes()
{
	for (int i=0;i<width*height;i++)
	{
		data[i] = inputFile.get();
		inputFile.seekg(3, std::ios::cur);
	}
}

void LevelConverter::outputBytes()
{
	std::cout << "Creating map file from image" << std::endl;
	outputFile.open("Assets/Graphics/level1.jatmap");
	for (int j = 0;j<width*height;j++)
	{
		outputFile << data[j];
	}
}

void LevelConverter::printBytes()
{
	for (int i = 0;i<height*width;i++)
	{
		std::cout << data[i];
		if (i>width && (i%width == 0))
		{
			std::cout << std::endl;
		}
	}
}