#pragma once
#include "GameState.h"
#include "../Gameplay/Player.h"
#include "../IO/LevelConverter.h"
#include "../Graphics/Text.h"
#include "../Util/Timer.h"
#include "../Gameplay/Enemy.h"
#include "../Gameplay/GameWorld.h"
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
	SDL_Rect rect;
	bool escape;
	Camera m_cam;
	GameWorld gameWorld;
};

