#pragma once
#include "UIContainer.h"
#include "GameSettings.h"
#include "UIEditorBarButton.h"
class UIEditorBar:
	public UIContainer
{
public:
	UIEditorBar(SDL_Renderer* renderer);
	~UIEditorBar();

	enum Tools
	{
		TOOL_FILE,
		TOOL_PENCIL,
		TOOL_ERASER,
		TOOL_HAND,
		TOOL_PLAYER
	};

	void update();
	void draw();
	void SetX(int X);
	void SetY(int Y);
	Tools getSelected();

private:
	SDL_Rect m_drawRect;
	UIEditorBarButton* File;
	UIEditorBarButton* Pencil;
	UIEditorBarButton* Eraser;
	UIEditorBarButton* Hand;
	UIEditorBarButton* Player;
	int x, y;
	SDL_Rect highlight;
	Tools currentTool;
};

