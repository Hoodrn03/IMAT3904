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
			engineInterface->drawCube(v_GameObjects[i].getComponent<TransformComponent>()->getModelMatrix());
		}
	}
}

std::vector<GameObject> Scene::m_GetGameObjects()
{
	return v_GameObjects;
}

void Scene::m_loadLevel(std::string levelFile)
{
	v_GameObjects.clear(); 

	int l_iNumberOfElementsToRead;

	std::stringstream l_ss;
	std::string l_s;

	std::ifstream l_MyInputFile;

	// Open the .txt file. 

	l_MyInputFile.open(levelFile, std::ios_base::in);

	if (l_MyInputFile.is_open())
	{
		std::getline(l_MyInputFile, l_s);

		std::cout << l_s << std::endl;

		l_ss.str(l_s);

		// Find the number of elements. 

		while (!l_ss.eof())
		{
			std::string l_temp;

			l_ss >> l_temp;

			if (std::stringstream(l_temp) >> l_iNumberOfElementsToRead)
			{
				break;
			}
		}

		// Set the size of the vector to be the number of elements in the .txt file.

		v_GameObjects.resize(l_iNumberOfElementsToRead);

		float w, x, y, z;

		for (int i = 0; i < l_iNumberOfElementsToRead; i++)
		{
			// Discard First line. 

			std::getline(l_MyInputFile, l_s);

			l_ss.clear();

			std::cout << l_s << std::endl;

			// Get Position values. 

			std::getline(l_MyInputFile, l_s);

			l_ss.clear();

			l_ss.str(l_s);

			l_ss >> x >> y >> z;

			glm::vec3 pos(x, y, z);

			// Get Orientation values 

			std::getline(l_MyInputFile, l_s);

			l_ss.clear();

			l_ss.str(l_s);

			l_ss >> w >> x >> y >> z;

			glm::quat orient(w, x, y, z);

			// Get Scale values. 

			std::getline(l_MyInputFile, l_s);

			l_ss.clear();

			l_ss.str(l_s);

			l_ss >> x >> y >> z;

			glm::vec3 scale(x, y, z);

			// Create Cube 

			v_GameObjects[i].addComponent(new TransformComponent(pos, orient, scale));

		}

	}

}

bool Scene::m_LoadLevelJson(std::string levelFile)
{
	v_GameObjects.clear(); 

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
		
	}

	return true;
}


