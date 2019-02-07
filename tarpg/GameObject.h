#pragma once

#include <vector>
#include <string>


class GameComponent;
class Transform;
class Renderer;
class Scene;

class GameObject
{
private:
	std::vector<GameComponent*> components;

public:
	std::string name;
	char icon;

	Scene *scene;

	Transform *transform;
	Renderer *renderer;

	GameObject();
	GameObject(std::string name);
	GameObject(std::string name, char icon);
	~GameObject();

	void PreUpdate();
	void Update();
	void LateUpdate();

	template<class T>T* AddComponent();
};


template<typename T> T* GameObject::AddComponent()
{
	T *comp = new T(this);

	components.push_back((GameComponent*) comp);

	return comp;
}