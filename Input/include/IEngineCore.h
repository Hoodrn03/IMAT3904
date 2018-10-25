#pragma once
#include <string>
#include <iostream>

class Game;

class IEngineCore
{
public:

	virtual ~IEngineCore() {}

	virtual bool initWindow(int width, int height, std::string windowName) = 0;
	virtual bool runEngine(Game& game) = 0;

	virtual void renderColouredBackground(float r, float g, float b) = 0; 

};
