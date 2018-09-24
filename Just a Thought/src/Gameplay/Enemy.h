#pragma once
#include "../Graphics/Sprite.h"
#include "Player.h"
#include "../Core/Timer.h"
class Enemy
{
public:
	Enemy(SDL_Renderer* renderer, const Player& pin);
	~Enemy();
	void draw();
private:
	SDL_Renderer* renderer;
	SDL_Rect shot;
	Timer timer;
	Sprite leg;
	Sprite top;
	const Player& player;
	SDL_Point pivot = { 200,255 };
	double angle;
	float x, y;
};

