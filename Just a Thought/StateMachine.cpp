#include "StateMachine.h"

StateMachine::StateMachine(SDL_Renderer* renderer):
	m_renderer(renderer)
{
	
}

StateMachine::~StateMachine()
{
	while (!stateStack.empty())
	{
		stateStack.pop();
	}
}

void StateMachine::setState(GameState::StateRequest newState)
{
	if (newState.popCurrent && newState.state != GameState::STATE_NONE)
	{
		stateStack.pop();
		if (newState.popPrev)
		{
			std::cout << "Popping previous state: \n";
			if (!stateStack.empty())
			{
				stateStack.pop();
			}
		}
		else
		{
			if (!stateStack.empty())
				stateStack.top()->revealed();
		}

	}
	switch (newState.state)
	{
	case GameState::STATE_INTRO:
		stateStack.push(std::make_unique<Intro>(m_renderer));
		break;
	case GameState::STATE_TITLE:
		stateStack.push(std::make_unique<Title>(m_renderer));
		break;
	case GameState::STATE_EDITOR:
		stateStack.push(std::make_unique<Editor>(m_renderer));
		break;
	case GameState::STATE_OPTIONS:
		stateStack.push(std::make_unique<OptionScreen>(m_renderer));
		break;
	case GameState::STATE_PAUSE:
		stateStack.push(std::make_unique<PauseMenu>(m_renderer));
		break;
	case GameState::STATE_LEVEL1:
		stateStack.push(std::make_unique<Level1>(m_renderer));
		break;
	}
}

GameState::StateRequest StateMachine::getStateRequest()
{
	return stateStack.top()->getStateRequest();
}

void StateMachine::draw()
{
	stateStack.top()->draw();
}

void StateMachine::update()
{
	//td::cout << stateStack.size() << std::endl;
	stateStack.top()->update();
}