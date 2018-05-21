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
	virtual void load(std::string path);
	void draw(int alpha = 255);
	virtual void draw(SDL_Rect* clip, int alpha = 255);
	void setX(int x);
	void setY(int y);
	void setWidthHeight(int w, int h);
	void getWidthHeight(int* w, int* h);
	SDL_Rect* getRect();
	
private:

protected:
	SDL_Texture* m_texture;
	SDL_Renderer* m_renderer;
	SDL_Rect m_dstRect;
};