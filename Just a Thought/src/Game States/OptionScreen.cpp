#include "OptionScreen.h"



OptionScreen::OptionScreen()
{
	std::cout << "Entering Options Menu " << std::endl;
	volume = new Jangine::Slider();
	volume->setX(300);
	volume->setY(500);
	escape = false;
}

void OptionScreen::draw()
{
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_RenderClear(m_renderer);
	volume->draw();
	SDL_RenderPresent(m_renderer);
}

void OptionScreen::update(float timestep)
{
	volume->update();
	const Uint8* keys = SDL_GetKeyboardState(NULL);
	if (keys[SDL_SCANCODE_ESCAPE])
	{
		if (!escape)
		{
			std::cout << "TODO: LET USER LEAVE!!!" << std::endl;
		}
	}
	else
	{
		escape = false;
	}
}

OptionScreen::~OptionScreen()
{
	std::cout << "options dead" << std::endl;
}
