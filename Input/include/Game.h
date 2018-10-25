#pragma once
#include "IEngineCore.h"
#include "InputHandler.h"
#include "GameObject.h"


class Game
{
public:
	Game();
	IEngineCore* m_engineInterfacePtr;

	InputHandler* m_inputHandler;

	void update();
	void render();

private:
	GameObject m_playerBackground;
};
