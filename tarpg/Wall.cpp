#include "Collider.h"
#include "Wall.h"
#include "GameObject.h"
#include "Transform.h"
#include "Renderer.h"


Wall::Wall(GameObject *go) : GameComponent::GameComponent(go)
{
	std::wstring gfx;
	gfx += LR"(############)";
	gfx += LR"(############)";
	gfx += LR"(############)";
	gfx += LR"(############)";
	gfx += LR"(############)";
	gfx += LR"(############)";

	gameObject->renderer->SetGraphic(gfx, 12, 6);

	/*
	auto collider = gameObject->AddComponent<Collider>();
	collider->sizeX = 12;
	collider->sizeY = 16;
	*/
}

