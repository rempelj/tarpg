#include "Scene.h"
#include "Screen.h"

void Scene::Update()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Update();
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