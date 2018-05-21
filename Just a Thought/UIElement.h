#pragma once
#include <SDL.h>
#include "Sprite.h"
class UIElement
{
public:
	UIElement(SDL_Renderer* renderer);
	virtual ~UIElement() = 0;

	virtual void draw() = 0;
	virtual void update() = 0;

	void setX(int X);
	void setY(int Y);

protected:
	SDL_Renderer* m_renderer;
	Sprite* m_sprite;
	int x, y;
};

