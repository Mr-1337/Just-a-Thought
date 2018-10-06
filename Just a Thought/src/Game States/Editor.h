#pragma once
#include "GameState.h"
#include "../UI/UIEditorBar.h"
#include "../IO/LevelConverter.h"
#include "../Gameplay/GameWorld.h"
#include "../Gameplay/Player.h"
#include "../Graphics/Text.h"
#include "../Graphics/Camera.h"
#include <SDL_mixer.h>
#include <random>

class Editor :
	public GameState
{
public:
	Editor(SDL_Renderer* renderer);
	~Editor();
	void update() override;
	void draw() override;
	void eventHandler() override;
	
private:
	void drawGrid();
	void drawHighlight();
	void paint(char value);

	UIEditorBar* editorBar;
	GameWorld* m_world;
	int mouseX, mouseY;
	int m_brushR;
	int tileX, tileY;
	std::pair<int, int> m_dragMotion;
	const int size = 20;
	SDL_Rect m_cursorHighlight;
	UIEditorBar::Tools currentTool;
	Camera m_cam;
};