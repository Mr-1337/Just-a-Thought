#pragma once
#include <string>
#include "ButtonBase.h"
class MenuButton :
	public ButtonBase
{
public:
	MenuButton(SDL_Renderer* renderer, std::string path);
	~MenuButton();
	void draw();
	void update();
private:
	void onHover();
};

