#pragma once
#include "Sprite.h"
#include <SDL_ttf.h>
class Text :
	public Sprite
{
public:
	Text(SDL_Renderer* renderer, std::string message);
	~Text();
	void load(std::string path, int pntSize, SDL_Color fontColor = { 0, 0, 0, 255 });
	void draw() override;
	void updateText(std::string text);
private:
	TTF_Font* font;
	SDL_Color fontColor;
	SDL_Surface* tempSurface;
	std::string m_string;
};

