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
	m_GameCubes.resize(2); 

	m_engineInterfacePtr = nullptr;
	m_inputHandler = new InputHandler(&m_GameCubes[0]);

	m_playerBackground.addComponent(new RedComponent);
	m_playerBackground.addComponent(new GreenComponent);
	m_playerBackground.addComponent(new BlueComponent); 

	m_GameCubes[0].addComponent(new TransformComponent);
	m_GameCubes[1].addComponent(new TransformComponent);

	// move the cube
	TransformComponent* l_temp = m_GameCubes[0].getComponent<TransformComponent>();
	l_temp->translate(0, 0, -5);

	TransformComponent* l_tempTwo = m_GameCubes[1].getComponent<TransformComponent>();
	l_tempTwo->translate(0, 0, -5);
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
	m_engineInterfacePtr->drawCube(m_GameCubes[0].getComponent<TransformComponent>()->getModelMatrix());

	m_engineInterfacePtr->drawCube(m_GameCubes[1].getComponent<TransformComponent>()->getModelMatrix());
	
}

