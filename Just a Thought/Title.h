#pragma once
#include "GameState.h"
#include "GameSettings.h"
#include "MenuButton.h"
class Title :
	public GameState
{
public:
	Title(SDL_Renderer* renderer);
	~Title();
	void update();
	void draw();

private:
	Sprite* menu;

	MenuButton* m_play;
	MenuButton* m_quit;
	MenuButton* m_options;
};

