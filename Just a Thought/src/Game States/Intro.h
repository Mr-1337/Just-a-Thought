#pragma once
#include "GameState.h"
#include "../Graphics/Sprite.h"
#include "../Core/GameSettings.h"
#include <random>

//Intro Screen

class Intro :
	public GameState
{
public:
	Intro(SDL_Renderer* renderer);
	~Intro();
	void update();
	void draw();
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

