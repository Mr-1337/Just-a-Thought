#include "UIEditorBar.h"



UIEditorBar::UIEditorBar(SDL_Renderer* renderer)
	:UIContainer(renderer)
{

	int w, h; 
	GameSettings::getDimensions(&w, &h);
	m_drawRect.w = w;
	m_drawRect.h = h*0.1;
	m_drawRect.x = 0;
	m_drawRect.y = 0;

	File = new UIEditorBarButton(renderer, "Assets/Graphics/save.png");
	Pencil = new UIEditorBarButton(renderer, "Assets/Graphics/pencil.png");
	Eraser = new UIEditorBarButton(renderer, "Assets/Graphics/eraser.png");
	Hand = new UIEditorBarButton(renderer, "Assets/Graphics/hand.png");
	Player = new UIEditorBarButton(renderer, "Assets/Graphics/guy.png");

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
	delete File;
	delete Pencil;
	delete Eraser;
	delete Hand;
	delete Player;
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
	if (File->click())
	{
		currentTool = TOOL_FILE;
	}
	if (Pencil->click())
	{
		currentTool = TOOL_PENCIL;
	}
	if (Eraser->click())
	{
		currentTool = TOOL_ERASER;
	}
	if (Hand->click())
	{
		currentTool = TOOL_HAND;
	}
	if (Player->click())
	{
		currentTool = TOOL_PLAYER;
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