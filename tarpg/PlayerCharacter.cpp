#include <Windows.h>

#include "PlayerCharacter.h"
#include "GameObject.h"
#include "Time.h"

void PlayerCharacter::Update()
{
	// Handle Movement
	if (GetAsyncKeyState(VK_UP))
	{
		gameObject->transform->y += 1 * Time::deltaTime;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		gameObject->transform->y -= 1 * Time::deltaTime;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		gameObject->transform->x -= 1 * Time::deltaTime;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		gameObject->transform->x += 1 * Time::deltaTime;
	}
}