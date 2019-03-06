#include "PlayerCharacter.h"
#include "GameObject.h"
#include "Time.h"
#include "Transform.h"
#include "Renderer.h"
#include "Game.h"
#include "Scene.h"
#include "Input.h"
#include "Debug.h"
#include "Collider.h"


PlayerCharacter::PlayerCharacter(GameObject *go) : GameComponent::GameComponent(go)
{
	std::wstring playerGfx;
	playerGfx += LR"( __  @    /)";
	playerGfx += LR"(|  | .   / )";
	playerGfx += LR"(\__/ .  O  )";
	playerGfx += LR"(    / \    )";
	playerGfx += LR"(    L  L   )";

	gameObject->renderer->SetGraphic(playerGfx, 11, 5);

	/*
	auto collider = gameObject->AddComponent<Collider>();
	collider->sizeX = 11;
	collider->sizeY = 5;

	// TODO - remove this (here for debugging)
	collider->AddOnCollisionEnterHandler([&](Collider *collision) 
	{
		Debug::Log("Collided with something");

		std::wstring gfx;
		gfx += LR"(............)";
		gfx += LR"(............)";
		gfx += LR"(............)";
		gfx += LR"(............)";
		gfx += LR"(............)";
		gfx += LR"(............)";

		collision->gameObject->renderer->SetGraphic(gfx, 12, 6);
	});
	*/
}

void PlayerCharacter::Update()
{
	const float speed = 40;

	// Handle Movement
	if (Input::GetKey(Input::KeyCode::UpArrow))
	{
		gameObject->transform->y -= 1 * speed/2 * Time::deltaTime;
	}

	if (Input::GetKey(Input::KeyCode::DownArrow))
	{
		gameObject->transform->y += 1 * speed/2 * Time::deltaTime;
	}

	if (Input::GetKey(Input::KeyCode::LeftArrow))
	{
		gameObject->transform->x -= 1 * speed * Time::deltaTime;
	}

	if (Input::GetKey(Input::KeyCode::RightArrow))
	{
		gameObject->transform->x += 1 * speed * Time::deltaTime;
	}

	// center the camera on the player
	Game::activeScene.camX = gameObject->transform->x;
	Game::activeScene.camY = gameObject->transform->y;
}