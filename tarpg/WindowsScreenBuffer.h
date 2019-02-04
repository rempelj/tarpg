#pragma once
#if defined(_WIN64) || defined(_WIN32)

#include "ScreenBuffer.h"

#include <Windows.h>

class WindowsScreenBuffer : public ScreenBuffer
{
private:
	HANDLE hConsole;
	DWORD dwBytesWritten;

public:
	WindowsScreenBuffer();
	void Refresh();
};

#endif