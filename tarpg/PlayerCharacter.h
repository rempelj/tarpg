#pragma once

#include "GameComponent.h"

class PlayerCharacter : GameComponent
{
public:
	PlayerCharacter(GameObject* go);
	void Update();
};