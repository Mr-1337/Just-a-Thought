#pragma once
#include <Graphics/Sprite.h>
#include <Util/Timer.h>
#include "Player.h"
class Enemy
{
public:
	Enemy(SDL_Renderer* renderer, const Player& pin);
	~Enemy();
	void draw();
private:
	SDL_Renderer* renderer;
	SDL_Rect shot;
	Jangine::Timer timer;
	Jangine::Sprite leg;
	Jangine::Sprite top;
	const Player& player;
	SDL_Point pivot = { 200,255 };
	double angle;
	float x, y;
};

