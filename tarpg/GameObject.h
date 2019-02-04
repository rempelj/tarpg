#pragma once

#include <vector>
#include "Transform.h"

class GameObject
{
private:
	std::vector<GameComponent*> components;

public:
	Transform *transform;
	void Update();
};