#pragma once

#include "IEngineCore.h"
#include "InputHandler.h"
#include "GameObject.h"
#include "Camera.h"
#include "Scene.h"

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

	/*! \var This will be the main game camera for the game. */
	Camera m_camera;

	Scene* m_CurrentScene; 

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

};
