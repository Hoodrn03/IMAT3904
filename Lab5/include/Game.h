#pragma once
#include "IEngineCore.h"
#include "InputHandler.h"
#include "GameObject.h"
#include "Camera.h"

class Game
{
public:
	Game();
	IEngineCore* m_engineInterfacePtr;

	InputHandler* m_inputHandler;

	void update();
	void render();

	void loadLevel(std::string levelFile);

private:
	GameObject m_playerBackground;
	GameObject m_playerCube;

	Camera m_camera;
};
