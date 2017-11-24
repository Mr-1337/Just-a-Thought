#include "Player.h"

Player::Player(SDL_Renderer* renderer) : m_renderer(renderer)
{
	if (m_renderer != nullptr)
	{
		m_sprite = new Sprite(m_renderer);
		m_sprite->loadImg("Assets/Graphics/guy.png");
		std::cout << "Player Created!" << std::endl;
		SDL_RWops* mapData = SDL_RWFromFile("Assets/Graphics/level1.jatmap", "r+b");
		std::cout << std::endl;
		if (mapData != NULL)
		{
			for (int j = 0;j < 768;j++)
			{
				for (int i = 0;i < 1024;i++)
				{
					SDL_RWread(mapData, &map[j][i], sizeof(Uint8), 1);
				}
			}
		}
		x = 0;
		y = 0;
	}
	else
	{
		std::cout << "Renderer Undefined for player!" << std::endl;
	}
}


Player::~Player()
{
	std::cout << "Bye bye" << std::endl;
	SDL_DestroyRenderer(m_renderer);
	delete m_sprite;
}

void Player::update()
{
	const Uint8* keys = SDL_GetKeyboardState(NULL);
	static float speed;
	speed += 0.4;
	if (keys[SDL_SCANCODE_D])
	{
		x+=5;
	}
	if (keys[SDL_SCANCODE_A])
	{
		x-=5;
	}
	if (keys[SDL_SCANCODE_W])
	{
		for (int i = 0; i < 16; i++)
		{
			y--;
			if (y >= 0 && y <= 768)
			{
				while (map[y][x + 64] == 0)
				{
					y++;
					//speed = 0;
				}
			}
		}
	}
	for (int i = 0; i < speed; i++)
	{
		y++;
		if (y >= 0 && y <= 768)
		{
			while (map[y + 128][x + 64] == 0 || map[y + 127][x + 64] == 0)
			{
				y--;
				speed = 0;
			}
		}
	}
}

void Player::draw()
{
	m_sprite->setPosition(x, y);
	m_sprite->draw();
}