#pragma once

#include <vector>
#include <string>


class GameComponent;
class Transform;
class Renderer;

class GameObject
{
private:
	std::vector<GameComponent*> components;

public:
	std::string name;
	char icon;

	Transform *transform;
	Renderer *renderer;

	GameObject();
	GameObject(std::string name);
	GameObject(std::string name, char icon);
	~GameObject();

	void Update();

	template<class T>T* AddComponent();
};


template<typename T> T* GameObject::AddComponent()
{
	T *comp = new T(this);

	components.push_back((GameComponent*) comp);

	return comp;
}