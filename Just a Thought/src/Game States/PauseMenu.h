#pragma once
#include <Game States/GameState.h>
#include <Util/Timer.h>
#include <UI/Slider.h>
#include <Core/GameSettings.h>
#include <SDL_mixer.h>

#include "../UI/MenuButton.h"
class PauseMenu :
	public Jangine::GameState
{
public:
	PauseMenu(std::shared_ptr<GameState> prevState);
	void update(float timestep) override;
	void draw() override;
	~PauseMenu();
private:
	std::shared_ptr<GameState> prevState;
	Jangine::Sprite* sprite;
	Jangine::Timer timer;
	Mix_Music* chunk;
	MenuButton* quit;
	MenuButton* menu;
	Jangine::Slider* volume;
	bool escape;
};

