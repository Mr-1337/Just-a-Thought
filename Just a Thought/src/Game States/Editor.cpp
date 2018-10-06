#include "Editor.h"

Editor::Editor(SDL_Renderer* renderer) :
	GameState(renderer)
{
	SDL_GetMouseState(&mouseX, &mouseY);
	editorBar = new UIEditorBar(m_renderer);
	m_world = new GameWorld("Graphics/Assets/level1.jatmap", m_renderer, m_cam, 30, 40);
	m_cursorHighlight.w = size;
	m_cursorHighlight.h = size;
	m_brushR = 1;
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

	}
	
	delete editorBar;
	delete m_world;
}

void Editor::update()
{
	editorBar->update();
	currentTool = editorBar->getSelected();

	tileX = (((mouseX)/ size) - (m_brushR - 1));
	tileY = (((mouseY)/ size) - (m_brushR - 1));

	if (mouseY > 60)
	{
		if (SDL_BUTTON_LMASK == SDL_GetMouseState(&mouseX, &mouseY))
		{
			switch (currentTool)
			{
			case UIEditorBar::TOOL_PENCIL:
				paint(1);
				break;
			case UIEditorBar::TOOL_ERASER:
				paint(0);
				break;
			case UIEditorBar::TOOL_HAND:
				m_cam += m_dragMotion;
				break;
			case UIEditorBar::TOOL_PLAYER:
				paint(2);
				break;
			}
		}
	}
	else
	{
		SDL_GetMouseState(&mouseX, &mouseY);
	}

	m_dragMotion = { 0, 0 };

	if (currentTool == UIEditorBar::TOOL_FILE)
	{
		
	}
}

void Editor::draw()
{
	SDL_SetRenderDrawColor(m_renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderClear(m_renderer);

	m_world->draw();

	if (mouseY > 60)
	{
		SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x33, 0x88);
	}
	else
	{
		SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x33, 0x00);
	}
	
	drawHighlight();
	drawGrid();
	editorBar->draw();

	SDL_RenderPresent(m_renderer);
}


void Editor::paint(char value)
{
	for (int i = tileY; i <= (tileY + 2 * (m_brushR-1)); i++)
	{
		for (int j = tileX; j <= (tileX + 2 * (m_brushR - 1)); j++)
		{
			m_world->setData(j, i, value);
		}
	}
}


void Editor::eventHandler()
{
	while (SDL_PollEvent(&m_event) != 0)
	{
		switch (m_event.type)
		{
		case SDL_QUIT:
			request.state = STATE_QUIT;
			break;
		case SDL_KEYDOWN:
			if (!m_event.key.repeat)
			{
				switch (m_event.key.keysym.scancode)
				{
				case SDL_SCANCODE_UP:
					m_brushR++;
					break;
				case SDL_SCANCODE_DOWN:
					if (m_brushR > 1) 
						m_brushR--;
					break;
				}
			}
			break;
		case SDL_MOUSEMOTION:
			m_dragMotion.first = -m_event.motion.xrel;
			m_dragMotion.second = -m_event.motion.yrel;
			break;
		}
	}
}

void Editor::drawHighlight()
{
	m_cursorHighlight.w = size + 2 * size * (m_brushR-1);
	m_cursorHighlight.h = size + 2 * size * (m_brushR - 1);

	m_cursorHighlight.x = tileX * size - m_cam.getPos().first%size;
	m_cursorHighlight.y = tileY * size - m_cam.getPos().second%size;
	SDL_RenderFillRect(m_renderer, &m_cursorHighlight);
}

void Editor::drawGrid()
{
	SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0x22);
	for (int i = 0;i < 52;i++)
	{
		SDL_RenderDrawLine(m_renderer, size * i - m_cam.getPos().first%size, 0, size * i - m_cam.getPos().first%size, 768);
	}
	for (int i = 0;i < 39;i++)
	{
		SDL_RenderDrawLine(m_renderer, 0, size * i - m_cam.getPos().second%size, 1024, size * i - m_cam.getPos().second%size);
	}
}