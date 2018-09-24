#pragma once
#include "GameState.h"
#include "../Gameplay/Player.h"
#include "../IO/LevelConverter.h"
#include "../Graphics/Text.h"
#include "../Core/Timer.h"
#include "../Gameplay/Enemy.h"
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
	std::vector< std::vector <char> > tiles;
	SDL_Rect rect;
	const int size = 20;
	bool escape;
	std::string fps;
	int frame;
	Text Counter;
	SDL_Color fontColor;
	Timer fpsTimer;
	Enemy* enemy;
};

