#include "Player.h"

Player::Player(SDL_Renderer* renderer, std::vector <std::vector <char> > &mapIn) 
	: m_renderer(renderer), map(mapIn)
{
	if (m_renderer != nullptr)
	{
		m_sprite = new Sprite(m_renderer);
		m_sprite->load("Assets/Graphics/guy.png");
		std::cout << "Player Created!" << std::endl;
		x = 0;
		y = 100;
		m_sprite->setWidthHeight(40, 40);
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
	SDL_DestroyRenderer(m_renderer);
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
		speed = 2;
	if (keys[SDL_SCANCODE_D])
	{
		x+=speed;
	}
	if (keys[SDL_SCANCODE_A])
	{
		x-= speed;
	}
	if (keys[SDL_SCANCODE_W])
	{
		yVel =- 4;
	}
	yVel += g;
	y += floor(yVel);	
	if (x < 0)
		x = 1;
	if (x > 600)
		x = 600;
	while (map[(y+40) / 20][(x+20)/20] != 0)
	{
		switch (map[(y + 40) / 20][(x + 20) / 20])
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
	m_sprite->setX(x);
	m_sprite->setY(y);
	m_sprite->draw();
}