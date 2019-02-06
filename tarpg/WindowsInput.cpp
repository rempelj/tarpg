#if defined(_WIN64) || defined(_WIN32)

#include "Input.h"
#include "WindowsInput.h"
#include "Point.h"

#include <Windows.h>

namespace Input
{
	namespace   // anonymous namespace for private functions
	{
		int ToVK(KeyCode keyCode)
		{
			switch (keyCode)
			{
			case KeyCode::UpArrow:
				return VK_UP;
			case KeyCode::DownArrow:
				return VK_DOWN;
			case KeyCode::LeftArrow:
				return VK_LEFT;
			case KeyCode::RightArrow:
				return VK_RIGHT;
			case KeyCode::Alpha1:
				return 0x31;
			case KeyCode::Alpha2:
				return 0x32;
			case KeyCode::Alpha3:
				return 0x33;
			case KeyCode::Alpha4:
				return 0x34;
			case KeyCode::Alpha5:
				return 0x35;
			case KeyCode::Alpha6:
				return 0x36;
			case KeyCode::Alpha7:
				return 0x37;
			case KeyCode::Alpha8:
				return 0x38;
			case KeyCode::Alpha9:
				return 0x39;
			case KeyCode::Alpha0:
				return 0x30;
			case KeyCode::Mouse0:
				return VK_LBUTTON;
			case KeyCode::Mouse1:
				return VK_RBUTTON;
			case KeyCode::Mouse2:
				return VK_MBUTTON;
			default:
				return 0;
			}
		}
	}

	bool GetKey(KeyCode keyCode)
	{
		return GetAsyncKeyState(ToVK(keyCode)) != 0;
	}

	Point GetMousePosition()
	{
		auto result = Point(0, 0);

		POINT winp;
		if (GetCursorPos(&winp)) {
			result.x = winp.x;
			result.y = winp.y;
		}

		return result;
	}

}

#endif