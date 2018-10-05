#pragma once

#include<utility>
#include "../Core/GameSettings.h"

class Camera
{
public:
	Camera();
	~Camera();

	std::pair<int, int> getPos() const;
	void operator+=(std::pair<int, int> pos);
	void follow(std::pair<int, int> pos);

private:
	std::pair<int, int> m_pos;
	int w, h;
};

