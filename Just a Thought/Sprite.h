#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>

//Represents a drawable image

class Sprite
{
public:
	Sprite (SDL_Renderer* renderer);
	~Sprite();
	void loadImg(std::string path);
	void draw();
	void draw(SDL_Rect* clip,int alpha = 255);
	void setPosition(int x, int y);
	
private:

protected:
	SDL_Texture* m_texture;
	SDL_Renderer* m_renderer;
	SDL_Rect m_dstRect;
};