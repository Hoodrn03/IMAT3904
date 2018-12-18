#pragma once

#include "Component.h"
#include "Model.h"

class ModelComponent : public Component
{
public: 

	ModelComponent(Model *targetModel)
	{
		m_ThisModel = targetModel;
	}
	
public: 

	~ModelComponent()
	{

	}

	// Data Members

public:

	Model * m_ThisModel; 

	// Member Functions

public:

	void OnUpdate(float dt) override
	{

	}

	void OnMessage(const std::string m) override
	{

	}

};
