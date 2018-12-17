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

	MenuButton* m_playButton;
	MenuButton* m_quitButton;
	MenuButton* m_optionsButton;
	MenuButton* m_editorButton;
};

