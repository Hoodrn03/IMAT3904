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

	if (m_GameObjects.size() > 0)
	{
		for (unsigned int i = 0; i < m_GameObjects.size(); i++)
		{
			engineInterface->drawCube(m_GameObjects[i].getComponent<TransformComponent>()->getModelMatrix());
		}
	}
}

std::vector<GameObject> Scene::m_GetGameObjects()
{
	return m_GameObjects;
}

void Scene::loadLevel(std::string levelFile)
{
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

		m_GameObjects.resize(l_iNumberOfElementsToRead);

		float w, x, y, z;

		for (unsigned int i = 0; i < l_iNumberOfElementsToRead; i++)
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

			m_GameObjects[i].addComponent(new TransformComponent(pos, orient, scale));

		}

	}

}
