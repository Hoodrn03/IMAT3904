#include "Game.h"
#include "TransformComponent.h"
#include "ColourComponent.h"
#include <fstream>
#include <sstream>

//-----------------------------------------------------------//
/*! Constructor
*
*/
Game::Game()
{
	m_engineInterfacePtr = nullptr;

	m_playerBackground.addComponent(new RedComponent);
	m_playerBackground.addComponent(new GreenComponent);
	m_playerBackground.addComponent(new BlueComponent); 

	loadLevel("assets/levels/myCubeLevel.txt");

	if (m_GameCubes.size() > 0)
	{
		m_inputHandler = new InputHandler(&m_GameCubes[0]);
	}
}

//-----------------------------------------------------------//
/*! Deconstructor
*
*/
Game::~Game()
{
}

//-----------------------------------------------------------//
/*! Update : Called once every frame.
*
*/
void Game::update()
{

}

//-----------------------------------------------------------//
/*! Render : Will draw all items at the end of the frame.
*
*/
void Game::render()
{
	float redValue = 0, greenValue = 0, blueValue = 0;

	if (m_playerBackground.getComponent<RedComponent>())
	{
		redValue = m_playerBackground.getComponent<RedComponent>()->m_colourValue;
	}
	
	if (m_playerBackground.getComponent<GreenComponent>())
	{
		greenValue = m_playerBackground.getComponent<GreenComponent>()->m_colourValue;
	}
	if (m_playerBackground.getComponent<BlueComponent>())
	{
		blueValue = m_playerBackground.getComponent<BlueComponent>()->m_colourValue;
	}

	// e.g. pass object details to the engine to render the next frame
	m_engineInterfacePtr->renderColouredBackground(redValue, greenValue, blueValue);

	// update the camera (probably don't need to do this each frame)
	m_engineInterfacePtr->setCamera(&m_camera);

	// draw the cube
	if (m_GameCubes.size() > 0)
	{
		for (unsigned int i = 0; i < m_GameCubes.size(); i++)
		{
			m_engineInterfacePtr->drawCube(m_GameCubes[i].getComponent<TransformComponent>()->getModelMatrix());
		}
	}
	
}

void Game::loadLevel(std::string levelFile)
{

	int l_iNumberOfElementsToRead; 
	
	std::stringstream l_ss;
	std::string l_s;

	std::ifstream l_MyInputFile; 

	l_MyInputFile.open(levelFile, std::ios_base::in);

	if (l_MyInputFile.is_open())
	{
		std::getline(l_MyInputFile, l_s);

		std::cout << l_s << std::endl;

		l_ss.str(l_s); 

		while (!l_ss.eof())
		{
			std::string l_temp;

			l_ss >> l_temp;

			if (std::stringstream(l_temp) >> l_iNumberOfElementsToRead)
			{
				break;
			}
		}

		m_GameCubes.resize(l_iNumberOfElementsToRead); 

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

			m_GameCubes[i].addComponent(new TransformComponent(pos, orient, scale));

		}

	}

}

