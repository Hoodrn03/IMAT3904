#pragma once

#include "IEngineCore.h"
#include "InputHandler.h"
#include "GameObject.h"
#include "Camera.h"

class Game
{

public:

	//-----------------------------------------------------------//
	/*! Constructor 
	*
	*/
	Game();
	
	//-----------------------------------------------------------//
	/*! Deconstructor
	*
	*/
	~Game();

	// Data Members 

private:

	/*! \var The background for the game. */
	GameObject m_playerBackground;

	/*! \var The initial Cube dissplayed within the game world. */
	GameObject m_playerCube;

	/*! \var This will be the main game camera for the game. */
	Camera m_camera;

public:

	IEngineCore* m_engineInterfacePtr;

	InputHandler* m_inputHandler;

	// Member Functons 

public:

	//-----------------------------------------------------------//
	/*! Update : Called once every frame. 
	*
	*/
	void update();

	//-----------------------------------------------------------//
	/*! Render : Will draw all items at the end of the frame. 
	*
	*/
	void render();

	void loadLevel(std::string levelFile);

};
