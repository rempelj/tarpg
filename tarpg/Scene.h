#pragma once

#include <vector>

class GameObject;

class Scene
{
private:
	std::vector<GameObject*> gameObjects;

public:
	void Update();
	void Render();
	void AddGameObject(GameObject *go);
};