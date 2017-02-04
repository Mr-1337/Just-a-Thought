/*
Created February 3rd 2017 by Mr. 1337
This is my first real project that I have put a lot of thought and work into, and hopefully I can make something special
This is also a spiritual successor to "platformgame.swf", an earlier project. Some of you may probably remember that abomination, but it was my first attempt at something like this.
I know that this probably won't be the magnum opus that I'd really like it to be, but one can dream right?
*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

//Loads and unloads SDL + accompanying libraries
bool initialize();
void shutdown();

int main(int argc, char* args[])
{
	std::cout << "Welcome to the console for Just a Thought!" << std::endl << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::vector<std::string> quotes(15);
	std::srand(static_cast<int>(time(nullptr)));
	quotes = {
		"We are shaped by our thoughts; we become what we think. When the mind is pure, joy follows like a shadow that never leaves.",
		"It is the mark of an educated mind to be able to entertain a thought without accepting it.",
		"For every minute you remain angry, you give up sixty seconds of peace of mind.",
		"The face is the mirror of the mind, and eyes without speaking confess the secrets of the heart.",
		"You cannot have a positive life and a negative mind.",
		"The mind is everything. What you think you become.",
		"As a single footstep will not make a path on the earth, so a single thought will not make a pathway in the mind. To make a deep physical path, we walk again and again. To make a deep mental path, we must think over and over the kind of thoughts we wish to dominate our lives.",
		"It is a man's own mind, not his enemy or foe, that lures him to evil ways.",
		"JUST DO IT! DON'T LET YOUR DREAMS BE DREAMS!",
		"There are no constraints on the human mind, no walls around the human spirit, no barriers to our progress except those we ourselves erect.",
		"Do you even lift potatoes?",
		"Alert! Snert Gfun Ahead!",
		"Straight otta da boom!",
		"You need to stop with these walrus memes.",
		"Its'ah HIIIIIIIIIIIIIIIIIGH NOOOOOOOOOOOOOOOOOOOOOOOOOON"
	};
	//Loads and displays a random quote
	std::cout << quotes[std::rand() % 15] << std::endl;

	if (initialize())
	{
		//Initialization succeeded, so launch the game
		std::cout << "Initialization succeeded!" << std::endl;
	}
	else
	{
		std::cout << "The program failed to initialize, terminating";
		shutdown();
		return -1;
	}

	Mix_Music* music;
	music = Mix_LoadMUS("assets/music.wav");
	std::cout << Mix_GetError();
	Mix_PlayMusic(music, 2);

	std::cin.get();
	shutdown();
	return 0;
}


//Load through each component and return false if any fail
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
		}
	}
	return success;
}

void shutdown()
{
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}