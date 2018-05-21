#pragma once
#include "GameState.h"
#include "Player.h"
#include "LevelConverter.h"
#include "Text.h"
#include "Timer.h"

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
	std::vector< std::vector <char> > tiles;
	SDL_Rect rect;
	const int size = 20;
	std::string fps;
	Text Counter;
	SDL_Color fontColor;
	Timer fpsTimer;
};

