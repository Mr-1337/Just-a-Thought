/*
Created February 3rd 2017 by Mr. 1337
This is my first real project that I have put a lot of thought and work into, and hopefully I can make something special
This is also a spiritual successor to "platformgame.swf", an earlier project. Some of you may probably remember that abomination, but it was my first attempt at something like this.
I know that this probably won't be the magnum opus that I'd really like it to be, but one can dream right?
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_net.h>

#include "GameEngine.h"

//Loads SDL + accompanying libraries
bool initializeLibs();
//Unloads SDL + accompanying libraries
void shutdown();

/*
── █───▄▀█▀▀█▀▄▄───▐█──────▄▀█▀▀█▀▄▄
──█───▀─▐▌──▐▌─▀▀──▐█─────▀─▐▌──▐▌─█▀
─▐▌──────▀▄▄▀──────▐█▄▄──────▀▄▄▀──▐▌
─█────────────────────▀█────────────█
▐█─────────────────────█▌───────────█
▐█─────────────────────█▌───────────█
─█───────────────█▄───▄█────────────█
─▐▌───────────────▀███▀────────────▐▌
──█──────────▀▄───────────▄▀───────█
───█───────────▀▄▄▄▄▄▄▄▄▄▀────────█
*/

int main(int argc, char* args[])
{
	std::cout << "Welcome to the console output for Just a Thought!" << std::endl << std::endl;
	
	if (initializeLibs())
	{
		std::cout << "Initialization succeeded! Starting the game." << std::endl;
		SDL_Rect bounds;
		if (SDL_GetDisplayBounds(0, &bounds) != 0)
		{
			std::cout << SDL_GetError();
			std::cin.get();
			return -1;
		}
		std::cout << "Monitor Dimensions: " << bounds.w << " x " << bounds.h << std::endl;
		GameSettings::setDimensions(800, 600);
		GameEngine JaT("Just a Thought");
		JaT.appLoop();
	}
	else
	{
		std::cout << SDL_GetError() << std::endl;
		std::cout << "The program failed to initialize its libraries. You should do me a solid and report this!" << std::endl;
		shutdown();
		std::cin.get();
		return -1;
	}

	shutdown();
	std::cout << "Program closed, hit enter to terminate";
	std::cin.get();
	return 0;
}


//Load through each component and terminate if any fail
bool initializeLibs()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "SDL2 failed to launch! Error: " << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		SDL_version version;
		SDL_GetVersion(&version);
		std::cout << "The program has linked against SDL version " << (int)version.major << "." << (int)version.minor << "." << (int)version.patch << std::endl;
		int imgFlags = IMG_INIT_PNG;
		if (!((IMG_Init(imgFlags))&imgFlags))
		{
			std::cout << "SDL Image failed to launch! Error: " << IMG_GetError() << std::endl;
			success = false;
		}
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) != 0)
		{
			std::cout << "SDL Mixer failed to open audio mixer! Error: " << Mix_GetError() << std::endl;
			success = false;
			int sndFlags = MIX_INIT_MP3 | MIX_INIT_OGG;
			if ((Mix_Init(sndFlags)&sndFlags) != sndFlags)
			{
				std::cout << "SDL Mixer failed to launch! Error: " << Mix_GetError() << std::endl;
				success = false;
			}
		}
		if (TTF_Init() != 0)
		{
			std::cout << "SDL TTF failed to launch! Error: " << TTF_GetError() << std::endl;
			success = false;
		}
		if (SDLNet_Init() == -1)
		{
			std::cout << "SDL NET failed to launch! Error: " << SDLNet_GetError() << std::endl;
			success = false;
		}
	}
	return success;
}

void shutdown()
{
	SDLNet_Quit();
	TTF_Quit();
	Mix_CloseAudio();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}