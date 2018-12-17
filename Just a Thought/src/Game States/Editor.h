#pragma once
#include <Game States/GameState.h>
#include <Graphics/Text.h>
#include <Graphics/Camera.h>
#include <SDL_mixer.h>
#include <random>

#include "../UI/UIEditorBar.h"
#include "../IO/LevelConverter.h"
#include "../Gameplay/GameWorld.h"
#include "../Gameplay/Player.h"

class Editor :
	public Jangine::GameState
{
public:
	Editor();
	~Editor();
	void update(float timestep) override;
	void draw() override;
	void eventHandler() override;
	
private:
	void drawGrid();
	void drawHighlight();
	void paint(char value);

	UIEditorBar* editorBar;
	GameWorld* m_world;
	Jangine::Text* m_coords;
	int mouseX, mouseY;
	int m_brushR;
	int tileX, tileY;
	std::pair<int, int> m_dragMotion;
	const int size = 20;
	SDL_Rect m_cursorHighlight;
	UIEditorBar::Tools currentTool;
	Jangine::Camera m_cam;
};