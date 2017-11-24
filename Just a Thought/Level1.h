#pragma once
#include "GameState.h"
#include "Player.h"
#include "LevelConverter.h"

class Level1 :
	public GameState
{
public:
	Level1();
	~Level1();
	void update();
	void draw();
	void init();
	void outputPixels();

private:
	Player* m_player;
	Sprite* m_ground;

};

