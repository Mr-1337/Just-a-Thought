#pragma once
#include <string>
#include <UI/ButtonBase.h>
class MenuButton :
	public Jangine::ButtonBase
{
public:
	MenuButton(std::string path);
	~MenuButton();
	void draw() override;
	void update() override;
private:
	void onHover() override;
};

