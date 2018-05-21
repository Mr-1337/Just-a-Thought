#include "Sprite.h"
#include "GameEngine.h"

Sprite::Sprite(SDL_Renderer* renderer)
	:m_renderer(renderer)
{
	if (renderer != NULL)
	{
		std::cout << "Sprite created!" << std::endl;
	}
	else
	{
		std::cout << "Renderer undefined for Sprite" << std::endl;
	}
}

Sprite::~Sprite()
{
	std::cout << "Sprite destroyed!" << std::endl;
	SDL_DestroyTexture(m_texture);
}

void Sprite::setX(int x)
{
	m_dstRect.x = x;
}

void Sprite::setY(int y)
{
	m_dstRect.y = y;
}

void Sprite::setWidthHeight(int w, int h)
{
	m_dstRect.w = w;
	m_dstRect.h = h;
}

void Sprite::getWidthHeight(int* w, int* h)
{
	*w = m_dstRect.w;
	*h = m_dstRect.h;
}

SDL_Rect* Sprite::getRect()
{
	return &m_dstRect;
}

void Sprite::draw(int alpha)
{
	if (alpha < 0)
		alpha = 0;
	if (alpha > 255)
		alpha = 255;

	if (m_renderer != NULL && m_texture != NULL)
	{
		SDL_SetTextureAlphaMod(m_texture, alpha);
		SDL_RenderCopy(m_renderer, m_texture, NULL, &m_dstRect);
	}
	else
	{
		std::cout << "Renderer or texture are NULL" << std::endl;
	}
}

void Sprite::draw(SDL_Rect* clip, int alpha)
{
	if (alpha < 0)
		alpha = 0;
	if (alpha > 255)
		alpha = 255;

	if (m_renderer != NULL && m_texture != NULL && clip != NULL)
	{
		SDL_SetTextureAlphaMod(m_texture, alpha);
		m_dstRect.w = clip->w;
		m_dstRect.h = clip->h;
		SDL_RenderCopy(m_renderer, m_texture, clip, &m_dstRect);
	}
	else
	{
		std::cout << "Renderer, bounding rect, or texture are NULL" << std::endl;
	}
}

void Sprite::load(std::string path)
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