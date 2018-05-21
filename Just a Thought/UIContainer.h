#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <vector>
#include <iterator>
#include "UIElement.h"
class UIContainer
{
public:
	UIContainer(SDL_Renderer* renderer);
	virtual ~UIContainer()=0;

	virtual void update() = 0;
	virtual void draw() = 0;

protected:
	SDL_Renderer* m_renderer;
	std::vector<UIElement*> children;
	std::vector<UIElement*>::iterator iter;
};

