#pragma once

#include "IEngineCore.h"
#include "GameObject.h"
#include "TransformComponent.h"
#include "ModelComponent.h"
#include "Model.h"

#include <json/json.h>

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

	std::vector<GameObject> v_GameObjects; 

	// Member Functions

public:

	void m_Update();

	void m_Render(IEngineCore * engineInterface);

	std::vector<GameObject> m_GetGameObjects(); 

	bool m_LoadLevelJson(std::string levelFile);

};