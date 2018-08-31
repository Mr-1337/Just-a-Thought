#include "Editor.h"

Editor::Editor(SDL_Renderer* renderer) :
	GameState(renderer), columns(40), rows(30), tile(rows, std::vector<char>(columns)), text(renderer, " ")
{
	for (int i = 0; i < rows; i++)
	{
		tile[i].assign(columns, 0);
	}
	SDL_GetMouseState(&mouseX, &mouseY);
	editorBar = new UIEditorBar(m_renderer);
	rect.w = size;
	rect.h = size;
	r = 1;
	text.load("Assets/Font/Halo3.ttf", 30 , color);
}

Editor::~Editor()
{
	int result;
	std::cout << "destroyed editor" << std::endl;
	SDL_MessageBoxButtonData buttonData[2];
	buttonData[0].buttonid = 0;
	buttonData[0].text = "Yes";
	buttonData[1].buttonid = 1;
	buttonData[1].text = "No";

	SDL_MessageBoxData msgData;
	msgData.title = "Unsaved changes";
	msgData.message = "Would you like to save your changes before closing?";
	msgData.colorScheme = NULL;
	msgData.numbuttons = 2;
	msgData.buttons = buttonData;
	msgData.window = NULL;
	msgData.flags = SDL_MESSAGEBOX_WARNING;

	SDL_ShowMessageBox(&msgData, &result);

	if (result == 0)
	{
		LevelConverter saver(tile);
		saver.outputBytes();
	}
	
	delete editorBar;
}

void Editor::update()
{
	editorBar->update();
	currentTool = editorBar->getSelected();
	static bool down = false;
	static bool up = false;
	static bool enter = false;
	static bool space = false;
	tileX = ((mouseX / size) - (r - 1));
	tileY = ((mouseY / size) - (r - 1));

	if (mouseY > 60)
	{
		if (SDL_BUTTON_LMASK == SDL_GetMouseState(&mouseX, &mouseY))
		{
			switch (currentTool)
			{
			case UIEditorBar::TOOL_PENCIL:
				for (int i = 0; i < r * 2 - 1; i++)
				{
					for (int j = 0; j < r * 2 - 1; j++)
					{
						tile[tileY + i][tileX + j] = 2;
					}
				}
				break;
			case UIEditorBar::TOOL_ERASER:
				for (int i = 0; i < r * 2 - 1; i++)
				{
					for (int j = 0; j < r * 2 - 1; j++)
					{
						tile[tileY + i][tileX + j] = 0;
					}
				}
				break;
			case UIEditorBar::TOOL_HAND:
				for (int i = 0; i < r * 2 - 1; i++)
				{
					for (int j = 0; j < r * 2 - 1; j++)
					{
						tile[tileY + i][tileX + j] = 1;
					}
				}
				break;
			case UIEditorBar::TOOL_PLAYER:
				players.push_back(new Player(m_renderer, tile));
				break;
			}
		}
	}
	else
	{
		SDL_GetMouseState(&mouseX, &mouseY);
	}

	if (!players.empty())
	{
		for (Player* player : players)
		{
			player->update();
		}
	}

	const Uint8* keys = SDL_GetKeyboardState(NULL);
	if(keys[SDL_SCANCODE_DOWN] && !down && r > 1)
	{
		down = true;
		r--;
		std::cout << r << std::endl;
	}
	if (!keys[SDL_SCANCODE_DOWN] && down)
	{
		down = false;
	}
	if (keys[SDL_SCANCODE_UP] && !up)
	{
		up = true;
		r++;
		std::cout << r << std::endl;
	}
	if (!keys[SDL_SCANCODE_UP] && up)
	{
		up = false;
	}
	if (currentTool == UIEditorBar::TOOL_FILE)
	{
		if (keys[SDL_SCANCODE_RETURN] && !enter)
		{
			enter = true;
			LevelConverter converter(tile);
			converter.outputBytes();
			converter.printBytes();
		}
		if (!keys[SDL_SCANCODE_RETURN] && enter)
		{
			enter = false;
		}
		if (keys[SDL_SCANCODE_SPACE] && !space)
		{
			space = true;
			LevelConverter converter(tile);
			converter.openFile("Assets/Graphics/level1.jatmap");
			converter.loadBytes();
		}
		if (!keys[SDL_SCANCODE_SPACE] && space)
		{
			space = false;
		}
	}
}

void Editor::draw()
{
	SDL_SetRenderDrawColor(m_renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderClear(m_renderer);
	rect.w = size;
	rect.h = size;
	for (int i = 0;i < rows;i++)
	{
		for (int j = 0;j < columns;j++)
		{
			rect.x = size * j;
			rect.y = size * i;
			switch (tile[i][j])
			{
			case 1:
				SDL_SetRenderDrawColor(m_renderer, 0xff, 0x00, 0x00, 0xff);
				SDL_RenderFillRect(m_renderer, &rect);
				break;
			case 2:
				SDL_SetRenderDrawColor(m_renderer, 0x00, 0xff, 0x00, 0xff);
				SDL_RenderFillRect(m_renderer, &rect);
				break;
			}
		}		
	}
	rect.w = 2 * size * (r-1) + size;
	rect.h = 2 * size * (r-1) + size;
	if (mouseY > 60)
	{
		SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x33, 0x88);
	}
	else
	{
		SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x33, 0x00);
	}
	rect.x = ((mouseX / size) * size) - (size * (r-1));
	rect.y = ((mouseY / size) * size) - (size * (r-1));
	SDL_RenderFillRect(m_renderer, &rect);
	drawGrid();
	editorBar->draw();
	text.updateText(std::to_string(players.size()), color);
	text.draw();
	if (!players.empty())
	{
		for (Player* player : players)
		{
			player->draw();
		}
	}

	SDL_RenderPresent(m_renderer);
}

void Editor::drawGrid()
{
	SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0x22);
	for (int i = 0;i < 52;i++)
	{
		SDL_RenderDrawLine(m_renderer, size * i, 0,size * i, 768);
	}
	for (int i = 0;i < 39;i++)
	{
		SDL_RenderDrawLine(m_renderer, 0, size * i, 1024, size * i);
	}
}