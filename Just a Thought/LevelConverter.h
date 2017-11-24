#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
class LevelConverter
{
public:
	LevelConverter(int w, int h);
	~LevelConverter();
	void openFile(std::string filename);
	void formatBytes();
	void outputBytes();
	void printBytes();

private:
	std::ifstream inputFile;
	std::ofstream outputFile;
	std::vector<char> data;
	int width;
	int height;
};

