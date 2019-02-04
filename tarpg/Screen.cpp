#include <string>
#include "Screen.h"

namespace Screen
{
	wchar_t *screen;
	int screenSizeX = 120;			// Console Screen Size X (columns)
	int screenSizeY = 40;			// Console Screen Size Y (rows)

	char Get(int x, int y)
	{
		int index = x + screenSizeX*y;

		if (index < 0 || index >= screenSizeX*screenSizeY)
		{
			return ' ';
		}

		return screen[y + screenSizeX*x];
	}

	void Set(int x, int y, char value)
	{
		int index = x + screenSizeX*y;

		if (index < 0 || index >= screenSizeX*screenSizeY)
		{
			return;
		}

		screen[index] = value;
	}
}
