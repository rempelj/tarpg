#include "GameObject.h"
#include "Transform.h"
#include "Renderer.h"
#include "Game.h"
#include "Scene.h"
#include "Debug.h"


GameObject::GameObject() : GameObject::GameObject("New GameObject", '/0') {}
GameObject::GameObject(std::string name) : GameObject::GameObject(name, '/0') {}

GameObject::GameObject(std::string name, char icon)
{
	this->name = name;
	this->icon = icon;

	transform = AddComponent<Transform>();
	renderer = AddComponent<Renderer>();

	scene = &Game::activeScene;
	Game::activeScene.AddGameObject(this);

}

GameObject::~GameObject()
{
	for (int i = 0; i < components.size(); i++)
	{
		delete components[i];
	}

}

void GameObject::PreUpdate()
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->PreUpdate();
	}
}



void GameObject::Update()
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->Update();
	}
}

void GameObject::LateUpdate()
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->LateUpdate();
	}
}

