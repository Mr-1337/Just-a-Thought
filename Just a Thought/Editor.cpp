#include "Editor.h"

Editor::Editor()
{
	for (int i = 0;i < 52;i++)
	{
		for (int j = 0;j < 39;j++)
		{
			tile[j][i] = 0;
		}
	}
	rect.w = 20;
	rect.h = 20;
	r = 1;
}

Editor::~Editor()
{
}

void Editor::update()
{
	static bool down = false;
	static bool up = false;
	if (SDL_BUTTON_LMASK == SDL_GetMouseState(&mouseX, &mouseY))
	{
		for (int i = 0; i < r*2 - 1; i++)
		{
			for (int j = 0; j < r*2 - 1; j++)
			{
				tile[((mouseY / 20) - (r-1)) + i][((mouseX / 20) - (r-1)) + j] = 1;
			}
		}	
	}
	else if (SDL_BUTTON_RMASK == SDL_GetMouseState(&mouseX, &mouseY))
	{
		for (int i = 0; i < r * 2 - 1; i++)
		{
			for (int j = 0; j < r * 2 - 1; j++)
			{
				tile[((mouseY / 20) - (r - 1)) + i][((mouseX / 20) - (r - 1)) + j] = 2;
			}
		}
	}
	else if (SDL_BUTTON_MMASK == SDL_GetMouseState(&mouseX, &mouseY))
	{
		for (int i = 0; i < r * 2 - 1; i++)
		{
			for (int j = 0; j < r * 2 - 1; j++)
			{
				tile[((mouseY / 20) - (r - 1)) + i][((mouseX / 20) - (r - 1)) + j] = 0;
			}
		}
	}
	const Uint8* keys = SDL_GetKeyboardState(NULL);
	if(keys[SDL_SCANCODE_DOWN] && !down && r > 1)
	{
		down = true;
		r--;
		std::cout << r << std::endl;
	}
	if (!keys[SDL_SCANCODE_DOWN] && down)
	{
		down = false;
	}
	if (keys[SDL_SCANCODE_UP] && !up)
	{
		up = true;
		r++;
		std::cout << r << std::endl;
	}
	if (!keys[SDL_SCANCODE_UP] && up)
	{
		up = false;
	}
}

void Editor::draw()
{
	SDL_SetRenderDrawColor(m_renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderClear(m_renderer);
	rect.w = 20;
	rect.h = 20;
	for (int i = 0;i < 52;i++)
	{
		for (int j = 0;j < 39;j++)
		{
			rect.x = 20 * i;
			rect.y = 20 * j;
			switch (tile[j][i])
			{
			case 1:
				SDL_SetRenderDrawColor(m_renderer, 0xff, 0x00, 0x00, 0xff);
				SDL_RenderFillRect(m_renderer, &rect);
				break;
			case 2:
				SDL_SetRenderDrawColor(m_renderer, 0x00, 0xff, 0x00, 0xff);
				SDL_RenderFillRect(m_renderer, &rect);
				break;
			}
		}		
	}
	rect.w = 40 * (r-1) + 20;
	rect.h = 40 * (r-1) + 20;
	SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x33, 0x88);
	rect.x = ((mouseX / 20) * 20) - (20 * (r-1));
	rect.y = ((mouseY / 20) * 20) - (20 * (r-1));
	SDL_RenderFillRect(m_renderer, &rect);
	drawGrid();
	SDL_RenderPresent(m_renderer);
}

void Editor::drawGrid()
{
	SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0x22);
	for (int i = 0;i < 52;i++)
	{
		SDL_RenderDrawLine(m_renderer, 20 * i, 0, 20 * i, 768);
	}
	for (int i = 0;i < 39;i++)
	{
		SDL_RenderDrawLine(m_renderer, 0, 20 * i, 1024, 20 * i);
	}
}

void Editor::init()
{

}