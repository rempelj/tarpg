#pragma once

#include <vector>
#include <string>


#include "Transform.h"
#include "Renderer.h"

class GameObject
{
private:
	std::string name;
	std::vector<GameComponent*> components;

public:
	Transform *transform;
	Renderer *renderer;

	GameObject();
	GameObject(std::string name);

	void Update();

	template<class T>T* AddComponent();
};