#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
class LevelConverter
{
public:
	LevelConverter(std::vector<std::vector<char> > &inputData);
	~LevelConverter();
	void openFile(const std::string& filename);
	void loadBytes();
	void outputBytes();
	void printBytes();

private:
	std::ifstream inputFile;
	std::ofstream outputFile;
	std::vector <std::vector <char> > &data;
};

