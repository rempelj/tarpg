#pragma once

#include <vector>

#include "Map.h"

class GameObject;

class Scene
{
private:
	std::vector<GameObject*> gameObjects;

public:
	float camX;	// The screen centers its view on this world position 
	float camY;
	Map *map;

	~Scene();

	void Update();
	void Render();
	void AddGameObject(GameObject *go);
	std::vector<GameObject*> GetAllGameObjects();

};