#pragma once

#include <vector>
#include <string>


class GameComponent;
class Transform;
class Renderer;

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


template<typename T> T* GameObject::AddComponent()
{
	GameComponent *comp = (GameComponent*) new T();

	comp->gameObject = this;
	components.push_back(comp);
	return (T*)comp;
}