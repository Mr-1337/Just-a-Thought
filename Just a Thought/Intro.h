#pragma once
#include "GameState.h"
#include "Sprite.h"
#include "GameSettings.h"
#include <random>
#include <ctime>

//Intro Screen

class Intro :
	public GameState
{
public:
	Intro();
	~Intro();
	void update();
	void draw();
	void init();
private:
	Sprite* splash;
	Mix_Chunk* noise;
	SDL_Rect rect;
	SDL_Rect overlay;
	int color;
	int timer;
	int w;
	int h;
	double alpha;
	void loadMedia();
};

