#include <string>
#include <assert.h>

#include "GameObject.h"
#include "Map.h"
#include "PlayerCharacter.h"
#include "Transform.h"
#include "Wall.h"
#include "Game.h"
#include "Scene.h"


void Map::SetLayout(std::wstring layout, int sizeX, int sizeY)
{
	assert(("Character count does not match sizeX and sizeY", layout.size() == sizeX * sizeY));

	this->layout = layout;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
}

void Map::ApplyToActiveScene()
{
	Game::activeScene.map = this;

	int x = 0;
	int y = 0;

	for (int i = 0; i < layout.size(); i++)
	{
		char tile = layout[i];

		if (tile == '@')
		{
			GameObject *player = new GameObject("Player", '@');
			player->AddComponent<PlayerCharacter>();
			player->transform->x = x * Map::TILE_WIDTH;
			player->transform->y = y * Map::TILE_HEIGHT;
		}
		else if (tile == '#')
		{
			GameObject *wall = new GameObject("Wall", '#');
			wall->AddComponent<Wall>();
			wall->transform->x = x * Map::TILE_WIDTH;
			wall->transform->y = y * Map::TILE_HEIGHT;
		}

		// next tile position 
		x++;
		if (x >= sizeX)
		{
			x = 0;
			y++;
		}
	}
	
}