#pragma once

#include <vector>

#include "Transform.h"
#include "Renderer.h"

class GameObject
{
private:
	std::vector<GameComponent*> components;

public:
	Transform *transform;
	Renderer *renderer;

	void Update();

	template<class T>GameComponent* AddComponent();
};