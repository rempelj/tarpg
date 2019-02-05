#include <string>
#include <assert.h>

#include "Renderer.h"
#include "Screen.h"
#include "GameObject.h"
#include "Transform.h"
#include "Game.h"
#include "Scene.h"

Renderer::Renderer(GameObject *go) : GameComponent::GameComponent(go)
{
	this->graphic = L"?";
	this->graphicSizeX = 0;
	this->graphicSizeY = 0;
}

void Renderer::Update()
{
}

void Renderer::Render()
{
	int x = 0;
	int y = 0;

	while (y <= graphicSizeY - 1)
	{
		int index = x + graphicSizeX*y;
		char currentChar = graphic[index];
		
		if (currentChar != ' ')
		{
			float worldX = gameObject->transform->x + x;
			float worldY = gameObject->transform->y + y;

			Screen::Set(
				(int)std::round(worldX - Game::activeScene.camX / 2),
				(int)std::round(worldY - Game::activeScene.camY / 2 - graphicSizeY + 1),	// render bottom-left char at my position
				currentChar
			);
		}

		// next char
		x++;
		if (x >= graphicSizeX)
		{
			x = 0;
			y++;
		}
	}
}

void Renderer::SetGraphic(std::wstring graphic, int sizeX, int sizeY)
{
	assert(("Character count does not match sizeX and sizeY", graphic.size() == sizeX * sizeY));

	this->graphic = graphic;
	this->graphicSizeX = sizeX;
	this->graphicSizeY = sizeY;
}