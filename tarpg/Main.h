#pragma once

#include "Scene.h"

namespace Screen
{
	extern wchar_t *screen;
	extern int screenSizeX;			// Console Screen Size X (columns)
	extern int screenSizeY;			// Console Screen Size Y (rows)
}


namespace Time
{
	extern float deltaTime;

}

namespace Game
{
	extern Scene activeScene;
}

