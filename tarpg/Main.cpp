
#include <iostream>
#include <string>
#include <Windows.h>
#include <chrono>

#include "Main.h"

using namespace std;


namespace Screen
{
	wchar_t *screen;
	int screenSizeX = 120;			// Console Screen Size X (columns)
	int screenSizeY = 40;			// Console Screen Size Y (rows)
}


namespace Time
{
	float deltaTime = 0;

}

namespace Game
{
	Scene activeScene;
}



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

	// Setup 
	Game::activeScene = Scene();

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