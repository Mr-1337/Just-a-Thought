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
//Unloads SDL libraries + accompanying libraries
void shutdown();
void audio();

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
		//audio();
		int choice;	
		std::cout << "1: Client" << std::endl << "2: Host" << std::endl;
		std::cin >> choice;
		if (choice == 1)
		{
			IPaddress ip;
			std::cout << SDLNet_ResolveHost(&ip, "73.186.46.157", 25570) << std::endl;
			UDPsocket sock = SDLNet_UDP_Open(0);
			UDPpacket packet;
			packet.address = ip;
			if (sock == NULL)
				std::cout << SDLNet_GetError() << std::endl;
			else
			{
				while (true)
				{
					std::string data;
					std::cin >> data;
					packet.maxlen = 300;
					packet.len = sizeof(data.c_str());
					packet.data = (Uint8*)data.c_str();
					if (SDLNet_UDP_Send(sock, -1, &packet) == 0)
					{
						std::cout << SDLNet_GetError() << std::endl;
					}
				}
			}
		}
		else if (choice == 2)
		{
			IPaddress ip;
			std::cout << SDLNet_ResolveHost(&ip, NULL, 25570) << std::endl;
			TCPsocket sock = SDLNet_TCP_Open(&ip);
			TCPsocket rec;
			if (sock == NULL)
				std::cout << SDLNet_GetError() << std::endl;
			else
			{
				while (true)
				{
					rec = SDLNet_TCP_Accept(sock);
					if (rec != NULL)
						break;
				}
				std::cout << "WE RECEIVED A CONNECTION!" << std::endl;
				char data[30];
				while (true)
				{
					int res = SDLNet_TCP_Recv(rec, data, 30);
					if (res < 0)
						std::cout << SDLNet_GetError() << std::endl;
					if (res > 0)
						break;
				}
				for (char i : data)
				{
					std::cout << i;
				}
				std::cout << std::endl;
			}
			
		}
		else
		{
			std::cout << "WRONG WRONG WRONG WRONG WRONG YOU BROKE IT" << std::endl;
		}
		std::cout << "Initialization succeeded! Starting the game." << std::endl;
		GameSettings::setDimensions(800, 600);
		
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
	std::cin.get();
	return 0;
}

void audio()
{
	SDL_AudioSpec want, have;
	SDL_AudioDeviceID mic,speakers;

	int const size = 10000;
	float data[size];

	SDL_memset(&want, 0, sizeof(want)); /* or SDL_zero(want) */
	want.freq = 44100;
	want.format = AUDIO_F32;
	want.channels = 2;
	want.samples = 4096;
	want.callback = NULL; /* you wrote this function elsewhere -- see SDL_AudioSpec for details */
	const char* sp = SDL_GetAudioDeviceName(0, 0); 
	const char* mc = SDL_GetAudioDeviceName(1, 1);
	std::cout << mc << std::endl << sp << std::endl;
	speakers = SDL_OpenAudioDevice(sp, 0, &want, &have, SDL_AUDIO_ALLOW_FORMAT_CHANGE);
	mic = SDL_OpenAudioDevice(mc, 1, &want, &have, SDL_AUDIO_ALLOW_FORMAT_CHANGE);
	SDL_PauseAudioDevice(speakers, 0); /* start audio playing. */
	SDL_PauseAudioDevice(mic, 0);

	while (true)
	{
		SDL_DequeueAudio(mic, data, size * sizeof(data[0]));
		SDL_QueueAudio(speakers, data, size * sizeof(data[0])); /* let the audio callback play some sound for 5 seconds. */
		SDL_Delay(5);
		SDL_ClearQueuedAudio(speakers);
	}

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
		std::cout << (int)version.major << "." << (int)version.minor << "." << (int)version.patch << std::endl;
		int imgFlags = IMG_INIT_PNG;
		if (!((IMG_Init(imgFlags))&imgFlags))
		{
			std::cout << "SDL Image failed to launch! Error: " << IMG_GetError() << std::endl;
			success = false;
		}
		int sndFlags = MIX_INIT_MP3 | MIX_INIT_OGG;
		if ((Mix_Init(sndFlags)&sndFlags) != sndFlags)
		{
			std::cout << "SDL Mixer failed to launch! Error: " << Mix_GetError() << std::endl;
		}
		else
		{
			if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) != 0)
			{
				std::cout << "SDL Mixer failed to open audio mixer! Error: " << Mix_GetError() << std::endl;
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