#include "Camera.h"



Camera::Camera() : m_pos({ 0, 0})
{
	GameSettings::getDimensions(&w, &h);
}


Camera::~Camera()
{
}


std::pair<int, int> Camera::getPos() const
{
	return m_pos;
}


void Camera::operator+=(std::pair<int, int> pos)
{
	m_pos.first += pos.first;
	m_pos.second += pos.second;
}


void Camera::follow(std::pair<int, int> pos)
{
	int dx = pos.first - m_pos.first; 
	int dy = pos.second - m_pos.second;

	*this += { (dx - w / 2) / 8, (dy - h / 2) / 8};

}
