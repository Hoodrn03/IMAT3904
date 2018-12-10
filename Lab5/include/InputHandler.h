#pragma once
#include <map>
#include "GameObject.h"
#include <vector>
#include "TransformComponent.h"


class InputCommand
{
public:
	virtual ~InputCommand() {}
	virtual void execute(GameObject& playerBackground) = 0;

	float m_fRotateAmount = 0.05f;
	float m_fScaleUpAmount = 0.05f; 
	float m_fMoveAmount = 0.05f; 
};


/*! \class A class wich will be used to handle a single input item : This will roll the cube left. */
class RotateLeftCommand : public InputCommand
{
	void execute(GameObject& playerBackground) override { playerBackground.getComponent<TransformComponent>()->roll(-m_fRotateAmount); }
};

/*! \class A class wich will be used to handle a single input item : This will roll the cube right. */
class RotateRightCommand : public InputCommand
{
	void execute(GameObject& playerBackground) override { playerBackground.getComponent<TransformComponent>()->roll(m_fRotateAmount); }
};

class ScaleUpCommand : public InputCommand
{
	void execute(GameObject& playerBackground) override { playerBackground.getComponent<TransformComponent>()->scaleUp(m_fScaleUpAmount, 0, 0); }
};

class ScaleDownCommand : public InputCommand
{
	void execute(GameObject& playerBackground) override { playerBackground.getComponent<TransformComponent>()->scaleUp(-m_fScaleUpAmount, 0, 0); }
};

class TranslateLeftCommand : public InputCommand
{
	void execute(GameObject& playerBackground) override { playerBackground.getComponent<TransformComponent>()->translate(-m_fMoveAmount, 0, 0); }
};

class TranslateRightCommand : public InputCommand
{
	void execute(GameObject& playerBackground) override { playerBackground.getComponent<TransformComponent>()->translate(m_fMoveAmount, 0, 0); }
};

struct InputHandler
{	
	GameObject* m_playerCube;

	std::map<int, InputCommand*> m_controlMapping;

	InputHandler(GameObject* playerCube) : m_playerCube(playerCube)
	{
		// the idea will be to map the keys directly from a config file that can be loaded in
		// and changed on the fly
		
		m_controlMapping[65] = new RotateLeftCommand;
		m_controlMapping[90] = new RotateRightCommand; 
		
		m_controlMapping[83] = new ScaleUpCommand; 
		m_controlMapping[88] = new ScaleDownCommand; 

		m_controlMapping[68] = new TranslateLeftCommand;
		m_controlMapping[67] = new TranslateRightCommand;

	}

	void handleInputs(const std::vector<bool>& keyBuffer)
	{
		for(const auto& mapEntry : m_controlMapping)
		{
			if(keyBuffer[mapEntry.first])
			{
				mapEntry.second->execute(*m_playerCube);
			}
		}

	}
};
