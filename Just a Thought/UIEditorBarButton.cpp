#include "UIEditorBarButton.h"



UIEditorBarButton::UIEditorBarButton(SDL_Renderer* renderer, std::string path)
	:ButtonBase(renderer)
{
	m_sprite->load(path);
}


UIEditorBarButton::~UIEditorBarButton()
{
}


void UIEditorBarButton::onHover()
{
	alpha = 50;
}


void UIEditorBarButton::draw()
{
	SDL_SetRenderDrawColor(m_renderer, 0xff, 0xff, 0xff, alpha);
	SDL_RenderFillRect(m_renderer, m_sprite->getRect());
	m_sprite->draw();
}


void UIEditorBarButton::update()
{
	if (mouseInBounds())
	{
		onHover();	
	}
	else
	{
		alpha = 0;
	}
}