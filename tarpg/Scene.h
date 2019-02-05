#pragma once

#include <vector>

#include "Map.h"

class GameObject;

class Scene
{
private:
	std::vector<GameObject*> gameObjects;

public:
	~Scene();

	void Update();
	void Render();
	void AddGameObject(GameObject *go);

};