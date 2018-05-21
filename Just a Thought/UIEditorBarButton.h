#pragma once
#include "UIElement.h"
#include "ButtonBase.h"
class UIEditorBarButton :
	public ButtonBase
{
public:
	UIEditorBarButton(SDL_Renderer* renderer, std::string path);
	~UIEditorBarButton();

	void draw();
	void update();
private:
	void onHover();
	int alpha;
};

