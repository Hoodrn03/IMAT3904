#include "Game.h"

Game::Game()
{
	m_engineInterfacePtr = nullptr;
	m_inputHandler = new InputHandler(&m_playerBackground);
}

void Game::update()
{
	// perform all the logic for your game world
}

void Game::render()
{
	// e.g. pass object details to the engine to render the next frame
}