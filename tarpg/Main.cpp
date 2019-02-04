
#include <iostream>
#include <string>
#include <Windows.h>
#include <chrono>

#include "Main.h"
#include "Screen.h"
#include "PlayerCharacter.h"
#include "GameObject.h"
#include "Transform.h"
#include "GameComponent.h"


using namespace std;

int main()
{
	// vars for storing delta time
	auto tp1 = chrono::system_clock::now();
	auto tp2 = chrono::system_clock::now();

	// Create Screen Buffer
	Screen::screen = new wchar_t[Screen::screenSizeX * Screen::screenSizeY];
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	// Setup game
	Game::activeScene = Scene();

	GameObject player = GameObject("Player");
	player.AddComponent<PlayerCharacter>();
	player.transform->x = 10;
	player.transform->y = 10;

	while (1)
	{
		// Update delta time
		tp2 = chrono::system_clock::now();
		chrono::duration<float> elapsedTime = tp2 - tp1;
		tp1 = tp2;
		Time::deltaTime = elapsedTime.count();

		// Update Game Objects
		Game::activeScene.Update();
		Game::activeScene.Render();

		// Show some info
		swprintf_s(Screen::screen, 40, L"FPS=%3.2f ", 1.0f / Time::deltaTime);

		// Display Frame
		Screen::screen[Screen::screenSizeX * Screen::screenSizeY - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, Screen::screen, Screen::screenSizeX * Screen::screenSizeY, { 0,0 }, &dwBytesWritten);
	}

	return 0;
}