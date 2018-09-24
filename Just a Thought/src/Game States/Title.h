#pragma once
#include "GameState.h"
#include "../Core/GameSettings.h"
#include "../UI/MenuButton.h"
class Title :
	public GameState
{
public:
	Title(SDL_Renderer* renderer);
	~Title();
	void update() override;
	void draw() override;

private:
	Sprite* menu;

	MenuButton* m_play;
	MenuButton* m_quit;
	MenuButton* m_options;
	MenuButton* m_editor;
};

