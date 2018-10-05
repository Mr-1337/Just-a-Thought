#include "Player.h"

Player::Player(SDL_Renderer* renderer, GameWorld &gameWorld) 
	: m_renderer(renderer), m_map(gameWorld), g(0.1635f)
{
	if (m_renderer != nullptr)
	{
		flip = SDL_FLIP_NONE;
		SDL_Rect clip = {0,0,40,80};
		m_sprite = new AnimatedSprite(m_renderer, clip);
		m_sprite->load("Assets/Graphics/player.png");
		m_sprite->setFrameTime(80);
		std::cout << "Player Created!" << std::endl;
		x = 0;
		y = 100;
		fast = false;
		yVel = 0;
	}
	else
	{
		std::cout << "Renderer Undefined for player!" << std::endl;
	}
}

Player::~Player()
{
	std::cout << "Bye bye" << std::endl;
	delete m_sprite;
}

void Player::setX(int X)
{
	x = X;
}

void Player::update()
{
	const Uint8* keys = SDL_GetKeyboardState(NULL);

	static int speed;
	if (fast)
		speed = 6;
	else
		speed = 3;

	if (keys[SDL_SCANCODE_D])
	{
		x+=speed;
		flip = SDL_FLIP_NONE;
	}
	if (keys[SDL_SCANCODE_A])
	{
		x-= speed;
		flip = SDL_FLIP_HORIZONTAL;
	}
	if (keys[SDL_SCANCODE_W])
	{
		yVel = -4;
	}
	if (x < 0)
		x = 1;
	if (x > 750)
		x = 750;

	if (m_map.getData()[(y + 80) / 20][(x + 20) / 20] == 0 && y+floor(yVel) > 0)
	{
		y += floor(yVel);
	}
	yVel += g;

	while (m_map.getData()[(y + 80) / 20][(x + 20) / 20] != 0)
	{
		switch (m_map.getData()[(y + 80 ) / 20][(x + 20) / 20])
		{
		case 1:
			y--;
			fast = false;
			break;
		case 2:
			y--;
			fast = true;
			break;
		}
		yVel = 0;
	}
}

void Player::draw()
{
	m_sprite->setFlip(flip);
	m_sprite->setX(x);
	m_sprite->setY(y);
	m_sprite->draw();
}