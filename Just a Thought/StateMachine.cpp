#include "StateMachine.h"

StateMachine::StateMachine()
{
	
}

StateMachine::~StateMachine()
{
}

void StateMachine::setState(int state)
{
	if(state != GameState::STATE_NONE)
	{ 
		delete currentState;
		switch (state)
		{
		case GameState::STATE_QUIT:
			break;
		case GameState::STATE_INTRO:
			currentState = new Intro();
			break;
		case GameState::STATE_TITLE:
			currentState = new Title();
			break;
		case GameState::STATE_LEVEL1:
			currentState = new Level1();
			break;
		case GameState::STATE_EDITOR:
			currentState = new Editor();
			break;
		}
		currentState->setRenderer(m_renderer);
		currentState->init();
	}
}

int StateMachine::getNextState()
{
	return currentState->getNextState();
}

void StateMachine::draw()
{
	currentState->draw();
}

void StateMachine::update()
{
	currentState->update();
}

void StateMachine::setRenderer(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}