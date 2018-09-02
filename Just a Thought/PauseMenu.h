#pragma once
#include "GameState.h"
#include "Timer.h"
#include "MenuButton.h"
#include "Slider.h"
#include <SDL_mixer.h>
class PauseMenu :
	public GameState
{
public:
	PauseMenu(SDL_Renderer* renderer);
	void update() override;
	void draw() override;
	~PauseMenu();
private:
	Sprite* sprite;
	Timer timer;
	Mix_Music* chunk;
	MenuButton* quit;
	MenuButton* menu;
	Slider* volume;
	bool escape;
};
