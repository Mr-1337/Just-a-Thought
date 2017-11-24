#include "Sprite.h"
#include "GameEngine.h"

Sprite::Sprite(SDL_Renderer* renderer)
{
	std::cout << "Sprite created!" << std::endl;
	m_renderer = renderer;
}

Sprite::~Sprite()
{
	std::cout << "Sprite destroyed!" << std::endl;
	SDL_DestroyTexture(m_texture);
}

void Sprite::setPosition(int x, int y)
{
	m_dstRect.x = x;
	m_dstRect.y = y;
}

void Sprite::draw()
{
	if (m_renderer != NULL && m_texture != NULL)
	{
		SDL_RenderCopy(m_renderer, m_texture, NULL, &m_dstRect);
	}
	else
	{
		std::cout << "Renderer or texture is missing" << std::endl;
	}
}

void Sprite::draw(SDL_Rect* clip,int alpha)
{
	if (alpha < 0)
		alpha = 0;
	if (alpha > 255)
		alpha = 255;

	if (m_renderer != NULL && m_texture != NULL)
	{
		SDL_SetTextureAlphaMod(m_texture, alpha);
		SDL_RenderCopy(m_renderer, m_texture, clip, &m_dstRect);
	}
	else
	{
		std::cout << "Renderer or texture is missing" << std::endl;
	}
}

void Sprite::loadImg(std::string path)
{
	SDL_Surface* tempSurface;
	tempSurface = IMG_Load(path.c_str());
	if (tempSurface == NULL)
	{
		std::cout << "Error loading image! Error: " << IMG_GetError() << std::endl;
	}
	else
	{
		if (m_renderer == NULL)
		{
			std::cout << "Rendering context is undefined for this sprite!" << std::endl;
		}
		else
		{
			m_texture = SDL_CreateTextureFromSurface(m_renderer, tempSurface);

			m_dstRect.x = 0;
			m_dstRect.y = 0;
			m_dstRect.w = tempSurface->w;
			m_dstRect.h = tempSurface->h;
			std::cout << "loaded texture " << path << " with dimensions of " << m_dstRect.w << " x " << m_dstRect.h << std::endl;
		}
	}
	SDL_FreeSurface(tempSurface);
}