#pragma once
#include <Game States/GameState.h>
#include <UI/Slider.h>
class OptionScreen :
	public Jangine::GameState
{
public:
	OptionScreen();
	void draw() override;
	void update(float timestep) override;
	~OptionScreen();
private:
	bool escape;
	Jangine::Slider* volume;
};

