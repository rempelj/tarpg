#include "GameObject.h"
#include "Transform.h"
#include "Renderer.h"
#include "Game.h"
#include "Scene.h"

GameObject::GameObject() : GameObject::GameObject("New GameObject") {}

GameObject::GameObject(std::string name)
{
	this->name = name;

	transform = AddComponent<Transform>();
	renderer = AddComponent<Renderer>();

	Game::activeScene.AddGameObject(this);
}

GameObject::~GameObject()
{
	for (int i = 0; i < components.size(); i++)
	{
		delete components[i];
	}
}

void GameObject::Update()
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->Update();
	}
}

