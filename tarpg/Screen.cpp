#include "Screen.h"

namespace Screen
{
	wchar_t *screen;
	int screenSizeX = 120;			// Console Screen Size X (columns)
	int screenSizeY = 40;			// Console Screen Size Y (rows)

	int Get(int x, int y)
	{
		return screen[y + screenSizeX*x];
	}

	void Set(int x, int y, char value)
	{
		screen[y + screenSizeX*x] = value;
	}
}
