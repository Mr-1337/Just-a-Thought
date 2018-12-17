#pragma once
#include <Game States/GameState.h>
#include <Core/GameSettings.h>

#include "../UI/MenuButton.h"
class Title :
	public Jangine::GameState
{
public:
	Title();
	~Title();
	void update(float timestep) override;
	void draw() override;

private:
	Jangine::Sprite* menu;

	MenuButton* m_play;
	MenuButton* m_quit;
	MenuButton* m_options;
	MenuButton* m_editor;
};

