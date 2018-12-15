#pragma once

#include "IEngineCore.h"
#include "GameObject.h"
#include "TransformComponent.h"

#include <fstream>
#include <sstream>

class Scene
{
public:

	Scene();

public:

	~Scene();

	// Data Members 

private:

	std::vector<GameObject> m_GameObjects; 

	// Member Functions

public:

	void m_Update();

	void m_Render(IEngineCore * engineInterface);

	std::vector<GameObject> m_GetGameObjects(); 

	void loadLevel(std::string levelFile);

};