
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
}

