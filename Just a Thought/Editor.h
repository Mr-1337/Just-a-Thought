#pragma once
#include "GameState.h"
#include <random>

class Editor :
	public GameState
{
public:
	Editor();
	~Editor();
	void update();
	void draw();
	void init();
private:
	void drawGrid();
	int tile[39][52];
	int mouseX, mouseY;
	int r;
	SDL_Rect rect;
};