#include "UIEditorBar.h"

UIEditorBar::UIEditorBar()
{

	int w, h; 
	Jangine::GameSettings::getDimensions(&w, &h);
	m_drawRect.w = w;
	m_drawRect.h = h/10;
	m_drawRect.x = 0;
	m_drawRect.y = 0;

	File   = std::make_shared<UIEditorBarButton>("Assets/Graphics/save.png");
	Pencil = std::make_shared<UIEditorBarButton>("Assets/Graphics/pencil.png");
	Eraser = std::make_shared<UIEditorBarButton>("Assets/Graphics/eraser.png");
	Hand   = std::make_shared<UIEditorBarButton>("Assets/Graphics/hand.png");
	Player = std::make_shared<UIEditorBarButton>("Assets/Graphics/guy.png");

	File->onClick = [this]() { currentTool = TOOL_FILE; };
	Pencil->onClick = [this]() { currentTool = TOOL_PENCIL; };
	Eraser->onClick = [this]() { currentTool = TOOL_ERASER; };
	Hand->onClick = [this]() { currentTool = TOOL_HAND; };
	Player->onClick = [this]() { currentTool = TOOL_PLAYER; };

	children.push_back(File);
	children.push_back(Pencil);
	children.push_back(Eraser);
	children.push_back(Hand);
	children.push_back(Player);

	highlight.w = 40;
	highlight.h = 40;
	highlight.x = 20;
	highlight.y = 10;
	currentTool = TOOL_FILE;

}


UIEditorBar::~UIEditorBar()
{
}


void UIEditorBar::SetX(int X)
{
	x = X;
}


void UIEditorBar::SetY(int Y)
{
	y = Y;
}


UIEditorBar::Tools UIEditorBar::getSelected()
{
	return currentTool;
}

void UIEditorBar::draw()
{
	SDL_SetRenderDrawColor(m_renderer, 127, 127, 127, 127);
	SDL_RenderFillRect(m_renderer, &m_drawRect);
	SDL_SetRenderDrawColor(m_renderer, 255, 127, 37, 127);
	SDL_RenderFillRect(m_renderer, &highlight);
	if (!children.empty())
	{	
		int i = 0;
		for (iter = children.begin(); iter < children.end(); iter++)
		{	
			(*iter)->setX(20+x+120*i);
			(*iter)->setY(y+10);
			(*iter)->draw();
			i++;
		}
	}
}


void UIEditorBar::update()
{
	m_drawRect.x = x;
	m_drawRect.y = y;
	
	for (iter = children.begin(); iter < children.end(); iter++)
	{
		(*iter)->update();
	}
	switch (currentTool)
	{
	case TOOL_FILE:
		highlight.x = 20;
		break;
	case TOOL_PENCIL:
		highlight.x = 140;
		break;
	case TOOL_ERASER:
		highlight.x = 260;
		break;
	case TOOL_HAND:
		highlight.x = 380;
		break;
	case TOOL_PLAYER:
		highlight.x = 500;
		break;

	}

}