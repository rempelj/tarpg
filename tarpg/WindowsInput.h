#pragma once
#if defined(_WIN64) || defined(_WIN32)

#include "Point.h"

namespace Input
{
	enum KeyCode;

	extern bool GetKey(KeyCode keyCode);
	extern Point GetMousePosition();
}

#endif