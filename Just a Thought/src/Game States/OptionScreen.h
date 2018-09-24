#pragma once
#include "GameState.h"
#include "../UI/Slider.h"
class OptionScreen :
	public GameState
{
public:
	OptionScreen(SDL_Renderer* renderer);
	void draw() override;
	void update() override;
	~OptionScreen();
private:
	bool escape;
	Slider* volume;
};

