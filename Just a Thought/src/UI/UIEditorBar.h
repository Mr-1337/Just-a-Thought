#pragma once
#include <UI/UIContainer.h>
#include <Core/GameSettings.h>
#include "../UI/UIEditorBarButton.h"
class UIEditorBar:
	public Jangine::UIContainer
{
public:
	UIEditorBar();
	~UIEditorBar();

	enum Tools
	{
		TOOL_FILE,
		TOOL_PENCIL,
		TOOL_ERASER,
		TOOL_HAND,
		TOOL_PLAYER
	};

	void update() override;
	void draw() override;
	void SetX(int X);
	void SetY(int Y);
	Tools getSelected();

private:
	SDL_Rect m_drawRect;
	std::shared_ptr<UIEditorBarButton> File;
	std::shared_ptr<UIEditorBarButton> Pencil;
	std::shared_ptr<UIEditorBarButton> Eraser;
	std::shared_ptr<UIEditorBarButton> Hand;
	std::shared_ptr<UIEditorBarButton> Player;
	int x, y;
	SDL_Rect highlight;
	Tools currentTool;
};

