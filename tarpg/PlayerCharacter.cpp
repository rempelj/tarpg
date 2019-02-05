#include <Windows.h>

#include "PlayerCharacter.h"
#include "GameObject.h"
#include "Time.h"
#include "Transform.h"
#include "Renderer.h"
#include "Game.h"
#include "Scene.h"


PlayerCharacter::PlayerCharacter(GameObject *go) : GameComponent::GameComponent(go)
{
	std::wstring playerGfx;
	playerGfx += LR"( __  @    /)";
	playerGfx += LR"(|  | .   / )";
	playerGfx += LR"(\__/ .  O  )";
	playerGfx += LR"(    / \    )";
	playerGfx += LR"(    L  L   )";

	gameObject->renderer->SetGraphic(playerGfx, 11, 5);
}

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

	// center the camera on the player
	Game::activeScene.camX = gameObject->transform->x;
	Game::activeScene.camY = gameObject->transform->y;
}