#include "Scene.h"
#include "Screen.h"

#include "GameObject.h"
#include "Renderer.h"

Scene::~Scene()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		delete gameObjects[i];
	}
}

void Scene::Update()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->PreUpdate();
	}

	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Update();
	}

	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->LateUpdate();
	}
}

void Scene::Render()
{
	// clear the screen
	for (int i = 0; i < Screen::screenSizeX * Screen::screenSizeY; i++)
	{
		Screen::screen[i] = ' ';
	}

	// Tell renderers to render themselves
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->renderer->Render();
	}

}

void Scene::AddGameObject(GameObject *gameObject)
{
	gameObjects.push_back(gameObject);
}

std::vector<GameObject*> Scene::GetAllGameObjects()
{
	return gameObjects;
}