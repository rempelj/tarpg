#pragma once

#include <vector>

#include "GameObject.h"

class Scene
{
private:
	std::vector<GameObject*> gameObjects;

public:
	void Update();
	void Render();
	void AddGameObject(GameObject *go);
};