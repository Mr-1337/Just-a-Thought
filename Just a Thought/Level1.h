#pragma once
#include "GameState.h"
#include "Player.h"
#include "LevelConverter.h"
#include "Text.h"
#include "Timer.h"
#include <SDL_net.h>

class Level1 :
	public GameState
{
public:
	Level1(SDL_Renderer* renderer);
	~Level1();
	void update() override;
	void draw() override;

private:
	Player* m_player;
	Player* m_player2;
	std::vector< std::vector <char> > tiles;
	SDL_Rect rect;
	const int size = 20;
	std::string fps;
	Text Counter;
	SDL_Color fontColor;
	Timer fpsTimer;
	IPaddress ip;
	UDPsocket client;
	UDPpacket packet;
};

