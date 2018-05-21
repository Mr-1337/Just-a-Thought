#pragma once
#include "GameState.h"
#include "UIEditorBar.h"
#include "LevelConverter.h"
#include "Player.h"
#include "Text.h"
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
	
private:
	void drawGrid();

	int columns;
	int rows;
	UIEditorBar* editorBar;
	std::vector < std::vector <char> > tile;
	int mouseX, mouseY;
	int r;
	int tileX, tileY;
	const int size = 20;
	std::vector <Player*> players;
	const SDL_Color color = { 255,0,0,255 };
	Text text;
	SDL_Rect rect;
	UIEditorBar::Tools currentTool;
};