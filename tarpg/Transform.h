#pragma once

#include "GameComponent.h"

class Transform : public GameComponent
{
public:
	float x;
	float y;

	Transform(GameObject* go);
	void Update();
};