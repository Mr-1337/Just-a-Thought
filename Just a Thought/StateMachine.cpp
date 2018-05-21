#include "StateMachine.h"

StateMachine::StateMachine(SDL_Renderer* renderer):
	m_renderer(renderer)
{
	
}

StateMachine::~StateMachine()
{
	delete currentState;
}

void StateMachine::setState(GameState::states newState)
{
	if(newState != GameState::STATE_NONE && newState != GameState::STATE_QUIT)
	{ 
		delete currentState;
		switch (newState)
		{
		case GameState::STATE_INTRO:
			currentState = new Intro(m_renderer);
			break;
		case GameState::STATE_TITLE:
			currentState = new Title(m_renderer);
			break;
		case GameState::STATE_LEVEL1:
			currentState = new Level1(m_renderer);
			break;
		case GameState::STATE_EDITOR:
			currentState = new Editor(m_renderer);
			break;
		}
	}
}

GameState::states StateMachine::getNextState()
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