#include <Windows.h>

#include "PlayerCharacter.h"
#include "GameObject.h"
#include "Time.h"
#include  "Transform.h"

void PlayerCharacter::Update()
{
	const float speed = 40;

	// Handle Movement
	if (GetAsyncKeyState(VK_UP))
	{
		gameObject->transform->y -= 1 * speed/2 * Time::deltaTime;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		gameObject->transform->y += 1 * speed/2 * Time::deltaTime;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		gameObject->transform->x -= 1 * speed * Time::deltaTime;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		gameObject->transform->x += 1 * speed * Time::deltaTime;
	}
}