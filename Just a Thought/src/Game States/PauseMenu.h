#pragma once
#include "GameState.h"
#include "../Core/Timer.h"
#include "../UI/MenuButton.h"
#include "../UI/Slider.h"
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

