#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::m_Update()
{
}

void Scene::m_Render(IEngineCore * engineInterface)
{
	// draw the cube

	if (v_GameObjects.size() > 0)
	{
		for (unsigned int i = 0; i < v_GameObjects.size(); i++)
		{
			engineInterface->drawModel(v_GameObjects[i].getComponent<ModelComponent>()->m_ThisModel, *&v_GameObjects[i].getComponent<TransformComponent>()->getModelMatrix());
		}
	}
}

std::vector<GameObject> Scene::m_GetGameObjects()
{
	return v_GameObjects;
}

bool Scene::m_LoadLevelJson(std::string levelFile)
{
	v_GameObjects.clear(); 

	Model * l_TestModel = new Model("assets/models/Sphere.obj");

	// Initalize variables. 
	std::fstream l_JasonData;
	
	Json::Value l_Root;
	Json::Reader l_Reader;
	
	// Open file.
	l_JasonData.open(levelFile.c_str()); 

	// Check for errors. 
	if (!l_Reader.parse(l_JasonData, l_Root))
	{
		std::cout << "Failed to parse data from: " << levelFile << l_Reader.getFormattedErrorMessages(); 

		return false; 
	}

	const Json::Value l_GameObjects = l_Root["GameObjects"];

	v_GameObjects.resize(l_GameObjects.size()); 

	for (unsigned int i = 0; i < l_GameObjects.size(); i++)
	{
		std::cout << l_GameObjects[i]["name"].asString() << " Loaded" << std::endl;

		float x, y, z; 

		const Json::Value l_PosNode = l_GameObjects[i]["position"];

		x = l_PosNode[0].asFloat();
		y = l_PosNode[1].asFloat();
		z = l_PosNode[2].asFloat();

		glm::vec3 pos(x, y, z); 

		v_GameObjects[i].addComponent(new TransformComponent(pos));

		v_GameObjects[i].addComponent(new ModelComponent(l_TestModel));
		
	}

	return true;
}


