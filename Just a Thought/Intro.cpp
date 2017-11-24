#include "Intro.h"

Intro::Intro():alpha(255),timer(0)
{
	std::cout << "Created Intro" << std::endl;
	srand(static_cast<int>(time(0)));
}

Intro::~Intro()
{
	std::cout << "Destroyed Intro" << std::endl;
	Mix_FreeChunk(noise);
	delete splash;
}

void Intro::init()
{
	splash = new Sprite(m_renderer);
	loadMedia();
}

void Intro::loadMedia()
{
	SDL_SetRenderDrawColor(m_renderer, 130, 130, 130, 255);
	//SDL_RenderClear(m_renderer);
	noise = Mix_LoadWAV("Assets/Sound/whitenoise.wav");

	if (noise != NULL)
		Mix_PlayChannel(0, noise, -1);

	GameSettings::getDimensions(&w, &h);
	int choice = rand() % 3;
	switch (choice)
	{
	case 0:
		splash->loadImg("Assets/Graphics/the chef.png");
		splash->setPosition(-300, 0);
		break;
	case 1:
		splash->loadImg("Assets/Graphics/Shrek.png");
		splash->setPosition(-400, 0);
		break;
	case 2:
		splash->loadImg("Assets/Graphics/Elmo.png");
		splash->setPosition(0, 0);
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
		rect.y = rand() % h;
		SDL_SetRenderDrawColor(m_renderer, color, color, color, 255);
		SDL_RenderFillRect(m_renderer, &rect);
	}
	SDL_RenderPresent(m_renderer);
	Mix_FadeOutChannel(0, 8000);
}

void Intro::update()
{
	alpha -= 0.5;
	if (alpha <= 0)
		alpha = 0;
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, (255.0 - alpha)/100);

	splash->draw(NULL,(255-alpha)/5);
	SDL_RenderFillRect(m_renderer, &overlay);

	timer++;
	if (timer > 660)
	{
		nextState = GameState::STATE_TITLE;
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
		SDL_SetRenderDrawColor(m_renderer, color, color, color, static_cast<int>(alpha));
		SDL_RenderFillRect(m_renderer, &rect);
	}
	SDL_RenderPresent(m_renderer);
}