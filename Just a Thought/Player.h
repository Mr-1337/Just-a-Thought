#pragma once
#include "Sprite.h"
#include <vector>
#include <bitset>
class Player
{
public:
	Player(SDL_Renderer* renderer);
	~Player();
	void update();
	void draw();
private:
	Sprite* m_sprite;
	SDL_Renderer* m_renderer;
	int x;
	int y;
	Uint8 map[768][1024];
};

