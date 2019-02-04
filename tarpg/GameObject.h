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