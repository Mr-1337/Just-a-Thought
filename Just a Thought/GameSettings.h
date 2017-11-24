#pragma once

//Global settings for the game

class GameSettings
{
public:
	~GameSettings();
	static void getDimensions(int* w, int* h);
	static void setDimensions(int w, int h);
private:
	GameSettings();
	static int width;
	static int height;
};