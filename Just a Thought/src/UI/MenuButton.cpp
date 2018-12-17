#include "MenuButton.h"

MenuButton::MenuButton(std::string path)
{
	m_sprite = new Jangine::Sprite();
	m_sprite->load(path);
}


MenuButton::~MenuButton()
{
	delete m_sprite;
}


void MenuButton::onHover()
{
	SDL_Rect* rect = m_sprite->getRect();
	m_sprite->setWidthHeight(70, 50);
	m_sprite->setX(x-10);
	m_sprite->setY(y-10);
}


void MenuButton::update()
{

	ButtonBase::update();
	if (mouseInBounds())
		onHover();
	else
	{
		m_sprite->setWidthHeight(50, 30);
		m_sprite->setX(x);
		m_sprite->setY(y);
	}
}


void MenuButton::draw()
{
	m_sprite->draw();
}
