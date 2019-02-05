#if defined(_WIN64) || defined(_WIN32)

#include "WindowsScreenBuffer.h"
#include "Screen.h"
#include "Time.h"
#include "Map.h"
#include "Game.h"
#include "Scene.h"
#include "Transform.h"
#include "GameObject.h"

#include <iostream>
#include <Windows.h>

WindowsScreenBuffer::WindowsScreenBuffer()
{
	hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	dwBytesWritten = 0;
}

void WindowsScreenBuffer::Refresh()
{
	// Show some info
	swprintf_s(Screen::screen, Screen::screenSizeX, L"FPS=%3.2f ", 1.0f / Time::deltaTime);


	// Display Map
	int mapWidth = Game::activeScene.map->GetSizeX();
	int mapHeight = Game::activeScene.map->GetSizeY();

	int mapOffsetX = Screen::screenSizeX - mapWidth - 1;
	int mapOffsetY = Screen::screenSizeY - mapHeight - 1;

	// Clear map
	for (int nx = 0; nx < mapWidth; nx++)
	{
		for (int ny = 0; ny < mapHeight; ny++)
		{
			char tile = '.';

			Screen::screen[(ny+ mapOffsetY)*Screen::screenSizeX + (nx+mapOffsetX)] = tile;
		}
	}

	// Display objects
	std::vector<GameObject*> allGos = Game::activeScene.GetAllGameObjects();
	std::vector<GameObject*>::iterator iter;
	for (iter = allGos.begin(); iter != allGos.end(); iter++) 
	{
		char tile = (*iter)->icon;

		Screen::Set(((*iter)->transform->x / Map::TILE_WIDTH) + mapOffsetX, ((*iter)->transform->y / Map::TILE_HEIGHT)+ mapOffsetY, tile);
	}

	// Display camera position
	Screen::Set((Game::activeScene.camX / Map::TILE_WIDTH) + mapOffsetX, (Game::activeScene.camY / Map::TILE_HEIGHT)+ mapOffsetY, '@');


	// Display Frame
	Screen::screen[Screen::screenSizeX * Screen::screenSizeY - 1] = '\0';
	WriteConsoleOutputCharacter(hConsole, Screen::screen, Screen::screenSizeX * Screen::screenSizeY, { 0,0 }, &dwBytesWritten);

}

#endif