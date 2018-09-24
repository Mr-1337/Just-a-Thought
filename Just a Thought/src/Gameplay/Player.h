#pragma once
#include "../Graphics/AnimatedSprite.h"
#include <vector>

class Player
{
public:
	Player(SDL_Renderer* renderer, std::vector <std::vector <char> > &mapIn);
	~Player();
	void update();
	void draw();
	void setX(int X);
	inline int getX() const { return x; };
	inline int getY() const { return y; };
private:
	AnimatedSprite* m_sprite;
	SDL_Renderer* m_renderer;
	SDL_RendererFlip flip;
	std::vector <std::vector <char> > &map;
	bool fast;
	const float g;
	float yVel;
	int x;
	int y;
};

