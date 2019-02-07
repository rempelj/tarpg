#include "Debug.h"

#include <Windows.h>

namespace Debug
{
	void Log(std::string message)
	{
		std::wstring stemp = std::wstring(message.begin(), message.end());
		LPCWSTR sw = stemp.c_str();

		OutputDebugString(sw);
		OutputDebugString(L"\n");
	}
}