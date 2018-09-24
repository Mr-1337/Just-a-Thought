#include "Enemy.h"


Enemy::Enemy(SDL_Renderer* renderer, const Player& pin)
	:leg(renderer), top(renderer), player(pin), renderer(renderer)
{
	leg.load("Assets/Graphics/heavy.png");
	top.load("Assets/Graphics/heavytop.png");
	x = 300;
	y = 265;
	leg.setX(x);
	top.setX(x);
	shot.w = 10;
	shot.h = 10;
	shot.x = 300;
	shot.y = 255;
	timer.start();
}


Enemy::~Enemy()
{

}


void Enemy::draw()
{
	if (player.getX() < x)
	{
		pivot.x = 200;
		angle = 180 / M_PI  * atan2((y - (player.getY())), (x - player.getX()));
		leg.setFlip(SDL_FLIP_NONE);
		top.setFlip(SDL_FLIP_NONE);
	}	
	else
	{
		pivot.x = 91;
		angle = 180 / M_PI  * atan2((-y + (player.getY())), (-x + player.getX()));
		leg.setFlip(SDL_FLIP_HORIZONTAL);
		top.setFlip(SDL_FLIP_HORIZONTAL);
	}

	leg.draw();
	top.rotate(angle, &pivot);
	top.draw();
	static float angle2;
	if (timer.getTicks() > 500)
	{
		timer.restart();	
	}
	angle2 = atan2((float)(-shot.y + (player.getY())), (float)(-shot.x + player.getX()));
	SDL_SetRenderDrawColor(renderer, 0, 127, 0, 255);
	SDL_RenderFillRect(renderer, &shot);
	shot.x += (4.0 * cos(angle2));
	shot.y += (4.0 * sin(angle2));

} 