#pragma once
#include <Game States/GameState.h>
#include <Util/Timer.h>
#include <Graphics/Text.h>
#include <SDL_net.h>

#include "../Gameplay/Player.h"
#include "../IO/LevelConverter.h"
#include "../Gameplay/Enemy.h"
#include "../Gameplay/GameWorld.h"

class Level1 :
	public Jangine::GameState
{
public:
	Level1();
	~Level1();
	void update(float timestep) override;
	void draw() override;
	void revealed() override;

private:
	Player* m_player;
	SDL_Rect rect;
	Mix_Music* m_music;
	bool escape;
	Jangine::Camera m_cam;
	GameWorld gameWorld;
};

