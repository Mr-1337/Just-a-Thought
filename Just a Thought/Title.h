#pragma once
#include "GameState.h"
class Title :
	public GameState
{
public:
	Title();
	~Title();
	void update();
	void draw();
	void init();

private:
	Sprite* menu;
};

