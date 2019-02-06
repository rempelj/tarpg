#pragma once
#if defined(_WIN64) || defined(_WIN32)

#include <Windows.h>

#include "ScreenBuffer.h"

class WindowsScreenBuffer : ScreenBuffer
{
private:
	HANDLE hConsole;
	DWORD dwBytesWritten;

public:
	WindowsScreenBuffer();
	void Refresh();
};

#endif