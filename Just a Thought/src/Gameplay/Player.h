#pragma once
#include <Graphics/AnimatedSprite.h>
#include <vector>
#include "GameWorld.h"

class Player
{
public:
	Player(SDL_Renderer* renderer, GameWorld &gameWorld, Jangine::Camera &camera);
	~Player();
	void update();
	void draw();
	void setX(int X);
	inline int getX() const { return x; };
	inline int getY() const { return y; };
private:
	Jangine::AnimatedSprite* m_sprite;
	SDL_Renderer* m_renderer;
	SDL_RendererFlip flip;
	GameWorld &m_map;
	bool fast;
	const float g;
	float yVel;
	int x;
	int y;
	Jangine::Camera &m_cam;
};

