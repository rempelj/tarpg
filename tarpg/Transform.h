#pragma once

#include "GameComponent.h"

class Transform : public GameComponent
{
public:
	float x;
	float y;

	void Update();
};