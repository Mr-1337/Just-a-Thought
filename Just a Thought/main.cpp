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

#include "GameEngine.h"
//Main cpp file. This is the program that gets called by the OS. It all starts here.

//Loads SDL + accompanying libraries
bool initialize();
//Unloads SDL libraries
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
	
	if (initialize())
	{
		std::cout << "Initialization succeeded! Starting the game." << std::endl;
		GameSettings::setDimensions(1024, 768);
		GameEngine JaT;
		JaT.appLoop();
	}
	else
	{
		std::cout << SDL_GetError() << std::endl;
		std::cout << "The program failed to initialize, terminating. You should do me a solid and report this!" << std::endl;
		shutdown();
		return -1;
	}

	shutdown();
	std::cout << "Program closed, hit enter to terminate";
	std::cin.get();
	return 0;
}


//Load through each component and terminate if any fail
bool initialize()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_EVERYTHING != 0))
	{
		std::cout << "SDL2 failed to launch! Error: " << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags)&imgFlags))
		{
			std::cout << "SDL Image failed to launch! Error: " << IMG_GetError() << std::endl;
			success = false;
		}
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != 0)
		{
			std::cout << "SDL Mixer failed to launch! Error: " << Mix_GetError() << std::endl;
			success = false;
		}
		if (TTF_Init() != 0)
		{
			std::cout << "SDL TTF failed to launch! Error: " << TTF_GetError() << std::endl;
			success = false;
		}
	}
	return success;
}

void shutdown()
{
	TTF_Quit();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}