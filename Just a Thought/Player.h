#pragma once
#include "Sprite.h"
#include <vector>

class Player
{
public:
	Player(SDL_Renderer* renderer, std::vector <std::vector <char> > &mapIn);
	~Player();
	void update();
	void draw();
	void setX(int X);
private:
	Sprite* m_sprite;
	SDL_Renderer* m_renderer;
	std::vector <std::vector <char> > &map;
	bool fast;
	const float g = 0.1635f;
	float yVel;
	int x;
	int y;
};

