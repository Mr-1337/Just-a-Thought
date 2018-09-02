#pragma once
#include "UIElement.h"
#include "ButtonBase.h"
class UIEditorBarButton :
	public ButtonBase
{
public:
	UIEditorBarButton(SDL_Renderer* renderer, std::string path);
	~UIEditorBarButton();

	void draw() override;
	void update() override;
private:
	void onHover() override;
	int alpha;
};

