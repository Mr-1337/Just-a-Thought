#include "Intro.h"
#include "Title.h"

Intro::Intro():
	alpha(255),timer(0)
{
	std::cout << "Created Intro" << std::endl;
	splash = new Jangine::Sprite();
	loadMedia();
}

Intro::~Intro()
{
	std::cout << "Destroyed Intro" << std::endl;
	Mix_FreeChunk(noise);
	delete splash;
}

void Intro::loadMedia()
{
	SDL_SetRenderDrawColor(m_renderer, 130, 130, 130, 255);
	//SDL_RenderClear(m_renderer);
	noise = Mix_LoadWAV("Assets/Sound/whitenoise.wav");

	if (noise != NULL)
		Mix_PlayChannel(0, noise, -1);
	
	Jangine::GameSettings::getDimensions(&w, &h);
	srand(SDL_GetTicks());
	int choice = rand()%4;
	switch (choice)
	{
	case 0:
		splash->load("Assets/Graphics/the chef.png");
		splash->setX(-300);
		break;
	case 1:
		splash->load("Assets/Graphics/Shrek.png");
		splash->setX(-400);
		break;
	case 2:
		splash->load("Assets/Graphics/Elmo.png");
		splash->setX(0);
		break;
	case 3:
		splash->load("Assets/Graphics/Globglogabgalab.png");
		splash->setX(-200);
		break;
	}

	rect.w = 3;
	rect.h = 3;
	overlay.w = w;
	overlay.h = h;

	for (int i = 0; i < 50000; i++)
	{
		color = rand() % 255;
		rect.x = rand() % w;
		rect.y = (rand() % h);
		SDL_SetRenderDrawColor(m_renderer, color, color, color, 255);
		SDL_RenderFillRect(m_renderer, &rect);
	}
	SDL_RenderPresent(m_renderer);
	Mix_FadeOutChannel(0, 8000);
}

void Intro::update()
{
	alpha -= 0.5;
	if (alpha < 0)
		alpha = 0;
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, (255 - alpha)/100);
	splash->setAlpha(255 - alpha);
	splash->draw();
	SDL_RenderFillRect(m_renderer, &overlay);

	timer++;
	if (timer > 600)
	{
		m_nextState = std::make_shared<Title>();
	}

}

void Intro::draw()
{
	//Draw fading static dots
	for (int i = 0; i < 10000; i++)
	{
		color = rand() % 255;
		rect.x = rand() % w;
		rect.y = rand() % h;
		SDL_SetRenderDrawColor(m_renderer, color, color, color, alpha);
		SDL_RenderFillRect(m_renderer, &rect);
	}
	SDL_RenderPresent(m_renderer);
}