#include "Scene.h"
#include "Main.h"

void Scene::Update()
{
	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i].Update();
	}


}

void Scene::Render()
{
	// clear the screen
	for (int i = 0; i < Screen::screenSizeX * Screen::screenSizeY; i++)
	{
		Screen::screen[i] = ' ';
	}



}