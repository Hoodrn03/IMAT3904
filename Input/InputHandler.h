#pragma once
#include <map>
#include "GameObject.h"
#include <vector>

#define COLOUR_ADJUSTMENT_VALUE 0.001f

class InputCommand
{
public:
	virtual ~InputCommand() {}
	virtual void execute(GameObject& playerBackground) = 0;
};

class IncreaseRedCommand : public InputCommand
{
public:
	void execute(GameObject& playerBackground) override { playerBackground.r += COLOUR_ADJUSTMENT_VALUE; }
};

class DecreaseRedCommand : public InputCommand
{
public:
	void execute(GameObject& playerBackground) override { playerBackground.r -= COLOUR_ADJUSTMENT_VALUE; }
};

struct InputHandler
{	
	GameObject* m_playerBackground;
	std::map<int, InputCommand*> m_controlMapping;

	

	InputHandler(GameObject* playerBackground) : m_playerBackground(playerBackground)
	{
		// the idea will be to map the keys directly from a config file that can be loaded in
		// and changed on the fly
		m_controlMapping[65] = new IncreaseRedCommand;
		m_controlMapping[90] = new DecreaseRedCommand;
	}

	void handleInputs(const std::vector<bool>& keyBuffer)
	{
		for(const auto& mapEntry : m_controlMapping)
		{
			if(keyBuffer[mapEntry.first])
			{
				mapEntry.second->execute(*m_playerBackground);
			}
		}

	}
};
