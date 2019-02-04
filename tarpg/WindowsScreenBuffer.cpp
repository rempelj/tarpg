#if defined(_WIN64) || defined(_WIN32)

#include "WindowsScreenBuffer.h"
#include "Screen.h"
#include "Time.h"

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
	swprintf_s(Screen::screen, 40, L"FPS=%3.2f ", 1.0f / Time::deltaTime);

	// Display Frame
	Screen::screen[Screen::screenSizeX * Screen::screenSizeY - 1] = '\0';
	WriteConsoleOutputCharacter(hConsole, Screen::screen, Screen::screenSizeX * Screen::screenSizeY, { 0,0 }, &dwBytesWritten);

}

#endif